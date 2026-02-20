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
	2. [Vérification du chemin (algo Flood Fill)](#2-vérification-du-chemin-algo-flood-fill)
	3. [Initialisation graphique](#3-initialisation-graphique)
	4. [Affichage de la map (Rendering)](#4-affichage-de-la-map-rendering)
	5. [Gestion des déplacements](#5-gestion-des-déplacements)
	6. [Clean exit](#6-clean-exit)
		- [Résumé étapes](#résumé-étapes)
3. [MINILIBX](#minilibx)
	1. [Qu'est-ce que la MiniLibX?](#quest-ce-que-la-minilibx)
		- [Pourquoi on l'utilise dans so_long ?](#pourquoi-on-lutilise-dans-so_long-)
	2. [Ce que la MiniLibX permet de faire (index des fonctions)](#ce-que-la-minilibx-permet-de-faire-index-des-fonctions)
		- [Créer une fenêtre](#créer-une-fenêtre)
		- [Charger des images](#charger-des-images)
		- [Afficher des images dans la fenêtre](#afficher-des-images-dans-la-fenêtre)
		- [Gérer les événements](#gérer-les-événements)
		- [Lancer la boucle graphique](#lancer-la-boucle-graphique)
	3. [Logique de fonctionnement](#logique-de-fonctionnement)
		- [Application concrète dans so_long](#application-concrète-dans-so_long)
	4. [Points importants à retenir](#points-importants-à-retenir)
	5. [Résumé MiniLibX](#résumé-minilibx)

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

## 2. Vérification du chemin (algo Flood Fill)
But :  
Vérifier que le joueur peut atteindre :

- tous les collectibles
- la sortie

On fait une copie de la map et on “remplit” depuis `P`

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
- afficher des sprites (mur, sol, joueur, collectibles, exit)
- gérer les touches du clavier
- fermer le programme proprement

---

## Ce que la MiniLibX permet de faire (index des fonctions)

### Créer une fenêtre
[`mlx_new_window.c`](./minilibx-linux/mlx_new_window.c)

crée une surface d’affichage

### Charger des images
[`mlx_xpm_file_to_image`](./minilibx-linux/mlx_xpm.c)

transformer un fichier .xpm en image affichable

### Afficher des images dans la fenêtre
[`mlx_put_image_to_window`](./minilibx-linux/mlx_put_image_to_window.c)

dessiner un sprite à une position donnée en pixels.

### Gérer les événements
[`mlx_key_hook`](./minilibx-linux/mlx_key_hook.c) / [`mlx_hook`](./minilibx-linux/mlx_hook.c)

- détecter les touches clavier
- détecter le clic sur la croix de la fenêtre

### Lancer la boucle graphique
[`mlx_loop`](./minilibx-linux/mlx_loop.c)

le programme reste en attente d’événements, c’est le “cœur” du programme graphique.

## Logique de fonctionnement

Avec la MiniLibX, un programme ne s’exécute plus de manière linéaire.

> **Étapes :** Initialisation MLX → Fenêtre → Images → Hooks → Boucle

Ensuite, ce sont les événements qui déclenchent les actions.

### Application concrète dans so_long
À chaque déplacement du joueur :

- on met à jour la map en mémoire
- on redessine les images dans la fenêtre

La MiniLibX ne met pas à jour l’écran automatiquement.
C’est au programme de redessiner l’affichage.

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