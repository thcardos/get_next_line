<div align="center">

*This project has been created as part of the 42 curriculum by thcardos*

# ![get_next_line](https://img.shields.io/badge/get_next_line-9932CC?style=for-the-badge&logo=42&logoColor=white)

</div>

## ![Description](https://img.shields.io/badge/Description-B19CD9?style=flat-square)

<sub>get_next_line is a function that returns a line read from a file descriptor. This project is part of the 42 curriculum and enables students to practise advanced C concepts such as static variables, memory management, and buffer handling.

</sub>

<sub>

| Function Prototype | Description | Parameters | Return Value |
|---------|-------------|-------------|-------------|
| char *get_next_line(int fd)|Returns a line read from a file descriptor|fd: The file descriptor to read from |Read line: correct behavior NULL: there is nothing else to read, or an error occurred|

</sub>

<sub>**Below is a detailed description of each function and its logic:** 
</sub>

<sub>**`get_next_line`** </sub>

<sub>- Main entry point of the library</sub>

<sub>- Takes a file descriptor as argument</sub>

<sub>- Uses a static variable to save the remainder of the buffer</sub>

<sub>- Returns a dynamically allocated string containing the line</sub>

<sub>- Returns NULL on error or EOF</sub>

<sub>**`find_new_line`** </sub>

<sub>- Reads from the file descriptor until a newline is found</sub>

<sub>- Uses the defined BUFFER_SIZE for reading chunks</sub>

<sub>- Appends read content to the static buffer</sub>

<sub>- Handles end of file conditions</sub>

<sub>**`split_string`** </sub>

<sub>- Handles the extraction of the line from the static buffer</sub>

<sub>- Checks for the newline character '\n'</sub>

<sub>- Manages the static variable update for the next call</sub>

<sub>- Returns the extracted line</sub>

<sub>**`handle_newline_case`**</sub>

<sub>- Processes the case when a newline is found in the buffer</sub>

<sub>- Allocates memory for the line to return</sub>

<sub>- Updates the stash with the remaining content</sub>

<sub>- Frees temporary buffers appropriately</sub>

<sub>- Duplicates a string into a newly allocated memory space</sub>

<sub>- Handles memory allocation safely</sub>

<sub>- Returns the duplicated string</sub>

<sub>**`read_to_b`**</sub>

<sub>- Reads data from the file descriptor into a buffer</sub>

<sub>- Returns the read content as a newly allocated string</sub>

<sub>- Handles read errors and EOF conditions</sub>

<sub>- Returns NULL when nothing more can be read</sub>

<sub>**`ft_strjoin`**</sub>

<sub>- Joins two strings into a newly allocated string</sub>

<sub>- Handles memory allocation safely</sub>

<sub>- Frees the temporary buffers if necessary</sub>

<sub>- Returns the concatenated string</sub>

<sub>**`ft_strlen`**</sub>

<sub>- Calculates the length of a string</sub>

<sub>- Handles NULL pointers safely</sub>

<sub>- Returns the number of characters before '\0'</sub>

<sub>**`ft_strchr`**</sub>

<sub>- Searches for a character in a string</sub>

<sub>- Returns pointer to first occurrence or NULL</sub>

<sub>- Used to find newline characters</sub>

<sub>**`ft_memcpy`**</sub>

<sub>- Copies memory from source to destination</sub>

<sub>- Handles byte-by-byte copying</sub>

<sub>- Returns the destination pointer</sub>

<sub>**Algorithm and Data Structure**</sub>

<sub>**`Static Variable for State Preservation`**</sub>

<sub>I use a static variable to store the remainder of the buffer between function calls.</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- It allows the function to remember where it left off in the file.</sub>

<sub>- It enables reading across multiple calls to get_next_line().</sub>

<sub>- It is essential for handling lines larger than BUFFER_SIZE.</sub>

<sub>- It is the core concept taught by this project.</sub>

<sub>**`Buffer Management with BUFFER_SIZE`**</sub>

