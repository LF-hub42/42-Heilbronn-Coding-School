# C Piscine C 03

*This project has been created as part of the 42 curriculum by ekypraio.*

## Description

C 03 continued working with strings in C.

The exercises focused on comparing, joining and searching strings while
recreating the behavior of common C library functions.

This repository contains the exercises I completed during my Piscine.

## Exercises

### ex00: ft_strcmp

Created a function that compares two strings.

```c
int ft_strcmp(char *s1, char *s2);
```

**Focus:** String comparison and character values.

### ex01: ft_strncmp

Created a function that compares two strings up to a given length.

```c
int ft_strncmp(char *s1, char *s2, unsigned int n);
```

**Focus:** Limited string comparison.

### ex02: ft_strcat

Created a function that appends one string to another.

```c
char *ft_strcat(char *dest, char *src);
```

**Focus:** String traversal and concatenation.

### ex03: ft_strncat

Created a function that appends a limited number of characters from
one string to another.

```c
char *ft_strncat(char *dest, char *src, unsigned int nb);
```

**Focus:** Limited string concatenation.

### ex04: ft_strstr

Created a function that searches for a substring inside another string.

```c
char *ft_strstr(char *str, char *to_find);
```

**Focus:** Substring searching and pointer traversal.

### ex05: ft_strlcat

Implemented the behavior required by the exercise for `strlcat`.

```c
unsigned int ft_strlcat(
    char *dest,
    char *src,
    unsigned int size
);
```

**Focus:** String concatenation, buffer size and return values.

## What I Learned

During C 03 I learned how to:

- compare strings character by character
- work with limited string operations
- concatenate strings
- search for substrings
- navigate strings using indexes and pointers
- recreate common C library behavior
- think about buffer sizes during string operations

These exercises strengthened the string manipulation skills introduced
in C 02.

## Technical Focus

- C
- Strings
- Pointers
- String comparison
- String concatenation
- Substring searching
- Buffer sizes

## Resources

- C manual pages
- 42 subject
- Peer learning

## 🤖 AI Usage

These solutions are from my original Piscine work. AI was only used afterwards as a supporting tool for project review and GitHub documentation.
