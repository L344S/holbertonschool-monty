# MONTY PROGRAM

| Tâche | Statut | Fichier |
|-------|--------|--------|
| Vérifier si le nombre d'arguments est correct | Done | main.c |
| Ouvrir le fichier | Done | execute.c |
| Gérer l'erreur si le fichier ne peut pas être ouvert | Done | execute.c |
| Vérifier si l'instruction dans le fichier est valide | Non fait |
| Exécuter les bytecodes ligne par ligne | Non fait |
| Gérer l'erreur si une instruction invalide est trouvée | Non fait |
| Gérer l'erreur si malloc échoue | Non fait |

## ✿ Repository Files

Here is a list of the main files in the repository and a brief description of their role:

| File Name | Role | Functions |
| --------- | ---- | --------- |
| `monty.h` | This is the header file. It contains all function prototypes and structures used in the program. | None |
| `main.c` | The entry point of the program. It checks the number of arguments and calls the `execute` function with the filename as an argument. | `main` |
| `execute.c` | This file contains the `execute` function which is responsible for executing the instructions found in the Monty byte code file. The `execute` function opens the file and calls the `parseLine` function. The `parseLine` function reads a line from the Monty file, tokenizes it to separate the opcode and its argument, and then calls the `handle` function. The `handle` function compares the opcode and, if it matches a known opcode, calls the appropriate function to execute the instruction. | `execute`, `parseLine`, `handle` |
| `opcode.c` | This file contains the implementation of various opcodes (instructions) that can be found in a Monty byte code file. These functions manipulate the stack or queue according to the opcode. | `push`, `pall`, `pint`, `pop`, `swap` |
| `opcode2.c` | This file also contains the implementation of various opcodes. It's likely that the opcodes were split into two files for organizational purposes. | `add`, `nop` |
| `frees.c` | This file contains the `frees` function which is responsible for freeing all allocated memory. It's likely used to clean up memory before the program exits. | `frees` |

- Usage: monty file
where file is the path to the file containing Monty byte code

- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE

- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file

- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.
Line numbers always start at 1

- The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file  
it finds an error in the file an error occured  

- If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
