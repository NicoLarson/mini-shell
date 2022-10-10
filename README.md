# Mini-shell

## TODO

- [ ] faire un make file qui compil les fichiers
- [ ] chaque commande a un fichier main
- [ ] chaque commande va être utiliser avec l'executable

## Introduction

Ce programme est un mini-shell où il sera possible d'utiliser les commandes suivante:

- [x] mls
- [x] mpwd
- [ ] mcd
- [ ] mfind
- [x] mcat
- [ ] mgrep
- [x] mhist

```
                           ┌───────────┐
                           │ Programme │
                           └─────┬─────┘
                                 │
                            ┌────▼───┐
 ┌──────────────────────────► Prompt ◄─────────────────────────────────┐
 │                          └────┬───┘                                 │
 │                               │                                     │
 │                       ┌───────▼──────┐                              │
 │          ┌────────────┤   Commande   ├─────────┬─────────────┐      │
 │          │            └───────┬──────┘         │             │      │
 │          │                    │                │             │      │
 │ ┌────────▼───────┐  ┌─────────▼────────┐  ┌────▼────┐  ┌─────▼────┐ │
 │ │ Sans paramètre │  │  Avec paramètre  │  │ Quitter │  │ Inconnue ├─┘
 │ └───────────┬────┘  └───────┬──────────┘  └─────────┘  └──────────┘
 │             │               │
 │             │               │
 │             │               │
 │        ┌────▼───────────────▼───┐
 └────────┤ Traitement / affichage │
          └────────────────────────┘
```

Le mini-shell devra indiquer a l'utilisateur qu'il peut entrer une commande via le prompteur.
Lorsque l'utilisateur entrera une commande, le programme devra detecter le type de commande.
Si la commande est `exit`, le programme s'arrête.
Si la commande est inconnue, le message `commande inconnue` s'affiche et retour au prompteur.
Si la commande contient un paramètre, une fonction devra detecter la commande puis le paramètre. Et ainsi traiter la commande.

## Étapes

1. Créations des fichiers
2. Codage des fonctions
3. Test

### Les variables

```c
char my_commands[] = {"mls", "mpwd", "mcd", "mfind", "mcat", "mgrep", "mhist"};
```

### COMMANDES et PARAMÈTRES

Il faut tout d'abord savoir si une commende entré est:

- connue: Si une commande est dans la liste `my_commands`, elle est connue.
- avec ou sans variable

Faire une fonction `command_detector()` qui récupère l'entrée de l'utilisateur et trouve la commande.
Une commande commencera toujours au début.
Supprimer les espaces du début et prendre les premiers caractères jusqu’au prochain espace.

Faire une fonction `parameter_detector()` qui récupère l'entrée de l'utilisateur et trouve le paramètre de la commande.
Un paramètre sera toujours après une commande.

#### mcat

Affiche le contenu d'un fichier.

#### mcd

Fonctions opendir(3), readdir(3), closedir(3)

#### mfind

Fonction pour trouver un fichier ou dossier.

#### mgrep

#### mhist

Ajouter un tableau malloc pour insérer chaque commandes entré par l'utilisateur.
Ou créer un fichier contenant tous les historiques de commandes.

Affichage de l'historique des commandes exécutées avec une option pour la supprimer.

#### Fonctions

- Enregistrer les commandes
- Afficher les commandes

chdir(2)
getcwd(2)
localtime(3)

#### mls

- [x] Afficher le contenu du répertoire courant
- [ ] Afficher répertoire donné en argument.

#### mpwd

Affichage du répertoire courant.
Utilisation de la fonction `getcwd(2)`.
