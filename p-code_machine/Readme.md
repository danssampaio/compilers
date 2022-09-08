# P-CODE-MACHINE

Code transcribed from the paschal language

# Commands

| Command | Action |
| ------ | ------ |
| LIT 0 a | load constant a |
| OPR 0 a | execute operation a (13 operations: RETURN, 5 math functions, and 7 comparison functions) |
| LOD l a | load variable l,a |
| STO l a | store variable l,a |
| CAL l a | call procedure a at level l |
| INT 0 a | increment t-register by a |
| JMP 0 a | jump to a |
| JPC 0 a | jump conditional to a |

# Commands for OPR

| Code | Symbol | Action |
| ------ | ------ | ------ |
| 0 | Return | Return from a subroutine|
| 1 | Negate | Negate the value at the top of the stack |
| 2 | ADD | x = pop(); y = pop(); push(y + x) |
| 3 | Subtract | x = pop(); y = pop(); push(y - x) |
| 4 | Multiply | x = pop(); y = pop(); push(y * x) |
| 5 | Divide | x = pop(); y = pop(); push(y / x) |
| 6 | Odd? | Checks the top value of the stack whether it is odd or not |
| 7 | == | x = pop(); y = pop(); push(y == x) |
| 8 | < > | x = pop(); y = pop(); push(y < > x) |
| 9 | < | x = pop(); y = pop(); push(y < x) |
| 10 | >= | x = pop(); y = pop(); push(y >= x) |
| 11 | > | x = pop(); y = pop(); push(y > x) |
| 12 | <= | x = pop(); y = pop(); push(y <= x) |

#
# Starting the program in Linux

With gcc installed on your machine, use these commands in the terminal for compile the program.

```sh
$ gcc p-code.c -o p-code
$ ./p-code
```
