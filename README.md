
# Mini-shell

## Sommaire

- [Mini-shell](#mini-shell)
  - [Sommaire](#sommaire)
  - [1. Organisation du projet](#1-organisation-du-projet)
    - [1.1. Prise de connaissance de l’énoncé](#11-prise-de-connaissance-de-lénoncé)
    - [1.2. Outils de programmation](#12-outils-de-programmation)
    - [1.3. Mise en place de l'architecture du projet](#13-mise-en-place-de-larchitecture-du-projet)
      - [1.3.1 Arborescence du projet](#131-arborescence-du-projet)
      - [1.3.2 Les dossiers](#132-les-dossiers)
        - [1.3.2.1 Le dossier racine](#1321-le-dossier-racine)
        - [1.3.2.2 `build`](#1322-build)
        - [1.3.2.2 `src`](#1322-src)
  - [2. Liste des fonctionnalités du mini shell](#2-liste-des-fonctionnalités-du-mini-shell)
    - [2.1. Indiquer a l'utilisateur d'entrer une commande en passant par le prompteur](#21-indiquer-a-lutilisateur-dentrer-une-commande-en-passant-par-le-prompteur)
    - [2.2. Enregistrer l'entrée de l'utilisateur](#22-enregistrer-lentrée-de-lutilisateur)
    - [2.3. Après l'entrée de l'utilisateur, le mini-shell continue de fonctionner](#23-après-lentrée-de-lutilisateur-le-mini-shell-continue-de-fonctionner)
    - [2.4. Le prompteur ne s’arrête que lorsque l'utilisateur entre `exit`](#24-le-prompteur-ne-sarrête-que-lorsque-lutilisateur-entre-exit)
    - [2.5. Le mini-shell enregistre les entrées de l'utilisateur dans un fichier `historique.txt`](#25-le-mini-shell-enregistre-les-entrées-de-lutilisateur-dans-un-fichier-historiquetxt)
    - [2.6. Le mini-shell distingue les commandes des arguments](#26-le-mini-shell-distingue-les-commandes-des-arguments)
    - [2.7. Si une commande existe, le mini-shell cherche le chemin de la commande puis l'exécute](#27-si-une-commande-existe-le-mini-shell-cherche-le-chemin-de-la-commande-puis-lexécute)
  - [3. Liste des fonctionnalités des commandes](#3-liste-des-fonctionnalités-des-commandes)
    - [3.1. `mcat`](#31-mcat)
      - [3.1.1 Réalisation](#311-réalisation)
    - [3.2. `mfind`](#32-mfind)
      - [3.2.1 Réalisation](#321-réalisation)
    - [3.3. `mgrep`](#33-mgrep)
      - [3.3.1 Réalisation](#331-réalisation)
    - [3.4. `mhist`](#34-mhist)
      - [3.4.1 Réalisation](#341-réalisation)
    - [3.5. `mls`](#35-mls)
      - [3.5.1 Réalisation](#351-réalisation)
    - [3.6. `mpwd`](#36-mpwd)
      - [3.6.1 Réalisation](#361-réalisation)
    - [3.7. `mcd`](#37-mcd)
      - [3.7.1 Réalisation](#371-réalisation)
  - [4. Les manquements](#4-les-manquements)
  - [5. Usage](#5-usage)
  - [6. Author](#6-author)
  - [Show your support](#show-your-support)

## 1. Organisation du projet

### 1.1. Prise de connaissance de l’énoncé

Créer un programme `mini-shell` où il sera possible d'utiliser les commandes suivantes: `mfind`, `mcd`, `mls`, `mpwd`, `mcat`, `mhist` et `mgrep`.

### 1.2. Outils de programmation

- Éditeur de code: VSCODE
- Environnement GNU/Linux: WSL
- Compilateur: `gcc`
- Outil de compilation: `make`

### 1.3. Mise en place de l'architecture du projet

#### 1.3.1 Arborescence du projet

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

#### 1.3.2 Les dossiers

##### 1.3.2.1 Le dossier racine

Le dossier racine contient le fichier mini-shell.c qui contient le code du mini-shell qui permet d'exécuter les différentes commandes.

##### 1.3.2.2 `build`

Le dossier `build` contiens les exécutables des commandes

##### 1.3.2.2 `src`

Le dossier `src` contient le code des commandes ainsi que leur makefile.

> Le code de la commande `mcd` se trouve directement dans le fichier mini_shell.c

## 2. Liste des fonctionnalités du mini shell

```asci

                             ┌──────────┐
                             │Mini-shell│
                             └─────┬────┘
                                   │
                                   │
                              ┌────▼────┐
                 ┌────────────┤Prompteur◄──┬──────────────────────┐
                 │            └─────────┘  │                      │
                 │                         │                      │
                 │                         │                      │
      ┌──────────▼────────────┐   ┌────────┴────────┐ ┌───────────┴──────────┐
      │Entrée de l'utilisateur│   │Commande inconnue│ │Execution du programme│
      └────┬────────────────┬─┘   └────────▲────────┘ └───────────▲──────────┘
           │                │              │                      │
           │                │              │                      │
           │          ┌─────▼─────┐        │                      │
           │          │Traitements│        ├──────────────────────┘
           │          └───────┬───┘        │
           │                  │            │
           │                  │            │
┌──────────▼─────────┐     ┌──▼────────────┴───────────────┐
│Quitter le programme│     │Enregistrement dans history.txt│
└────────────────────┘     └───────────────────────────────┘
```

### 2.1. Indiquer a l'utilisateur d'entrer une commande en passant par le prompteur

```c
printf("mini-shell> ");
```

### 2.2. Enregistrer l'entrée de l'utilisateur

```c
fgets(input, 100, stdin);
```

### 2.3. Après l'entrée de l'utilisateur, le mini-shell continue de fonctionner

```c
int exit_mini_shell = 0;
while (exit_mini_shell == 0){ /* CODE */ }
```

### 2.4. Le prompteur ne s’arrête que lorsque l'utilisateur entre `exit`

```c
if (strcmp(arg_list[0], "exit") == 0)
    exit_mini_shell = 1;
```

### 2.5. Le mini-shell enregistre les entrées de l'utilisateur dans un fichier `historique.txt`

```c
void add_to_history_file(char *to_add);
```

### 2.6. Le mini-shell distingue les commandes des arguments

```c
char **arg_list = calloc(100, sizeof(char *));
char *input = calloc(100, sizeof(char));
fgets(input, 100, stdin);
char *token = strtok(input, " ");
int i = 0;
while (token != NULL){
    arg_list[i] = token;
    token = strtok(NULL, " ");
    i++;
}
arg_list[i - 1] = strtok(arg_list[i - 1], "\n");
arg_list[i] = NULL;
// arg_list[0]: Commande
// arg_list[n]: Arguments
```

### 2.7. Si une commande existe, le mini-shell cherche le chemin de la commande puis l'exécute

La fonction `concatenate` est utilisé pour concaténer le chemin de la commande avec le nom de la commande.

```c
char *concatenate(char *s1, char *s2){
    char *result = malloc(strlen(s1) + strlen(s2));
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
```

Ensuite, on exécute la commande avec la fonction `execvp`.

```c
int mini_shell(void){
    char *leaving_prog_directory = "/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/build/";
    /* CODE */
        char *command_build = concatenate(leaving_prog_directory, arg_list[0]);
        char *command = strtok(command_build, "\n");
    /* CODE */
            execvp(command, arg_list);
    /* CODE */
}
```

## 3. Liste des fonctionnalités des commandes

### 3.1. `mcat`

Affiche le contenu d'un fichier.

#### 3.1.1 Réalisation

La fonction `mcat` prend en paramètre une chaîne de caractères `file_directory`.
On ouvre le fichier `file_directory`.
Si on rencontre une erreur de lecture, on affiche une erreur.
Sinon, tant que le fichier n'est pas terminé, on parcourt chaque caractère du fichier et on l'affiche.

```c
void mcat(char *file_directory){
    char ch;
    FILE *fp;
    printf("\n---\nfile_directory: %s\n---\n", file_directory);
    fp = fopen(file_directory, "r");
    if (fp == NULL){
        int errnum = errno;
        fprintf(stderr, "%s \n", strerror(errnum));
    }else{
        ch = fgetc(fp);
        while (ch != EOF){
            printf("%c", ch);
            ch = fgetc(fp);
        }
        fclose(fp);
    }
}
```

### 3.2. `mfind`

Rechercher des fichiers par nom dans un répertoire.

#### 3.2.1 Réalisation

Le premier argument est le répertoire dans lequel on recherche les fichiers `directory_name`.
Le deuxième argument est le nom du fichier que l'on recherche `word_to_find`.
On ouvre le répertoire `directory_name`.
Si l’on rencontre une erreur d'ouverture, on affiche une erreur.
Sinon, on parcourt chaque fichier du répertoire et on compare le nom du fichier avec `word_to_find`.
Si le nom du fichier correspond à `word_to_find`, on affiche le chemin du fichier.

```c
int main(int argc, char *argv[]){
    char *word_to_find = argv[2];
    DIR *d;
    struct dirent *rp;
    char *directory_name = argv[1];
    d = opendir(directory_name);
    if (d == NULL){
        perror("opendir");
        return EXIT_FAILURE;
    }
    rp = readdir(d);
    while (rp != NULL){
        if (strncmp(rp->d_name, word_to_find, 3) == 0){
            if (rp->d_type == 4){
                fprintf(stdout, "Find directory: \"%s\" in %s\n", rp->d_name, directory_name);
            }else{
                fprintf(stdout, "Find file: \"%s\" in %s\n", rp->d_name, directory_name);
            }
        }
        rp = readdir(d);
    }
    closedir(d);
    printf("\n");
    return EXIT_SUCCESS;
}
```

### 3.3. `mgrep`

Afficher des lignes de fichiers donnés en argument contenant une chaîne de caractères aussi donnée en argument.

#### 3.3.1 Réalisation

On vérifie le nombre d'arguments.
Si le nombre d'arguments est inférieur à 3, indique la façon d'utiliser la commande puis on quitte la fonction.
Sinon, on parcourt chaque fichier et on affiche les lignes qui contiennent la chaîne de caractères.
Si l’on rencontre une erreur d'ouverture, on affiche une erreur.

```c
int main(int argc, char **argv){
    if (argc < 3){
        printf("Utilisation: %s string fichier& [fichier2 ...]\n", argv[0]);
        return 1;
    }
    for (int i = 2; i < argc; i++){
        FILE *file = fopen(argv[i], "r");
        if (file == NULL){
            printf("Erreur: ouverture du fichier %s\n", argv[i]);
            continue;
        }
        char *line = NULL;
        size_t size = 0;
        int line_number = 0;
        while (getline(&line, &size, file) != -1){
            line_number++;
            if (strstr(line, argv[1]) != NULL){
                printf("%s: ligne %d:\n%s", argv[i], line_number, line);
            }
        }
        fclose(file);
    }
    return 0;
}
```

### 3.4. `mhist`

Affichage de l'historique des commandes exécutées avec une option pour la supprimer.

#### 3.4.1 Réalisation

On créer une fonction qui va lire le fichier `historique.txt` et l'afficher.

```c
void mhist(void){
    char ch;
    FILE *fp;
    fp = fopen("./mini-shell/history.txt", "r");
    ch = fgetc(fp);
    while (ch != EOF){
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}
```

On créer une fonction qui supprime le fichier `history.txt`

```c
void clean_history(void){
    remove("./mini-shell/history.txt");
}
```

Puis, une fonction qui va vérifier si l'utilisateur a entré l'option pour supprimer l'historique.

```c
#define OPTIONS "c"

void mhist(void){/* CODE */}
void clean_history(void){/* CODE */}

int main(int argc, char **argv){
    opterr = 0;
    char option = 0;
    while (option != -1){
        option = getopt(argc, argv, OPTIONS);
        switch (option){
        case 'c':
            clean_history();
            break;
        case '?':
            fprintf(stdout, "Option %c inconnue\n", optopt);
            break;
        }
    }
    mhist();
    return EXIT_SUCCESS;
}
```

### 3.5. `mls`

Affichage du contenu du répertoire courant ou du répertoire donné en argument.

#### 3.5.1 Réalisation

Si aucun répertoire n'est donné en argument, le répertoire courant est utilisé.
Sinon, on ouvre le répertoire donné en argument.
Si l'on rencontre une erreur d'ouverture, on affiche une erreur.
Sinon, on parcourt chaque fichier du répertoire puis on affiche le nom du fichier.

```c
int main(int argc, char **argv){
    DIR *d;
    struct dirent *rp;
    char *directory_name = "./";
    if (argc == 2)    {
        directory_name = argv[1];
    }
    d = opendir(directory_name);
    if (d == NULL){
        perror("opendir");
        return EXIT_FAILURE;
    }
    rp = readdir(d);
    while (rp != NULL){
        fprintf(stdout, "%s\n", rp->d_name);
        rp = readdir(d);
    }
    closedir(d);
    printf("\n");
    return EXIT_SUCCESS;
}
```

### 3.6. `mpwd`

Affichage du répertoire courant.

#### 3.6.1 Réalisation

On utilise la fonction `getcwd` pour récupérer le répertoire courant.
Si l'on rencontre une erreur, on affiche une erreur.
Sinon, on affiche le répertoire courant.

```c
int main(void){
    char CWD[256];
    if (getcwd(CWD, sizeof(CWD)) == NULL)
        perror("getcwd(): error\n");
    else
        printf("%s\n", CWD);
    return 0;
}
```

### 3.7. `mcd`

Changer le répertoire courant.

#### 3.7.1 Réalisation

La commande `mcd` est codée dans le fichier `mini-shell.c` pour éviter de quitter le flux de l'application.
Elle prend en argument le répertoire dans lequel on veut se déplacer.
On utilise la fonction `chdir` pour changer le répertoire courant.

```c
int mcd(char *directory){
    int ch = chdir(directory);
    if (ch < 0)
        printf("chdir change of directory not successful\n");
    system("pwd");
    return 0;
}
```

## 4. Les manquements

- Implementation des redirection `>` et `|`
- Les signaux de terminaison
- La coloration syntaxique

## 5. Usage

```bash
make
make run
```

## 6. Author

👤 **Nicolas Yang**

- Website: [nicolasyang.dev](https://nicolasyang.dev)
- Github: [@NicoLarson](https://github.com/NicoLarson)
- LinkedIn: [@nicolas-yang-dev](https://linkedin.com/in/nicolas-yang-dev)

## Show your support

Give a ⭐️ if this project helped you!
