# Mini-shell

## Introduction

Ce programme est un mini-shell où il sera possible d'utiliser les commandes suivante:

- [ ] mls
- [x] mpwd
- [ ] mcd
- [ ] mfind
- [ ] mcat
- [ ] mgrep
- [ ] mhist

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
Si la commande contient un paramètre, une fonction devra detecter la commande puis le parametre. Et ainsi traiter la commande.

### Les variables

```c
char my_commands[] = {"mls", "mpwd", "mcd", "mfind", "mcat", "mgrep", "mhist"};
```

### Les fonctions

#### COMMANDE / PARAMÈTRE

```c
parameter_detector()
space_remover()
is_command_exist()
is_parameter_exist()
```

##### command_detector()

Faire une fonction qui récupère l'entrée de l'utilisateur et trouve la commande.
Une commande commencera toujours au début.
Supprimer les espaces du début et prendre les premiers caractères jusqu’au prochain espace.

```c
command_detector()
```

#### parameter_detector()

Faire une fonction qui récupère l'entrée de l'utilisateur et trouve le parametre de la commande.
Un paramètre sera toujours après une commande.

## mls

- [x] Afficher le contenu du répertoire courant
- [ ] Afficher répertoire donné en argument.

## mpwd

Affichage du répertoire courant.
Utilisation de la fonction `getcwd(2)`.

## mcd

Fonctions opendir(3), readdir(3), closedir(3)

## mfind

## mcat

## mgrep

## mhist

Affichage de l'historique des commandes exécutées avec une option pour la supprimer.

### Fonctions

- Enregistrer les commandes
- Afficher les commandes

chdir(2)
getcwd(2)
localtime(3)
