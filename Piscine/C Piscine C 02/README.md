# C Piscine C 02

*This project has been created as part of the 42 curriculum by ekypraio.*

## Description

C 02 focused on working with strings and character manipulation in C.

The exercises involved recreating common string operations and checking
or modifying characters without relying on standard library functions.

This repository contains the exercises I completed during my Piscine.

## Exercises

### ex00: ft_strcpy

Created a function that copies a string into another string.

```c
char *ft_strcpy(char *dest, char *src);
```

**Focus:** Strings, pointers and copying data.

### ex01: ft_strncpy

Created a function that copies a limited number of characters.

```c
char *ft_strncpy(char *dest, char *src, unsigned int n);
```

**Focus:** Limited string copying and indexing.

### ex02: ft_str_is_alpha

Checks whether a string contains only alphabetic characters.

```c
int ft_str_is_alpha(char *str);
```

**Focus:** Character validation.

### ex03: ft_str_is_numeric

Checks whether a string contains only numeric characters.

```c
int ft_str_is_numeric(char *str);
```

**Focus:** Digits and character ranges.

### ex04: ft_str_is_lowercase

Checks whether a string contains only lowercase letters.

```c
int ft_str_is_lowercase(char *str);
```

**Focus:** Lowercase character validation.

### ex05: ft_str_is_uppercase

Checks whether a string contains only uppercase letters.

```c
int ft_str_is_uppercase(char *str);
```

**Focus:** Uppercase character validation.

### ex06: ft_str_is_printable

Checks whether every character in a string is printable.

```c
int ft_str_is_printable(char *str);
```

**Focus:** ASCII values and printable characters.

### ex07: ft_strupcase

Converts lowercase letters in a string to uppercase.

```c
char *ft_strupcase(char *str);
```

**Focus:** Character conversion and ASCII.

### ex08: ft_strlowcase

Converts uppercase letters in a string to lowercase.

```c
char *ft_strlowcase(char *str);
```

**Focus:** Character conversion and ASCII.

### ex09: ft_strcapitalize

Capitalizes words in a string according to the exercise rules.

```c
char *ft_strcapitalize(char *str);
```

**Focus:** String traversal, word detection and character conversion.

## What I Learned

During C 02 I learned how to:

- manipulate strings using pointers
- copy strings without library functions
- work with ASCII character ranges
- validate different types of characters
- convert between uppercase and lowercase
- traverse and modify strings in place
- combine conditions and loops for text processing

These exercises improved my understanding of how strings are represented
and manipulated in C.

## Technical Focus

- C
- Strings
- Pointers
- ASCII
- Character validation
- Character conversion
- String manipulation

## Resources

- C manual pages
- 42 subject
- Peer learning

## 🤖 AI Usage

These solutions are from my original Piscine work. AI was only used afterwards as a supporting tool for project review and GitHub documentation.
