<div align="center">

*This project has been created as part of the 42 curriculum by thcardos*

# ![get_next_line](https://img.shields.io/badge/get_next_line-9932CC?style=for-the-badge&logo=42&logoColor=white)

</div>

## ![Description](https://img.shields.io/badge/Description-B19CD9?style=flat-square)

<sub>get_next_line is a function that returns a line read from a file descriptor. This project is part of the 42 curriculum and enables students to practise advanced C concepts such as static variables, memory management, and buffer handling.

</sub>

<sub>

| Specifiers | Description |
|---------|-------------|
| `%c` | Prints a character |
| `%s` | Prints a text string |
| `%d / %i` | Prints a signed integer |
| `%u` | Prints an unsigned integer |
| `%x` | Prints a number in hexadecimal (lowercase) |
| `%X` | Prints a hexadecimal number (uppercase) |
| `%p` | Prints a pointer (memory address) |
| `%%` | Prints the per cent symbol |

| Function Prototype | Description | Parameters | Return Value |
|---------|-------------|-------------|-------------|
| char *get_next_line(int fd)|Returns a line read from a file descriptor|fd: The file descriptor to read from |Read line: correct behavior NULL: there is nothing else to read, or an error occurred|

</sub>

<sub>**Below is a detailed description of each function and its logic:** 
</sub>

<sub>**Main Functions**</sub>

<sub>**`get_next_line`** </sub>

<sub>- Main entry point of the library</sub>

<sub>- Takes a file descriptor as argument</sub>

<sub>- Uses a static variable to save the remainder of the buffer</sub>

<sub>- Returns a dynamically allocated string containing the line</sub>

<sub>- Returns NULL on error or EOF</sub>

<sub>**`get_line`** </sub>

<sub>- Handles the extraction of the line from the static buffer</sub>

<sub>- Checks for the newline character '\n'</sub>

<sub>- Manages the static variable update for the next call</sub>

<sub>- Returns the extracted line</sub>

<sub>**`ft_strjoin`** </sub>

<sub>- Joins two strings into a newly allocated string</sub>

<sub>- Handles memory allocation safely</sub>

<sub>- Frees the temporary buffers if necessary</sub>

<sub>- Returns the concatenated string</sub>

<sub>**`ft_process_valid`**</sub>

<sub>**Output Functions**</sub>

<sub>**`ft_print_char`**</sub>

<sub>- Prints a single character</sub>

<sub>- Casts input to `unsigned char` to handle edge cases</sub>

<sub>- Returns 1 (always prints exactly one character)</sub>

<sub>**`ft_print_str`**</sub>

<sub>- Prints a string safely</sub>

<sub>- Handles NULL pointers by printing "(null)"</sub>

<sub>- Returns the length of the printed string</sub>

<sub>**`ft_print_int`**</sub>

<sub>- Converts signed integers to strings and prints them</sub>

<sub>- Uses `ft_itoa()` from libft to handle the conversion</sub>

<sub>- Manages memory deallocation after printing</sub>

<sub>- Returns the number of digits printed</sub>

<sub>**`ft_print_uint`**</sub>

<sub>- Prints unsigned integers directly without conversion</sub>

<sub>- Uses recursive digit extraction to avoid string allocation</sub>

<sub>- Counts and prints each digit in sequence</sub>

<sub>- Returns the number of digits printed</sub>

<sub>**`ft_print_hex`**</sub>

<sub>- Converts unsigned integers to hexadecimal format</sub>

<sub>- Supports both lowercase (%x) and uppercase (%X) formats</sub>

<sub>- Uses a lookup string ("0123456789abcdef" or "0123456789ABCDEF")</sub>

<sub>- Recursively processes each hexadecimal digit</sub>

<sub>- Returns the number of characters printed</sub>

<sub>**`ft_print_ptr`**</sub>

<sub>- Prints memory addresses (pointers) in hexadecimal format</sub>

<sub>- Adds the "0x" prefix before the address</sub>

<sub>- Handles NULL pointers appropriately</sub>

<sub>- Uses `unsigned long` for pointer arithmetic</sub>

<sub>- Returns the total characters printed (including "0x")</sub>

<sub>**Algorithm and Data Structure**</sub>

<sub>**`Character-by-character format analysis`**</sub>

<sub>I walk through the format string and react only when I encounter a `%`.</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- It is simple and easy to follow.</sub>

<sub>- It does not require complex structures.</sub>

<sub>- It is efficient: it reads each character only once.</sub>

<sub>- It is the same strategy used by the original `printf`.</sub>

<sub>**`Converting numbers with recursivity`**</sub>

<sub>To print `%u`, `%x`, and `%X`, I use recursive functions that divide the number by the base (10 or 16) and then print the digit.</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- Recursion prints from left to right without storing digits in an array.</sub>

<sub>- It avoids using extra memory to construct a string.</sub>

<sub>- It is easy to read and check.</sub>

<sub>- less memory and simpler code.</sub>

<sub>**`Symbol table for hexadecimal`**</sub>

<sub>I use a string such as ‘0123456789abcdef’ or ‘0123456789ABCDEF’.</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- Avoids many `if/else` statements.  </sub>

<sub>- It makes the code shorter and easier to read. </sub>

<sub>- It is cleaner and faster.</sub>

<sub>**`Separating printing and counting`**</sub>

<sub>I use functions that print and others that count how many digits are printed (`ft_count_digits`).</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- The `ft_printf` function must return the exact number of characters.  </sub>

<sub>- Separating responsibilities prevents errors improves clarity and facilitates testing. </sub>

<sub>- It is cleaner and faster.</sub>

<sub>**`ft_itoa() for signed integers`**</sub>

