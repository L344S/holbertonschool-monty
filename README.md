# MONTY PROGRAM

## Table of Contents
- [Description](#description)
- [Run Locally](#run-locally)
- [Example of use](#example-of-use)
- [Commands](#commands)
- [Authors](#authors)

## Description
The Monty program is a scripting language interpreter that reads and executes instructions from a file (.m) line by line. It is designed to use a unique stack with specific instructions to manipulate it.

### ✿ Flowchart
![Screenshot](./Docs/flowchart.png)

### ✿ Screenshot
![Screenshot](./Docs/screenshot.png)

### ✿ Repository Files

Here is a list of the main files in the repository and a brief description of their role:

| File Name | Role | Functions |
| --------- | ---- | --------- |
| `monty.h` | This is the header file. It contains all function prototypes and structures used in the program. | None |
| `main.c` | The entry point of the program. It checks the number of arguments and calls the `execute` function with the filename as an argument. | `main` |
| `execute.c` | This file contains the `execute` function which is responsible for executing the instructions found in the Monty byte code file. The `execute` function opens the file and calls the `parseLine` function. The `parseLine` function reads a line from the Monty file, tokenizes it to separate the opcode and its argument, and then calls the `handle` function. The `handle` function compares the opcode and, if it matches a known opcode, calls the appropriate function to execute the instruction. | `execute`, `parseLine`, `handle` |
| `opcode.c` | This file contains the implementation of various opcodes (instructions) that can be found in a Monty byte code file. These functions manipulate the stack or queue according to the opcode. | `push`, `pall`, `pint`, `pop`, `swap` |
| `opcode2.c` | This file also contains the implementation of various opcodes. It's likely that the opcodes were split into two files for organizational purposes. | `add`, `nop` |
| `frees.c` | This file contains the `frees` function which is responsible for freeing all allocated memory. It's likely used to clean up memory before the program exits. | `frees` |

### ✿ Project Tasks
| Task | Description | Status |
| ---- | ----------- | ------ |
| 1.   | Create the header file | Done |
| 2.   | Implement the main function to check the number of arguments and print the appropriate error message if needed | Done |
| 3.   | Implement the functionality to open the file and print an error message if it's not possible | Done |
| 4.   | Implement the functionality to read the file line by line | Done |
| 5.   | Implement the functionality to parse the file's text into opcode and argument | Done |
| 6.   | Implement the functionality to handle invalid instructions and print the appropriate error message | Done |
| 7.   | Implement the functionality to execute the correct function for the given opcode | Done |
| 8.   | Ensure that the program stops executing if an error occurs or if it has executed all lines of the file | Done |
| 9.   | Use malloc and free for memory management and avoid memory leaks | Done |

## Run Locally
### ✿ Prerequisites
To install and run this program, ensure you have the following:

- Operating System: Ubuntu 20.04 LTS
- Compiler: gcc
- Compiler Options: -Wall -Werror -Wextra -pedantic -std=gnu89

### ✿ Installation
Use the following command to install the monty program:

```bash
# Clone the repository
git clone https://github.com/L344S/holbertonschool-monty.git

# Navigate to the project directory
cd holbertonschool-monty

# Compile the files
gcc -Wall -Werror -Wextra -pedantic *.c -o monty

# Run the monty program :
./monty <file>
```

## Example of use
```sh
leasel@MacBook-Pro-de-Lea holbertonschool-monty % cat bytecodes/06.m    
push 1
pint
push 2
pint
push 3
pint                 
leasel@MacBook-Pro-de-Lea holbertonschool-monty % ./monty bytecodes/06.m
1
2
3
leasel@MacBook-Pro-de-Lea holbertonschool-monty %
```

```sh
leasel@MacBook-Pro-de-Lea holbertonschool-monty % cat bytecodes/09.m
push 1
push 2
push 3
pall
swap
pall                
leasel@MacBook-Pro-de-Lea holbertonschool-monty % ./monty bytecodes/09.m
3
2
1
2
3
1
leasel@MacBook-Pro-de-Lea holbertonschool-monty % 
```

## Commands
| Opcode  | Description |
| -------- |:------------|
| push     | Pushes an element to the stack |
| pall     | Prints all values on the stack, starting from the top |
| pint     | Prints the value at the top of the stack |
| pop      | Removes the top element of the stack |
| swap     | Swaps the top two elements of the stack |
| add      | Adds the top two elements of the stack |
| nop      | Does nothing |

## Authors
- [@Yazgahar](https://www.github.com/Yazgahar)
- [@L344S](https://www.github.com/L344S)

