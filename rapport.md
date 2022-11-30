# Rapport

## Organisation global du projet

### Arborescence du projet

```bash
├── build
│   ├── mcat
│   ├── mcd
│   ├── mfind
│   ├── mgrep
│   ├── mhist
│   ├── mls
│   └── mpwd
├── history.txt
├── main.c
├── makefile
├── mini_shell
├── mini_shell.c
├── mini_shell.h
└── src
    ├── mcat
    │   ├── main.c
    │   └── makefile
    ├── mfind
    │   ├── main.c
    │   └── makefile
    ├── mgrep
    │   ├── main.c
    │   └── makefile
    ├── mhist
    │   ├── main.c
    │   └── makefile
    ├── mls
    │   ├── main.c
    │   └── makefile
    └── mpwd
        ├── main.c
        └── makefile
```

### Dossiers

#### Racine

Contient le fichier mini-shell.c qui contient le code du mini-shell qui permet d'executer les différentes commandes.

#### build

Contient les executables des commandes

### src

Contient le code des commandes ainsi que leur makefile.

> Le code de la commande mcd ce trouve directement dans le fichier mini_shell.c

## Méthodologiques

1. Prise de connaissance de l’énoncé
2. Mise en place des outils de programmation
3. Mise en place de l'architecture du projet
4. Liste des fonctionnalités du mini shell
5. Liste des fonctionnalité des commandes
6. Le code

## Réalisation

### Le mini shell

Le mini-shell devra indiquer a l'utilisateur qu'il peut entrer une commande via le prompteur.
Lorsque l'utilisateur entrera une commande avec ou sans argument, le programme détectera si la commande est connu.  
Si l'utilisateur entre `exit`, le programme s'arrête.
Si la commande contient un paramètre, une fonction devra detecter la commande puis le paramètre. Et ainsi traiter la commande.

### Les commandes

#### mcat

La fonction ce trouve dans le fichier mini_shell.c ligne 27

#### mfind

#### mgrep

#### mhist

option: -c pour nettoyer l'historique.

#### mls

```c

```

#### mpwd

Utilisation de la fonction getcwd() pour afficher le repertoire courant.

```c
int main(void)
{
    char CWD[256];
    if (getcwd(CWD, sizeof(CWD)) == NULL)
        perror("getcwd(): error\n");
    else
        printf("%s\n", CWD);
    return 0;
}
```

## Manquements

Implémentation des redirections > et |.
Les signaux de terminaison.
Méthode de terminaison du mini-shell
La coloration syntaxique

## Organisation des taches