<sub>I reuse a previously tested function `ft_itoa()` from my `libft` to convert signed integers</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- It handles negative signs correctly.</sub>

<sub>- It simplifies the logic in `ft_print_int()`.</sub>

<sub>**`Chosen data types`**</sub>

<sub>

| Function | Type | Justification |
|--------|------|---------------|
| `ft_print_int()` | `int` | It is the standard type for `%d` and `%i` |
| `ft_print_uint()` | `unsigned int` | Avoids problems with negative numbers |
| `ft_print_hex()` | `unsigned int` | Unsigned base 16 |
| `ft_print_ptr()` | `unsigned long` | Allows complete addresses to be represented |

</sub>

<sub>**`Handling NULL`**</sub>

<sub>- It revents memory access errors.</sub>

<sub>- It matches the actual behaviour of `printf`:</sub>

<sub>- `‘(null)’` for null strings</sub>

<sub>- `‘(nil)’` for null pointers</sub>


## ![Instructions](https://img.shields.io/badge/Instructions-B19CD9?style=flat-square)

<sub>

**Compilation with the library**
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

**Available commands**

| Comand | Description |
|---------|-------------|
| `make` | Compiles the library |
| `make clean` | Deletes all the object files (.o) |
| `make fclean` | Deletes the object files and the library |
| `make re` | Compiles everything again |

</sub>

<sub>**Testing the functions:**</sub>

<sub>Here you have the [Main File](https://github.com/thcardos/ft_printf/blob/main/main.c) I have created to test my functions.
</sub>


<sub>

**Memory verification with Valgrind:**
```bash
# Compile your program with the library (-L search for libraries in the current directory (.) and -lftprintf links with the libary libftprintf.a)
cc -g -Wall -Wextra -Werror main.c -L. -lftprintf -o test

# Run with Valgrind
valgrind --leak-check=full ./program

# Show all possible Leaks
valgrind --leak-check=full --show-leak-kinds=all ./test

# Display detailed information about the errors
valgrind --leak-check=full --track-origins=yes ./test

# Save the report to a file
valgrind --leak-check=full --log-file=valgrind_report.txt ./test
```

**🟩Without errors🟩**
```bash
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
  total heap usage: X allocs, X frees, Y bytes allocated

All heap blocks were freed -- no leaks are possible
```

**🟥With errors🟥**
```bash
LEAK SUMMARY:
   definitely lost: 24 bytes in 1 blocks
```
This indicates that there is memory that was allocated with malloc but never freed with free.


**Using GDB (GNU Debugger)**

GDB is an interactive debugger that allows you to inspect your program while it runs.

**Basic usage:**
```bash
# Compile with debugging symbols
gcc -g -Wall -Wextra -Werror main.c -L. -lftprintf -o test

# Start GDB
gdb ./test
```

**GDB commands**

| Comand | Description |
|---------|-------------|
| `run` | Execute the program |
| `break main` | Set a breakpoint at main function |
| `break your_program` | Set a breakpoint at your_program |
| `next` | Execute next line (step over) |
| `step` | Execute next line (step into) |
| `print variable` | Print variable value |
| `continue` | Continue execution |
| `quit` | Exit GDB |

**Using AddressSanitizer**

AddressSanitizer detects memory errors at runtime.

```bash
gcc -g -fsanitize=address -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```
This will automatically detect:

- Buffer overflows

- Use after free

- Memory leaks

- Double free


## ![Resoures](https://img.shields.io/badge/Resources-B19CD9?style=flat-square)

**References used:**

- [ft_printf Subject (v12.0)]() - Official project subject

- [Learn-C.org](https://www.learn-c.org/) - Interactive C tutorial.

- [Make Tutorial](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) - Makefiles tutorial.

- [C Reference Manual](https://en.cppreference.com/w/c) - Complete C reference documentation.
  
- [Hardfloat](https://hardfloat.es/blog/2021/11/05/funciones-variadicas.html) - Blog with useful explanations about variadic functions in spanish.

- [GeeksforGeeks - C Programming](https://www.geeksforgeeks.org/c-programming-language/) - C tutorials and examples. Specifically [variadic functions](https://www.geeksforgeeks.org/c/variadic-functions-in-c/).

- [Stack Overflow](https://stackoverflow.com/questions) - Community for resolving specific queries.

</sub>

<sub>**Use of AI**</sub>

<sub>During the development of this project artificial intelligence has been used as a **learning support tool**, not as a shortcut. Similar to consulting a book or asking a classmate, AI has been used to:</sub>


<sub>- Understand concepts that were not clear in the documentation.</sub>

<sub>- Obtain guidance on what to study.</sub>

<sub>- Improve the presentation of documentation.</sub>

<sub>- Understand error messages from the terminal.</sub>

<sub>However, **the entire process of reasoning, implementation, and debugging has been manual**, ensuring the development of essential skills for the rest of the 42 curriculum and for taking exams without external dependencies.</sub>

<sub>**Educational Use:**</sub>


<sub>- **README Aesthetics:** Visual design, badges, markdown formatting, and documentation structure.</sub>

<sub>- **Resource Guidance:** Advice on which resources, documentation, and tutorials to look for to learn specific concepts.</sub>

<sub>- **Definitions for notes:** Creation of clear and concise definitions of programming concepts for my personal notes.</sub>

<sub>- **Debugging tips:** Suggestions on debugging tools and methodologies (Valgrind, GDB, etc.)</sub>


<sub>**Not used for:**</sub>


<sub>- **Code generation:** All function code has been written manually without AI assistance.

<sub>- **Exercise solving:** Algorithms and logic have been developed independently.

<sub>- **Direct copying of solutions:** AI-generated answers have not been used to implement functions.