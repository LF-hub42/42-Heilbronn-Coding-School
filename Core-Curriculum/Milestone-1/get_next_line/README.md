*This project has been created as part of the 42 curriculum by ekypraio.*

# 📖 get_next_line

> Reading a file descriptor one line at a time — 42 Heilbronn

## Description

get_next_line is a C project from the 42 curriculum.

The goal of the project is to implement a function that reads and returns one
line at a time from a file descriptor.

The function can be called repeatedly and keeps track of unread data between
calls.

The main challenge is that `read()` works with a fixed buffer size and does
not know anything about lines. Depending on the `BUFFER_SIZE`, one call to
`read()` may contain only part of a line, exactly one line, or parts of several
lines.

My implementation solves this by storing unread data between calls and
processing it until the next complete line is available.

The project focuses on:

- File descriptors
- `read()`
- Static variables
- Dynamic memory allocation
- Buffer handling
- String manipulation
- Memory management
- Error handling

## Instructions

The mandatory implementation consists of:

    get_next_line.c
    get_next_line_utils.c
    get_next_line.h

The function prototype is:

    char *get_next_line(int fd);

The project can be compiled with different `BUFFER_SIZE` values.

For example:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test

Then run:

    ./gnl_test

The implementation also provides a default `BUFFER_SIZE` when no value is
specified during compilation.

Different values can therefore be tested, for example:

    -D BUFFER_SIZE=1
    -D BUFFER_SIZE=42
    -D BUFFER_SIZE=99
    -D BUFFER_SIZE=1000

Each call to `get_next_line()` returns the next available line.

If a newline exists, the terminating `\n` is included in the returned string.

If the end of the file is reached and the final line does not contain a
newline, the remaining characters are returned as the final line.

If there is nothing left to read or an error occurs, the function returns
`NULL`.

## 📁 Project Structure

    .
    ├── get_next_line.c
    ├── get_next_line.h
    ├── get_next_line_utils.c
    ├── README.md
    ├── test_get_next_line.c
    └── test.txt

The three `get_next_line` source/header files contain the mandatory
implementation.

`test_get_next_line.c` and `test.txt` are development files used to test the
function.

The mandatory implementation intentionally does not contain a `main()`
function. The separate `test_get_next_line.c` file provides the `main()` used
for local testing and peer evaluation.

## 🔄 Algorithm

The implementation separates the work into three main steps:

    read_to_storage()
           ↓
    extract_line()
           ↓
    update_storage()

This approach was chosen because each step has one clear responsibility:
reading data, extracting the current line, and preserving the remaining data
for the next call.

### 1. Reading into storage

`read_to_storage()` receives the file descriptor and the current storage.

A temporary buffer of:

    BUFFER_SIZE + 1

bytes is allocated.

The additional byte is required for the terminating null character.

The function repeatedly calls:

    read(fd, buffer, BUFFER_SIZE);

After every successful read, the buffer is terminated with `\0` and appended
to the existing storage.

Reading continues until:

- a newline is found in the storage, or
- `read()` reaches the end of the file.

This means the function does not intentionally read the entire file before
returning a line. It stops once enough data is available to produce the next
line.

### 2. Extracting the line

`extract_line()` starts at the beginning of the storage and searches for the
first newline.

It calculates the required size and allocates a new string for the line.

Characters are copied until either:

- `\n` is reached, or
- the end of the storage is reached.

If a newline exists, it is included in the returned string.

For example, if storage contains:

    Hello\nWorld\n

the current call returns:

    Hello\n

The remaining part must stay available for the next call.

### 3. Updating the storage

After the current line has been extracted, `update_storage()` finds the first
newline in the old storage.

Everything before and including that newline has already been returned.

A new storage is therefore created containing only the characters after the
newline.

For example:

    Before:
    Hello\nWorld\n

After returning `Hello\n`:

    World\n

The old storage is freed after the remaining data has been preserved.

If there is no remaining data, the storage is freed and becomes `NULL`.

## 💾 Static Storage

The central part of the implementation is the static storage used by
`get_next_line()`.

    static char *storage;

A static variable keeps its value between function calls.

This is necessary because one call to `read()` may retrieve more data than is
needed for the current line.

For example, a read could retrieve:

    Line 1\nLine 2\n

The current call must return only:

    Line 1\n

The remaining:

    Line 2\n

must still exist when `get_next_line()` is called again.

Using static storage allows this unread data to survive after the current
function call returns without using a global variable.

## 🧩 Utility Functions

### `ft_strlen()`

Calculates the length of a string.

The implementation also handles a `NULL` pointer by returning `0`.

### `ft_strchr()`

Searches for a character inside a string.

It is mainly used to determine whether the current storage already contains a
newline.

For example:

    ft_strchr(storage, '\n');

### `ft_strjoin()`

Appends newly read data to the existing storage.

