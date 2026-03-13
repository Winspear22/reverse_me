# Reverse Engineering Cheatsheet

Voici un récapitulatif des commandes que nous avons utilisées pour craquer les binaires.

## 🛠️ Commandes Shell (Analyse & Compilation)

| Commande | Utilité |
|----------|---------|
| `objdump -d -C -M intel binary/levelX` | Affiche l'assembleur (en syntaxe Intel, plus lisible). |
| `gcc -Wall -Wextra -Werror source.c -o level` | Compilé ton code C avec toutes les sécurités. |
| `echo "password" > level/password` | Crée un fichier contenant le mot de passe. |
| `ls -alR` | Liste tous les fichiers et dossiers récursivement. |

---

## 🕵️‍♂️ Commandes GDB (Débogage)

GDB est l'outil principal pour "entrer" dans le binaire pendant qu'il tourne.

| Commande | Raccourci | Utilité |
|----------|------------|---------|
| `gdb ./binary` | - | Lance GDB sur le binaire. |
| `break *main+0x123` | `b` | Pose un piège (breakpoint) à une adresse précise. |
| `run` | `r` | Démarre l'exécution du programme. |
| `info registers` | `i r` | Affiche la valeur de tous les registres (eax, ebx, etc.). |
| `x/s $edx` | - | **(32-bit)** Affiche le texte pointé par le registre EDX. |
| `x/s $rsi` | - | **(64-bit)** Affiche le texte pointé par le registre RSI. |
| `stepi` / `nexti` | `si` / `ni` | Avance d'une seule instruction assembleur. |
| `continue` | `c` | Continue l'exécution jusqu'au prochain piège. |
| `disassemble main` | `disas` | Affiche l'assembleur de la fonction main depuis GDB. |
| `quit` | `q` | Quitte GDB. |

---

## 💡 Astuces de détective
- En **32-bit**, les arguments des fonctions sont sur la **pile** (`stack`).
- En **64-bit**, les arguments sont dans les registres (**RDI**, **RSI**, **RDX**, **RCX**...).
- Le résultat d'une fonction (comme `strcmp` ou `atoi`) se trouve presque toujours dans **EAX / RAX**.
