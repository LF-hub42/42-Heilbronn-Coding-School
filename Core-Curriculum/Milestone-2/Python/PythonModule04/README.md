

````markdown
*This project has been created as part of the 42 curriculum by ekypraio.*

# 🗄️ Data Archivist

## Description

Data Archivist is a Python project from the 42 curriculum focused on file
operations and data management.

The project is set in the context of the Cyber Archives, where digital
information needs to be recovered, transformed, stored, and protected.

The exercises gradually introduce different ways of working with files,
handling errors, managing data streams, and safely opening and closing files.

The main focus of the project is:

- File operations
- Reading and writing files
- Exception handling
- Standard input and output streams
- Standard error output
- File descriptors
- Context managers
- The `with` statement
- Type hints

## Instructions

The project uses **Python 3.10+**.

The code must follow the `flake8` standards and all functions and methods must
include type hints.

`mypy` can be used to check the type hints.

The project is divided into four exercises:

```text
ex0/
ex1/
ex2/
ex3/
```

Only the files requested by the subject should be submitted.

### Important

The `with` statement is introduced in **Exercise 3** and must not be used
before that exercise.

The standard Python types and collections allowed by the subject include:

- `str`
- `int`
- `float`
- `list`
- `dict`
- `set`
- `tuple`

## 📂 Exercises

### Exercise 0 — Ancient Text Recovery

`ft_ancient_text`

The first exercise introduces basic file reading.

The program receives a filename from the command line and displays the contents
of the file, similar to the `cat` command.

It also needs to handle different failure cases, such as files that do not
exist or files that cannot be accessed.

The exercise uses:

- `sys.argv`
- `open()`
- `read()`
- `close()`
- `print()`
- Basic exception handling

Example:

```bash
python3 ft_ancient_text.py ancient_fragment.txt
```

The program reads the archive fragment, displays its contents, and closes the
file afterwards.

### Exercise 1 — Archive Creation

`ft_archive_creation`

The second exercise builds directly on the previous one.

After reading the original file, each line is transformed by adding the `#`
character at the end.

The transformed content is displayed and the user is asked whether it should be
saved to a new file.

If a filename is provided, the file is created or replaced with the transformed
content.

This exercise introduces:

- Reading file contents
- Transforming strings
- Writing to files
- `input()`
- Creating or replacing files
- Handling file errors

Example:

```text
Transform data:
---
[FRAGMENT 001] Digital preservation protocols established 2087#
[FRAGMENT 002] Knowledge must survive the entropy wars#
[FRAGMENT 003] Every byte saved is a victory against oblivion#
---
Enter new file name (or empty): new_fragment.txt
Saving data to 'new_fragment.txt'
Data saved in file 'new_fragment.txt'.
```

### Exercise 2 — Stream Management

`ft_stream_management`

This exercise introduces Python's standard streams.

Instead of using the `input()` built-in function, user input is read from
`sys.stdin`.

Error messages are no longer printed to the standard output. They are sent to
the standard error stream using `sys.stderr`.

The exercise works with:

- `sys.stdin`
- `sys.stdout`
- `sys.stderr`
- `readline()`
- `write()`
- `flush()`

This makes the program's input, normal output, and error output more clearly
separated.

Example:

```text
[STDERR] Error opening file 'foo': [Errno 2] No such file or directory: 'foo'
```

### Exercise 3 — Vault Security

`ft_vault_security`

The final exercise introduces the `with` statement and context managers.

A function called:

```python
secure_archive()
```

provides safe access to a file for reading or writing.

The function returns a tuple containing:

```text
(True | False, content_or_error_message)
```

The boolean indicates whether the operation was successful, while the string
contains either the file content or an error message.

The function supports:

- Reading a file
- Writing content to a file
- Handling nonexistent files
- Handling inaccessible files
- Automatically closing files

The important addition in this exercise is the use of a context manager:

```python
with open(...) as file:
    ...
```

This ensures that the file is properly closed even when an error occurs.

## 🧠 What I Learned

This project helped me understand how Python works with files and data streams
in a more practical way.

During the exercises I worked with:

- Opening files
- Reading file contents
- Writing data
- Closing files
- Command-line arguments
- `sys.stdin`
- `sys.stdout`
- `sys.stderr`
- Exception handling
- File permissions and access errors
- Context managers
- The `with` statement
- Type hints
- `flake8`
- `mypy`

The project also showed the difference between normal program output and error
output.

The biggest step was moving from manually opening and closing files to using
the `with` statement, which handles the cleanup automatically.

## 🔧 Technical Focus

### File Operations

The first exercises work directly with `open()`, `read()`, `write()`, and
`close()`.

This makes it possible to read existing archive data, transform it, and create
new files.

### Standard Streams

Exercise 2 introduces the three standard streams:

- `stdin` — receives input
- `stdout` — normal program output
- `stderr` — error messages

Keeping these streams separate makes command-line programs easier to use and
allows errors to be handled independently from normal output.

### Context Manager

Exercise 3 introduces the `with` statement.

A context manager takes care of closing the file automatically after the block
has finished, including when an exception occurs.

This makes file handling safer and helps prevent resource leaks.

## 🛠️ Development

I worked through the project step by step, starting with basic file reading and
then adding writing, stream management, and finally safe file handling with
context managers.

Each exercise builds on the previous one, so the project gradually moves from
simple file operations towards a safer and more structured way of working with
files.

The project was developed using Python 3.

## 📚 Resources

- 42 Data Archivist subject
- Python 3 documentation
- `flake8`
- `mypy`
- Personal testing and experimentation

## 🤖 AI Usage

AI was used during the project to help clarify Python concepts and to structure
this README.

The code and concepts were reviewed and understood before being used in the
project.
````
