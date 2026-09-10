# Headers + Separate Compilation

This exercise practices splitting a C program into modules using `.c` and `.h` files.

## Structure

- `main.c` — program entry point
- `student.h` — public interface: structs, enums, function prototypes
- `student.c` — function implementations

## Build

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -c main.c
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -c student.c
gcc main.o student.o -o student_app