This allows data from several calls to `read()` to be combined when a line is
larger than the selected `BUFFER_SIZE`.

### `update_storage()`

Creates the storage required for the next call to `get_next_line()`.

It removes the line that has already been returned and preserves only the
remaining unread characters.

## ⚠️ Error Handling

The implementation checks for an invalid file descriptor and invalid
`BUFFER_SIZE` values.

If:

    fd < 0

or:

    BUFFER_SIZE <= 0

the function returns `NULL`.

Errors returned by `read()` are also handled.

If `read()` returns `-1`, allocated memory associated with the current read is
freed before returning `NULL`.

Allocation failures are also checked to avoid continuing with invalid
pointers.

## 🧪 Testing

The implementation can be tested using `test_get_next_line.c` together with
`test.txt`.

The test program provides a separate `main()`, opens the text file, repeatedly
calls `get_next_line()`, prints every returned line, frees it, and continues
until the function returns `NULL`.

The following commands provide a quick testing procedure for local testing and
peer evaluation.

### 1. Norminette

Check the mandatory source files:

    norminette get_next_line.c get_next_line_utils.c get_next_line.h

The mandatory files should pass Norminette.

### 2. Compile

Compile the mandatory implementation together with the local test program:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test

### 3. Run

Run the test program:

    ./gnl_test

The program reads from `test.txt`.

Each call to `get_next_line()` should return exactly one line until the end of
the file is reached.

After there is no more data to read, `get_next_line()` returns `NULL`.

### 4. Test Different BUFFER_SIZE Values

BUFFER_SIZE = 1:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test && ./gnl_test

BUFFER_SIZE = 2:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test && ./gnl_test

BUFFER_SIZE = 10:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test && ./gnl_test

BUFFER_SIZE = 42:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test && ./gnl_test

BUFFER_SIZE = 99:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=99 get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test && ./gnl_test

BUFFER_SIZE = 1000:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test && ./gnl_test

### 5. Important Edge Cases

Relevant test cases include:

- Empty file
- One-character file
- One line ending with `\n`
- One line without a final `\n`
- Multiple lines
- Empty lines
- File containing only `\n`
- Very long lines
- Invalid file descriptor
- End of file
- Repeated calls until `NULL`
- Standard input
- Very small `BUFFER_SIZE`
- Large `BUFFER_SIZE`

Testing different `BUFFER_SIZE` values is particularly important because the
boundaries between individual calls to `read()` change.

A line may therefore require several reads, or one read may already contain
data belonging to the following line.

### 6. Memory Check

Compile the test program:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test

Run it with Valgrind:

    valgrind --leak-check=full --show-leak-kinds=all ./gnl_test

Check the output for:

- Memory leaks
- Invalid reads
- Invalid writes
- Double frees
- Other Valgrind errors

### Quick Evaluation Commands

For a fast evaluation, the main checks can be copied in this order:

    norminette get_next_line.c get_next_line_utils.c get_next_line.h

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c test_get_next_line.c -o gnl_test

    ./gnl_test

    valgrind --leak-check=full --show-leak-kinds=all ./gnl_test

`main()` is intentionally located only in `test_get_next_line.c`. It is a
testing tool and is not part of the mandatory get_next_line implementation.

## 🧠 What I Learned

This project helped me understand how `read()` works with file descriptors and
why reading a file line by line requires keeping track of data between
function calls.

The most important concept was the use of static variables.

I also gained more experience with:

- Pointers
- Static variables
- `malloc()` and `free()`
- File descriptors
- Buffer sizes
- String manipulation
- Memory lifetime
- Error handling

## 🔧 Technical Choices

### Static storage

Static storage was chosen because unread data must survive between calls to
`get_next_line()`.

A normal local variable would disappear when the function returns, while a
global variable is not permitted by the project requirements.

### Separation of responsibilities

The implementation separates the main operations into different functions:

    read_to_storage()
    extract_line()
    update_storage()

This makes the flow easier to understand and allows each function to handle
one specific part of the algorithm.

### Custom utility functions

The project does not use Libft.

Instead, the small set of string operations required by the implementation is
provided directly in `get_next_line_utils.c`.

These include:

    ft_strlen()
    ft_strchr()
    ft_strjoin()

## 📚 Resources

Resources used while learning and working on the project:

- 42 get_next_line subject
- Linux manual page for `read()`
- Documentation for `malloc()`
- Documentation for `free()`
- C documentation about static variables
- 42 peer evaluations
- Personal testing and debugging

Useful manual pages can also be opened directly from a terminal:

    man 2 read
    man 3 malloc
    man 3 free

## 🤖 AI Usage

AI was used as a learning and support tool to help clarify concepts such as:

- File descriptors
- The behavior of `read()`
- Static storage
- Buffer handling
- Memory lifetime
- Testing strategies

AI was also used to help structure and format this README and to review the
project requirements.

---

42 Heilbronn — Common Core
