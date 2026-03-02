# SO_LONG

## Sommaire

1. [Introduction](#introduction)
	1. [But](#but)
	2. [MAP](#map)
		- [Conditions obligatoires](#conditions-obligatoires)
	3. [Contrôles](#contrôles)
	4. [Partie graphique](#partie-graphique)
2. [Checklist (TODO)](#checklist-todo)
	1. [Parsing](#1parsing)
	2. [Vérification du chemin](#2-vérification-du-chemin)
		- [Algo "Flood Fill"](#algo-flood-fill)
	3. [Initialisation graphique](#3-initialisation-graphique)
	4. [Affichage de la map (Rendering)](#4-affichage-de-la-map-rendering)
	5. [Gestion des déplacements](#5-gestion-des-déplacements)
	6. [Clean exit](#6-clean-exit)
		- [Résumé étapes](#résumé-étapes)
3. [MINILIBX](#minilibx)
	1. [Qu'est-ce que la MiniLibX?](#quest-ce-que-la-minilibx)
		- [Pourquoi on l'utilise dans so_long ?](#pourquoi-on-lutilise-dans-so_long-)
	2. [Logique de fonctionnement](#logique-de-fonctionnement)
		- [Application concrète dans so_long](#application-concrète-dans-so_long)
	3. [Points importants à retenir](#points-importants-à-retenir)
	4. [Résumé MiniLibX](#résumé-minilibx)
4. [Fonctions MLX utilisées](#fonctions-mlx-utilisées)
	1. [Initialisation graphique](#1-initialisation-graphique)
		- [mlx_init()](#mlx_init)
	2. [Création de la fenêtre](#2-création-de-la-fenêtre)
		- [mlx_new_window()](#mlx_new_windowmlx-width-height-title)
	3. [Chargement des sprites](#3-chargement-des-sprites)
		- [mlx_xpm_file_to_image()](#mlx_xpm_file_to_image)
	4. [Affichage d'une image](#4-affichage-dune-image)
		- [mlx_put_image_to_window()](#mlx_put_image_to_window)
	5. [Gestion du clavier](#5-gestion-du-clavier)
		- [mlx_key_hook()](#mlx_key_hook)
	6. [Fermer avec la croix](#6-fermer-avec-la-croix)
		- [mlx_hook()](#mlx_hookwin-17-0-close_game-data)
	7. [Lancer la boucle graphique](#7-lancer-la-boucle-graphique)
		- [mlx_loop()](#mlx_loop)
	8. [Clean exit](#8-clean-exit-important)

# Introduction
## But

Le but est de créer un petit jeu 2D en utilisant la **MiniLibX**.

Le joueur doit :
1. récupérer tous les collectibles (`C`)
2. puis atteindre la sortie (`E`)
3. en faisant le **moins de mouvements possible**

Le jeu se joue sur une **map lue depuis un fichier `.ber`**.


## MAP

La map est composée uniquement de ces caractères :

| Caractère | Rôle |
|-----------|------|
| `1` | mur |
| `0` | sol |
| `C` | collectible |
| `E` | sortie |
| `P` | position du joueur |

### Conditions obligatoires

Une map valide doit :

- être **rectangulaire**
- être **fermée par des murs**
- contenir :
  - 1 seul `P`
  - 1 seul `E`
  - au moins 1 `C`
- contenir **uniquement les caractères autorisés**
- avoir un **chemin valide** :
  - le joueur peut atteindre tous les `C`
  - puis la sortie

Sinon → `Error\n` + message explicite.

## Contrôles

Touches obligatoires :

| Touche | Action |
|--------|--------|
| W / Z | haut |
| A / Q | gauche |
| S | bas |
| D | droite |
| ESC | quitter proprement |

À chaque mouvement :
-> afficher le **nombre de moves dans le terminal**

## Partie graphique

Ton programme doit :

- ouvrir une fenêtre
- afficher la map avec des images
- gérer la fermeture propre :
  - ESC
  - clic sur la croix

Le jeu **n’a pas besoin d’être en temps réel**  
-> il se met à jour uniquement quand le joueur bouge.

# Checklist (TODO)

## 1.Parsing

Lire le fichier `.ber` :

- `open` / `read`
- stocker dans un `char **`
- vérifier toutes les règles de validité (**map valide?**)

## 2. Vérification du chemin
But :  
Vérifier que le joueur peut atteindre :

- tous les collectibles
- la sortie

Fait une copie de la map (pour ne pas la modifier) et “remplit” de '.' depuis `P`.

### Algo "Flood Fill"

**Flood fill** = “remplir une zone” à partir d’un point de départ, en se propageant dans les 4 directions (haut/bas/gauche/droite), sans traverser les murs.

Dans so_long, on l’utilise pour répondre à la question :

- *Depuis la position du joueur P, est-ce que je peux atteindre tous les C et la sortie E ?*

La fonction reçoit :

- y, x : une case actuelle
- copy : la map copiée
- game->map_width/map_height : limites

<pre>
void	flood_fill(t_game *game, char **copy, int y, int x)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (copy[y][x] == '1')
		return ;
	if (copy[y][x] == '.')
		return ;
	else
	{
		copy[y][x] = '.';
		flood_fill(game, copy, y + 1, x); // En bas
		flood_fill(game, copy, y - 1, x); // En haut
		flood_fill(game, copy, y, x + 1); // A droite
		flood_fill(game, copy, y, x - 1); // A gauche
	}
}
</pre>

**C'est du `DFS` (Depth-First). Il va au bout dans la première direction avant d'essayer les autres. Il ne passe à "HAUT" que quand "BAS" est entièrement épuisé, il plonge toujours vers le bas en premier, et ne "remonte" vers une direction précédente que quand le bas est un cul-de-sac (mur ou case déjà visitée).**


| Condition | Raison |
|-----------|--------|
| `x < 0` ou hors limites | On sort de la map |
| `copy[y][x] == '1'` | C'est un mur |
| `copy[y][x] == '.'` | Déjà visité → évite les boucles infinies |


## 3. Initialisation graphique

Avec la MLX :

- `mlx_init`
- `mlx_new_window`
- charger les textures (`mlx_xpm_file_to_image`)

## 4. Affichage de la map (Rendering)

Pour chaque case :

- mur → image mur
- sol → image sol
- C → image collectible
- E → image exit
- P → image player

Position en pixels :

<pre>
x = colonne * TILE_SIZE;
y = ligne   * TILE_SIZE;
</pre>

## 5. Gestion des déplacements

Quand une touche est pressée :

1. vérifier si le prochain tile ≠ mur
2. déplacer le joueur
3. si C → le ramasser
4. si E + tous les C ramassés -> victoire 
5. afficher le compteur de move

## 6. Clean exit
À la fermeture :

1. détruire les images
2. détruire la fenêtre
3. free la map
4. exit()

### Résumé étapes

- ✅ parsing complet
- ✅ map valide
- ✅ flood fill OK
- ✅ affichage statique de la map
- ✅ mouvements du joueur
- ✅ collectibles
- ✅ exit
- ✅ clean exit

---

# MINILIBX

## Qu'est-ce que la MiniLibX?

La MiniLibX est une petite bibliothèque graphique fournie par 42.  
Elle permet d’interagir avec le système graphique pour :

- ouvrir une fenêtre
- afficher des images
- gérer les événements clavier et souris
- créer une boucle de rendu

C’est une abstraction très simple au-dessus des systèmes graphiques :
- **X11 sous Linux**
- **AppKit/OpenGL sous macOS**

Elle est volontairement minimaliste pour nous obliger à comprendre la logique d’un moteur graphique.

### Pourquoi on l’utilise dans so_long ?

Dans so_long, la MiniLibX sert à :

- afficher la map dans une fenêtre
- afficher les différents éléments du jeu avec des textures :
  - murs
  - sol
  - joueur
  - collectibles
  - sortie
- détecter les touches du clavier pour déplacer le joueur
- fermer le programme proprement

---

## Logique de fonctionnement

### Application concrète dans so_long
À chaque déplacement du joueur :

- on met à jour la map en mémoire
- on redessine les images dans la fenêtre

La MiniLibX ne met pas à jour l’écran automatiquement.
C’est au programme de redessiner l’affichage.
Le jeu n’est pas en temps réel :  
- l’écran est mis à jour uniquement lors d’un déplacement.

## Points importants à retenir

> **À retenir impérativement**
> 
> - Toutes les positions sont en pixels
> - La MLX ne gère pas la logique du jeu → seulement l'affichage
> - `mlx_loop` ne se termine jamais sans un exit
> - Il faut détruire :
> 	- les images
> 	- la fenêtre pour quitter proprement
---
### Résumé MiniLibX

La MiniLibX est une bibliothèque graphique minimaliste qui permet de :
- créer une fenêtre
- afficher des images
- gérer les entrées utilisateur
- faire tourner une boucle événementielle

Elle sert de lien entre la logique du jeu et son affichage à l’écran.

---
# Fonctions MLX utilisées
## 1. Initialisation graphique

### mlx_init()
[`mlx_init`](./minilibx-linux/mlx_init.c)

**Rôle :**
Initialise la connexion avec le serveur graphique (X11).

**Ce que fait la fonction en interne :**
- ouvre la connexion avec le display (`XOpenDisplay`)
- récupère l’écran, la profondeur de couleur, etc.
- stocke tout dans une structure mlx

**Pourquoi c’est indispensable :**
Toutes les autres fonctions MLX ont besoin de ce pointeur.

C’est le point de départ du programme graphique

## 2. Création de la fenêtre

### mlx_new_window(mlx, width, height, title)
[`mlx_new_window.c`](./minilibx-linux/mlx_new_window.c)

**Rôle :**
Créer une fenêtre à l’écran.

**En interne :**
- crée une vraie fenêtre X11
- configure les événements qu’elle peut recevoir
- l’affiche à l’écran

**Dans so_long :**

la taille dépend de la map :

<pre>
width = map_width * TILE_SIZE;
height = map_height * TILE_SIZE;
</pre>

## 3. Chargement des sprites
### mlx_xpm_file_to_image()
[`mlx_xpm_file_to_image`](./minilibx-linux/mlx_xpm.c)

**Rôle :**
Convertir un fichier `.xpm` en image MLX.

**En interne :**

- lit le fichier
- transforme les caractères en pixels
- stocke le tout dans une image utilisable

**Dans so_long :**

appel UNE SEULE FOIS au début pour :
- mur
- sol
- player
- collectible
- exit

Ensuite on réutilise les pointeurs.

## 4. Affichage d'une image
### mlx_put_image_to_window()
[`mlx_put_image_to_window`](./minilibx-linux/mlx_put_image_to_window.c)

**Rôle :**
Dessiner une image dans la fenêtre.

**En interne :**
Copie les pixels de l’image vers la fenêtre.

**Dans so_long :**
C’est ELLE qui affiche la map

<pre>
mlx_put_image_to_window(mlx, win, img, x * TILE, y * TILE);
</pre>

## 5. Gestion du clavier
### mlx_key_hook()
[`mlx_key_hook`](./minilibx-linux/mlx_key_hook.c)

**Rôle :**
Appeler une fonction quand une touche est pressée.

**En interne :**
- écoute les événements clavier
- appelle ta fonction avec le keycode

**Dans so_long :**
déplacer le joueur

## 6. Fermer avec la croix
### mlx_hook(win, 17, 0, close_game, data)
[`mlx_hook`](./minilibx-linux/mlx_hook.c)

**Rôle :**
Capturer l’événement de fermeture de la fenêtre.

**Pourquoi 17 :**
C’est l’événement X11 DestroyNotify

## 7. Lancer la boucle graphique
### mlx_loop()
[`mlx_loop`](./minilibx-linux/mlx_loop.c)

**Rôle :**
Lancer la boucle infinie qui attend les événements

**En interne :**
<pre>
while (1)
{
    attendre un événement
    exécuter le hook associé
}
</pre>

**Sans elle:**
- la fenêtre se ferme instantanément.

## 8. Clean exit (important)

[`mlx_destroy_image`](./minilibx-linux/mlx_destroy_image.c)

- Libère les images.

[`mlx_destroy_window`](./minilibx-linux/mlx_destroy_window.c)

- Détruit la fenêtre.

[`mlx_destroy_display`](./minilibx-linux/mlx_destroy_display.c) (Linux)

- Ferme la connexion avec X11