<sub>I read data in chunks defined by the BUFFER_SIZE macro.</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- It optimizes memory usage by not reading the whole file at once.</sub>

<sub>- It allows flexibility for different testing environments.</sub>

<sub>- It prevents excessive memory allocation.</sub>

<sub>- It follows the project constraints.</sub>

<sub>**`Dynamic Memory Allocation`**</sub>

<sub>I use malloc to create strings for the lines returned.</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- The size of the line is unknown beforehand.</sub>

<sub>- It ensures the returned string persists after the function returns.</sub>

<sub>- It requires careful freeing to avoid memory leaks.</sub>

<sub>- It is standard practice for string manipulation in C.</sub>

<sub>**`Separating Utilities and Logic`**</sub>

<sub>I use helper functions in get_next_line_utils.c for string manipulation.</sub>

<sub><sub>**Why:**</sub></sub>

<sub>- It keeps get_next_line.c clean and focused on logic.</sub>

<sub>- It facilitates testing and debugging.</sub>

<sub>- It improves code readability and modularity.</sub>

<sub>- It follows the Norm requirements.</sub>

<sub>**`Chosen data types`**</sub>

<sub>

| Function | Type | Justification |
|--------|------|---------------|
| `get_next_line()` | `char *` | Returns a dynamically allocated string |
| `fd` | `int` | Standard file descriptor type |
| `static buffer` | `char *` | Stores remainder between calls |
| `BUFFER_SIZE` | `macro` | Defines read chunk size at compilation |

</sub>

<sub>**`Handling NULL and Errors`**</sub>

<sub>- It prevents memory access errors.</sub>

<sub>- It matches the actual behaviour of the subject:</sub>

<sub>- Returns `NULL` on error or when nothing else is to be read.</sub>

<sub>- Frees memory appropriately before returning `NULL`.</sub>


## ![Instructions](https://img.shields.io/badge/Instructions-B19CD9?style=flat-square)

<sub>

**Compilation with the library**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o test
```
</sub>

<sub>**Testing the functions:**</sub>

<sub>Here you have the [Main File](https://github.com/thcardos/get_next_line/blob/main/main.c) and the [.txt File](https://github.com/thcardos/get_next_line/blob/main/test.txt)I have created to test my functions.
</sub>


<sub>

**Memory verification with Valgrind:**
```bash
# Compile your program with the buffer size flag
cc -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o test

# Run with Valgrind
valgrind --leak-check=full ./test

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

**Using LLDB**

LLDB is the default debugger for macOS and LLVM-based systems. It provides similar functionality to GDB with a modern interface.

```bash
# Compile with debugging symbols
clang -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o test

# Start LLDB
lldb ./test
```

LLDB commands |Description
|---|---|
| b main|Set a breakpoint at main function|
| r|Execute the program|
| gui|Opens the interface|
| `n`|Execute next line (step over)|
| `s`| Execute next line (step in) |
|`c`|Continue execution|
|`h`|Shows help dialog|
|`esc`|Exit interface|
| exit|Exit LLDB|



**Using AddressSanitizer**

AddressSanitizer detects memory errors at runtime.

```bash
gcc -g -fsanitize=address -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o test
./test
```
This will automatically detect:

- Buffer overflows

- Use after free

- Memory leaks

- Double free


## ![Resoures](https://img.shields.io/badge/Resources-B19CD9?style=flat-square)

**References used:**

- [get_next_line Subject (v14.0)]() - Official project subject

- [Learn-C.org](https://www.learn-c.org/) - Interactive C tutorial.

- [C Reference Manual](https://en.cppreference.com/w/c) - Complete C reference documentation.

- [Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/) - Explanation of static variables.

- [GeeksforGeeks - C Programming](https://www.geeksforgeeks.org/c-programming-language/) - C tutorials and examples. Specifically [file handling](https://www.geeksforgeeks.org/c/basics-file-handling-c/).

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