# Minishell2

> Projet EPITECH 2024 — Un mini shell Unix implémenté en C.

## Description

**Minishell2** est la suite de Minishell1. Il s'agit d'un interpréteur de commandes minimaliste écrit en C qui reproduit le comportement de base d'un shell Unix (type `tcsh`). Ce projet étend les fonctionnalités du premier minishell en ajoutant la gestion des **pipes**, des **redirections** et des **séparateurs de commandes**.

---

## Fonctionnalités

### Commandes built-in
| Commande | Description |
|---|---|
| `env` | Affiche les variables d'environnement |
| `setenv VAR value` | Crée ou modifie une variable d'environnement |
| `unsetenv VAR` | Supprime une variable d'environnement |
| `cd [path]` | Change le répertoire courant |

### Exécution de commandes externes
- Recherche automatique des binaires via la variable `$PATH`
- Exécution de commandes avec chemin absolu (`/bin/ls`)

### Pipes (`|`)
- Redirection de la sortie d'une commande vers l'entrée d'une autre
```sh
b_sh <3 ls | grep .c
```

### Redirections
| Syntaxe | Description |
|---|---|
| `cmd > file` | Redirige la sortie vers un fichier (écrasement) |
| `cmd >> file` | Redirige la sortie vers un fichier (ajout) |
| `cmd < file` | Lit l'entrée depuis un fichier |
| `cmd << DELIM` | Here-document : lit l'entrée jusqu'au délimiteur |

### Séparateur de commandes (`;`)
- Exécution séquentielle de plusieurs commandes sur une même ligne
```sh
b_sh <3 echo hello ; ls ; pwd
```

---

## Compilation

```sh
make
```

Produit l'exécutable `mysh`.

```sh
make clean   # supprime les fichiers objets
make fclean  # supprime les fichiers objets et l'exécutable
make re      # recompile entièrement
```

---

## Utilisation

```sh
./mysh
```

Le shell affiche le prompt `b_sh <3 ` lorsqu'il est lancé en mode interactif (TTY). Il peut également être utilisé en mode non-interactif (lecture depuis un fichier ou un pipe).

### Exemples

```sh
b_sh <3 ls -la
b_sh <3 echo "Hello, World!"
b_sh <3 ls | grep Makefile
b_sh <3 cat < Makefile
b_sh <3 ls > output.txt
b_sh <3 echo test >> output.txt
b_sh <3 setenv MY_VAR hello
b_sh <3 env
b_sh <3 unsetenv MY_VAR
b_sh <3 cd /tmp ; pwd
```

---

## Structure du projet

```
Minishell2/
├── Makefile
├── my.h                        # En-têtes et prototypes
└── src/
    ├── main.c                  # Point d'entrée, boucle principale
    ├── mini_main.c             # Dispatch redirections / commandes / séparateurs
    ├── pipe.c                  # Gestion des pipes
    ├── redirection.c           # Gestion des redirections (>, >>, <, <<)
    ├── process.c               # Exécution des processus (fork/exec)
    ├── pathing.c               # Résolution du chemin via $PATH
    ├── getcmd.c                # Lecture de la ligne de commande
    ├── cd.c                    # Built-in cd
    ├── setenv.c                # Built-ins setenv / unsetenv
    ├── env_functions.c         # Copie et affichage de l'environnement
    ├── spliting.c              # Découpage de l'environnement
    ├── concat_strings.c        # Utilitaire de concaténation
    ├── countr.c                # Comptage de caractères
    ├── verify.c                # Vérification des redirections
    ├── my_strlen.c             # Implémentation de strlen
    ├── my_strcmp.c             # Implémentation de strcmp
    ├── my_strncmp.c            # Implémentation de strncmp
    ├── my_strdup.c             # Implémentation de strdup
    ├── my_strcpy.c             # Implémentation de strcpy
    ├── mini_printf.c           # Implémentation minimaliste de printf
    ├── my_str_to_word_array1.c # Tokenisation de la ligne de commande
    ├── my_str_to_word_array2.c # Découpage sur ';'
    ├── my_str_to_word_array3.c # Découpage sur '>'
    ├── my_str_to_word_array4.c # Découpage sur '<'
    └── my_str_to_word_array5.c # Découpage sur '|'
```

---

## Auteur

Projet réalisé dans le cadre du cursus **EPITECH** (2024).
