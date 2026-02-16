*This project has been created as part of the 42 curriculum by <jericard>*

## Description

**ft_printf** is a project developed as part of the **42 Porto Common Core**, with the goal of replicating the standard behavior of the `printf` function in the C programming language.

The project consists of implementing a function capable of formatting and writing output to **stdout (file descriptor 1)**, handling multiple data types and format specifiers. Supported types include signed integers (`%d`, `%i`), unsigned integers (`%u`), characters (`%c`), strings (`%s`), and hexadecimal numbers (`%x`, `%X`).

### Overview

As part of the **bonus section**, the project extends the base functionality by implementing **format flags**, allowing finer control over the generated output. This requires correctly parsing flag combinations, respecting their hierarchy, and applying the appropriate behavior depending on the data type.

The implemented flags are:

- `#`  
  Adds a prefix to hexadecimal values (`0x` or `0X`) when the value is non-zero.

- `.` (precision)  
  Controls the minimum number of digits for numeric values and the maximum number of characters printed for strings.

- `0`  
  Pads the output with zeros instead of spaces when a minimum field width is specified.

- `-`  
  Left-aligns the output within the given field width.

- ` ` (space)  
  Adds a leading space to positive numbers when the `+` flag is not used.

- `+`  
  Forces the display of the sign (`+` or `-`) for numeric values.

This implementation provides a deeper understanding of how `printf` works internally, including format parsing, flag handling, and efficient output writing in C.



## Instructions

### Installation

The project must be cloned from the official GitHub repository of the user **FNYRD**:
git clone https://github.com/FNYRD/ft_printf.git

After downloading the required files and folders, create a test file with any name ending in .c.
The test file must be located in the root directory of the project.

### Compilation

Navigate to the root directory of the project and compile the library:

make

or to compile the bonus part

make bonus

To remove compiled binaries, run:
make clean

### Usage

The test file must include the project header:
#include "./includes/ft_printf.h"
#include "./includes/ft_printf_bonus.h"

Compile the test file (as in the next line, the file's name is just an example) together with the ft_printf library:
cc -g -Wall -Wextra -Werror test_printf.c -I./includes ./libftprintf.a -o test

Run the executable:
./test

If you want to check for any type of memory leak:
valgrind --leak-check=full --show-leak-kinds=all ./test


## Resources

### References

- `man printf` and related manual pages, used to understand the behavior, format specifiers, and flags of the standard `printf` function.
- Similar `ft_printf` implementations available on GitHub, consulted to compare approaches and contrast expected behavior.
- memory management: https://www.w3schools.com/c/c_memory_management.php

### Use of AI Tools

- **ChatGPT** was used to clarify conceptual doubts related to format parsing, flag hierarchy, and general project requirements.
- **Codex** was used as a debugging aid to help identify logical errors and improve code correctness during development.

### Algorithm and Data Structures

The ft_printf function is implemented using a sequential parsing algorithm that processes the format string character by character. When a percent symbol (%) is encountered, the parser analyzes the following characters to identify formatting flags and the conversion specifier.

Once the type is determined, the corresponding argument is extracted using va_arg and converted into a null-terminated character array. This representation simplifies formatting operations such as padding, precision handling, and character counting before printing.

Each printing function returns the number of characters it outputs, which are accumulated in a counter. When the end of the format string is reached, the main function returns the total number of printed characters, matching the behavior of the standard printf.

Even in cases without formatting flags, or in special cases such as %% and %c, values are converted into character arrays to ensure consistent processing.

The implementation mainly relies on character arrays (strings) as its data structure, as they provide an efficient and flexible way to manipulate textual data in C.