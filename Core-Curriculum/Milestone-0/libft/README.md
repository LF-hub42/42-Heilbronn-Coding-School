*This project has been created as part of the 42 curriculum by ekypraio.*

# 🧩 Libft

> My first C library — 42 Heilbronn

## 📖 About

Libft is one of the first projects of the 42 curriculum.

The goal of the project is to create my own C library containing functions that are commonly used when working with characters, strings, memory, numbers, and file descriptors.

Instead of relying on existing implementations, I recreated these functions using basic C concepts such as loops, pointers, memory allocation, and string manipulation.

Libft was an important introduction to the way commonly used C functions work internally and provided a foundation for the projects that follow in the 42 curriculum.

## 🎯 Project Goals

The main goals of the project were to:

- Understand how commonly used C functions work internally
- Work confidently with pointers and pointer arithmetic
- Manage dynamically allocated memory
- Manipulate strings and character arrays
- Understand different integer and unsigned types
- Build and use a static library
- Follow the 42 coding standard and Norminette requirements

## 🧰 Functions

The library contains implementations of the functions required by the Libft subject.

### Character Checks

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is alphabetic |
| `ft_isdigit` | Checks whether a character is a digit |
| `ft_isalnum` | Checks whether a character is alphanumeric |
| `ft_isascii` | Checks whether a character belongs to the ASCII range |
| `ft_isprint` | Checks whether a character is printable |

### String Functions

| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a string |
| `ft_strchr` | Searches for a character in a string |
| `ft_strrchr` | Searches for a character from the end of a string |
| `ft_strncmp` | Compares two strings up to a given length |
| `ft_strnstr` | Searches for a string inside another string |
| `ft_strdup` | Creates a duplicate of a string |
| `ft_strlcpy` | Copies a string with size limitation |
| `ft_strlcat` | Appends a string with size limitation |
| `ft_substr` | Creates a substring |
| `ft_strjoin` | Joins two strings |
| `ft_strtrim` | Removes specified characters from the beginning and end |
| `ft_split` | Splits a string into an array of strings |

### Memory Functions

| Function | Description |
|---|---|
| `ft_memset` | Fills a memory area with a byte value |
| `ft_bzero` | Sets a memory area to zero |
| `ft_memcpy` | Copies a memory area |
| `ft_memmove` | Copies a memory area while handling overlapping regions |
| `ft_memchr` | Searches for a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_calloc` | Allocates and initializes memory |

### Conversion Functions

| Function | Description |
|---|---|
| `ft_atoi` | Converts a string to an integer |
| `ft_itoa` | Converts an integer to a string |
| `ft_tolower` | Converts a character to lowercase |
| `ft_toupper` | Converts a character to uppercase |

### File Descriptor Functions

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Function Pointer Based Functions

| Function | Description |
|---|---|
| `ft_strmapi` | Creates a new string by applying a function to each character |
| `ft_striteri` | Applies a function to each character and allows modification |

## 🛠️ Compilation

The project includes a Makefile with the following rules.

### Build

Run `make` to compile the library.

The resulting static library is:

`libft.a`

### Clean object files

Run `make clean` to remove the generated object files.

### Remove all generated files

Run `make fclean` to remove the generated object files and the static library.

### Recompile

Run `make re` to clean and rebuild the library.

## 🧪 Testing

The implementation was tested during development using individual tests and external Libft testers.

The project was also checked against the 42 requirements, including compilation with:

`-Wall -Wextra -Werror`

and Norminette compliance.

## 📚 What I Learned

Working on Libft gave me a better understanding of several fundamental C concepts:

- Pointers and pointer arithmetic
- `void *` and type casting
- Dynamic memory allocation with `malloc`
- Memory initialization
- Strings and character arrays
- `size_t` and memory sizes
- ASCII values
- Integer and unsigned types
- Handling negative numbers
- Checking allocation failures
- Function pointers
- Working with file descriptors
- Building a static library with `ar`

One important part of the project was learning to work directly with memory instead of treating library functions as black boxes.

For example, `ft_bzero` accesses the provided memory byte by byte and sets each byte to zero.

`ft_calloc` builds on this concept by allocating memory and then initializing the allocated area.

## 📁 Project Structure

    libft/
    ├── Makefile
    ├── libft.h
    ├── README.md
    ├── Libft.en.subject.pdf
    ├── .gitignore
    └── ft_*.c

## 📄 Subject

The original project subject is included in the repository:

`Libft.en.subject.pdf`

## 🤖 AI Usage

AI was used for project review and README preparation.

---

*42 Heilbronn — Common Core*
