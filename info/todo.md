# TODO (perso, ne pas rendre)

## Workflow :

| Etapes | Tâches |
|------|--------|
| 1 | Parsing + checks rectangulaire + chars + compteurs |
| 2 | Murs fermés + flood fill + maps tests |
| 3 | MLX init + textures + render statique |
| 4 | Moves + compteur + exit + clean exit (ESC + croix) |
| 5 | Polish + leaks + norm + README |


# liste détaillée :

## 0) Setup du projet

**Créer l’arborescence :**

- src/

- includes/

- maps/

- textures/ (fichiers .xpm)

- libft/

- Makefile (rules demandées + pas de relink)

**Décider une constante :**

#define TILE 64 (ou 32)

## 1) Architecture (avant de coder beaucoup)

**Faire structs principales (même si je les ajustes après).**

### c'est quoi une "struct"?

Une `struct` =
- un type personnalisé
- qui permet de regrouper plusieurs variables différentes dans une seule

C’est comme créer son propre “objet”, **utile pour eviter de declarer 10'000 variables dans les fonctions.**

**_Idée simple :_**


- `t_game` : tout ce qui vit pendant l’exécution

	- `void *mlx; void *win;`
	- images (mur/sol/joueur/C/E)
	- `char **map;`
	- tailles `width/height`
	- position joueur `px/py`
	- `collectibles_total`, `collectibles_left`
	- `moves`

- `t_img` (optionnel) : `void *ptr; int w; int h;`

**But : quand je dit “data” dans les hooks, je passe t_game *.**

## 2) Parsing du .ber (à faire en premier)
Objectif : obtenir un char **map clean.

**Étapes**
1. Vérifier l’argument :
	- exactement 1 argument
	- extension `.ber`

2. Lire le fichier :
	- open + read (souvent tu lis ligne par ligne avec GNL)
	- stocker les lignes dans une structure temporaire (liste) puis convertir en `char **`

3. Nettoyer :
	- enlever le `\n` final sur chaque ligne
	- refuser lignes vides / map vide

*À ce stade : juste print la map pour vérifier.*

3) Validations “map rules” (sujet obligatoire)

Tu fais les checks avant MLX.

Checks indispensables (dans cet ordre, ça aide)

Rectangulaire

toutes les lignes même longueur

Caractères autorisés

seulement 01CEP

Comptage

exactement 1 P

exactement 1 E

au moins 1 C

Fermée par des murs

première ligne full 1

dernière ligne full 1

première/dernière colonne de chaque ligne = 1

➡️ si erreur : Error\n + message + free + exit.

4) Validation du chemin (flood fill)

C’est LE truc que beaucoup ratent.

But

Depuis P, vérifier que :

tous les C sont atteignables

E est atteignable

Méthode

faire une copie de map

lancer flood fill/DFS depuis la position de P

marquer visité (ex: V)

à la fin, vérifier qu’il ne reste plus de C non visités et que E a été touché.

⚠️ Important : flood fill ne doit pas modifier la vraie map du jeu.

5) MiniLibX : init + chargement textures

Une fois que ta map est 100% valide, tu passes à l’affichage.

Étapes MLX

mlx_init

calcul taille fenêtre :

win_w = map_w * TILE

win_h = map_h * TILE

mlx_new_window

charger tes images XPM :

mlx_xpm_file_to_image pour chaque sprite

check NULL (sinon clean exit)

6) Rendu : dessiner la map

Fais une fonction propre genre render(t_game *g) :

Boucle sur y/x :

1 => wall

0 => floor

C => floor puis collectible (ou collectible direct)

E => exit

P => floor puis player

✅ conseil : dessine d’abord le sol partout, puis le reste.

7) Inputs : déplacements + règles

Hook clavier :

si touche = move

calculer prochaine case (nx, ny)

si mur 1 => rien

sinon :

si C => décrémenter collectibles_left

si E :

si collectibles_left == 0 => win + exit propre

sinon => bloquer (ou laisser mais généralement on bloque la victoire)

déplacer P dans la map (update char **)

moves++ + ft_printf("%d\n", moves);

render(g)

8) Hooks “fermeture propre”

ESC : clean exit

croix fenêtre (event 17) : clean exit

Ta clean_exit() doit :

destroy images (si non NULL)

destroy window

destroy display (selon version Linux)

free map

free struct si besoin

exit(0) (ou exit(1) si erreur)

9) Tests (pendant tout le projet)

Fais un dossier maps/bad/ et maps/good/.

Bad maps à tester :

non rectangulaire

trou dans les murs

2 P / 2 E / 0 C

caractère interdit

pas de chemin vers C

pas de chemin vers E

.ber vide / ligne vide

10) Bonus (quand mandatory est béton)

moves à l’écran : mlx_string_put

animation : mlx_loop_hook + changer sprite

ennemi patrouille : update logique + redraw (souvent loop_hook)