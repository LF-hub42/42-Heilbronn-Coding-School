*This project has been created as part of the 42 curriculum by ekypraio.*

# ft_printf

## Description

`ft_printf` is a C project from the 42 curriculum.

The goal is to recreate the core behaviour of `printf` using a variadic
function. The implementation reads the format string, detects conversion
specifiers, retrieves the corresponding arguments with `va_arg`, and writes
the formatted result to standard output.

The project builds a static library named `libftprintf.a`.

The implemented conversions are:

| Specifier | Behaviour |
|---|---|
| `%c` | Prints a character |
| `%s` | Prints a string, or `(null)` for a null string |
| `%p` | Prints a pointer address in hexadecimal with a `0x` prefix |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal integer in lowercase |
| `%X` | Prints an unsigned hexadecimal integer in uppercase |
| `%%` | Prints a percent sign |

## Instructions

Build the static library with:

```bash
make
```

The available Makefile rules are:

```bash
make clean
make fclean
make re
```

To use the library in another C program, include `ft_printf.h` and link the
generated archive:

```bash
cc your_program.c -L. -lftprintf
```

## What I Learned

This project helped me practise:

- Variadic functions with `va_list`
- Parsing format strings
- Handling different argument types
- Recursive number conversion
- Decimal and hexadecimal output
- Pointer representation
- Counting the number of printed characters
- Building a static library with a Makefile

## Technical Choices

The main `ft_printf` function scans the format string one character at a time.
When it finds `%`, the following character is passed to a format handler.

Output is written with `write()` through small helper functions. Separate
helpers are used for characters, strings, signed numbers, unsigned numbers,
hexadecimal numbers, and pointers.

Decimal and hexadecimal numbers are printed recursively. The hexadecimal
helper selects the lowercase, uppercase, or decimal digit base according to
the requested conversion.

Null strings are printed as `(null)`, while null pointers are printed as
`(nil)`.

## Development

The project is organised as a small static library:

```text
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_putchar_fd.c
├── ft_putnbr.c
├── ft_putnbr_x.c
├── ft_putptr.c
├── ft_putstr_fd.c
├── ft_strchr.c
└── ft_strlen.c
```

The Makefile compiles the source files with:

```text
-Wall -Wextra -Werror
```

## Resources

- The 42 `ft_printf` subject
- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- C documentation for variadic functions and formatted output

## 🤖 AI Usage

AI was used for project review and README preparation.
