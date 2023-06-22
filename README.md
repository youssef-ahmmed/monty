# Monty Interpreter

The Monty Bytecode Interpreter is a powerful tool for executing Monty bytecode files. Written in the C language, this interpreter can read bytecode files of any extension, although the preferred extension is `.m`. 

Our interpreter supports both `stack` (LIFO) and `queue` (FIFO) modes, and you can switch between the two modes during execution of a script. With a variety of Monty opcodes supported, you can perform a wide range of operations, including printing, mathematical calculations, and more. Below is a list of all the supported opcodes.

**The Monty Program**
- Usage: `monty file`
        - where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The monty program runs the bytecodes line by line and stop if either:
    - it executed properly every line of the file
    - it finds an error in the file
    - an error occured
- If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`

**Compile With The Following:**
```BASH
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

**Run the Interpreter**
```BASH
./monty file.m
```
---

## Monty Opcodes
- `push`
    - The opcode push pushes an element to the stack.
    - The element must be an integer
- `pall`
    - Prints all the values on the stack, starting from the top of the stack
- `pint`
    - Prints the value at the top of the stack
- `pop`
    - Removes the top element of the stack
- `nop`
    - Doesn’t do anything
- `add`
    - Adds the top two elements of the stack
    - The result is stored in the second top element of the stack, and the top element is removed
- `sub`
    - Subtracts the top element of the stack from the second top element of the stack
- `div`
    - Divides the second top element of the stack by the top element of the stack
- `mul`
    - Multiplies the second top element of the stack with the top element of the stack
- `mod`
    - Computes the rest of the division of the second top element of the stack by the top element of the stack
- `pchar`
    -  Prints the char at the top of the stack, followed by a new line
- `pstr`
    - Prints the string starting at the top of the stack, followed by a new line.
    - The string stops when either:
        - The stack is over
        - The value of the element is 0
        - The value of the element is not in the ascii table
- `swap`
    - Swaps the top two elements of the stack
- `rotl`
    - rotates the stack to the top
- `rotr`
    - rotates the stack to the bottom
- `stack`
    - Sets the format of the data to a stack (LIFO)
    - This is the default behavior of the program
- `queue`
    - sets the format of the data to a queue (FIFO)

---

## Comments and Empty Lines

- Any opcode preceeded by `#` character will be treated as comment and ignored by the interpreter.

- Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account.

### Examples
Push the integers 1, 2, 3 onto the stack and print them all, and subsequently popped off the stack and print all of them, until the stack is empty.
``` BASH
$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
$ ./monty bytecodes/07.m 
3
2
1
2
1
1
$
```

Using arithmetic operations to `add`, `mul`, `div`, `etc`. Takes the second from the top and performs the operation on the top: `second_from_top / top`, `second_from_top - top`, `etc`. Then assigns that to the `second_from_top` and pops the top element off the stack.
```BASH
$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

$ ./monty bytecodes/12.m 
3
2
1
5
1
$
```
Logical operations such as `rotl`, `rotr`, `etc`, rotates the stack to left, right. For `rotl`, the top element of the stack becomes the last one, and the second top element of the stack becomes the first one
`rotl` never fails.
```BASH
$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
$
```

You can switch to `queue` (FIFO) mode instead of the default `stack` (LIFO) mode to execute all opcodes. However, it's important to note that switching to `queue` mode does not change current `stack`, sets front of `queue` to top of stack.
```BASH
$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
$
``` 

## Authors
- [Salma Hussien](https://github.com/Sallmahussien)
- [Yousef Ahmed](https://github.com/youssef-ahmmed)
