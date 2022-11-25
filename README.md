# Mini-shell

// TODO: Mettre les chemin absolut pour tous le programme

## Introduction

Ce programme est un mini-shell où il sera possible d'utiliser les commandes suivante:

### TODO

- [ ] mfind
- [x] mcd dans le fichier mini-shell.c
- [x] mls
- [x] mpwd
- [x] mcat
- [x] mhist
- [x] mgrep

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

Il faut tout d'abord savoir si une commande entré est:

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

// FIXME: la fonction chdir() fait changer de repertoire et les autres chemins des commandes changes.
// TODO: Mettre les chemin absolut pour tous le programme

Fonction mcd est dans le fichier mini-shell car histoire de processus ...

#### mfind

Rechercher des fichiers dans une hiérarchie de répertoires.
`find [chemin...] [expression]`

Utiliser **regex**.

il faut:

1. Récupérer le mot à chercher entré par l'utilisateur.
2. Parcourir tous les dossiers et sous dossier
3. Comment parcourir les fichiers ?

4. Si correspondance est détecté
   1. afficher le chemin du fichier
   2. Puis continuer la recherche
5. Sinon continuer la recherche

#### mgrep

Vérifier le nombre d'argument.
Si le nombre d'argument est inférieur à 3, afficher un message d'erreur
Sinon parcourir les fichiers en argument

- Ouvrir le fichier
  - Si problème d'ouverture afficher un message d'erreur
  - Sinon parcourir les ligne
  - Rechercher la chaîne de caractères dans la ligne
  - Puis afficher la ligne
- Fermer le fichier

#### mhist

// TODO: Ajouter une option
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
