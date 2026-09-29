*This project has been created as part of the 42 core curriculum by Eleftherios Kypraios, ekypraio.*

# ✨ Push_swap

## 📌 Description

Push_swap is an algorithmic project from the 42 core curriculum.

The goal is to sort a disordered list of integers in Stack A using a second
stack, Stack B, and a limited set of operations.

The main focus of the project is to find an efficient way to sort the numbers
while keeping the number of operations as low as possible.

## Algorithm

For this project, I implemented **Radix Sort**.

### Why Radix Sort?

I chose Radix Sort because it performs predictably well with larger data sets,
especially with 100 to 500 numbers.

Instead of directly comparing the numbers, the algorithm processes them based
on their individual bits.

### Indexing

Before sorting, the input values are converted into positive indexes ranging
from `0` to `N-1`.

This normalization makes it possible to use the bitwise logic of Radix Sort
while still supporting negative numbers and large integer ranges.

The basic idea is:

```text
Input numbers
      |
      v
Normalize / Index
      |
      v
Positive ranks
      |
      v
Process individual bits
      |
      v
Stack operations
      |
      v
Sorted Stack A
```

## 🛠️ Instructions

### Compilation

Use the provided Makefile to compile the program:

```bash
make
```

### Execution

Run the program with a list of integers:

```bash
./push_swap 42 1 5 10 -3
```

The program outputs the stack operations required to sort the numbers.

### Testing with the Checker

The result can be checked using the school's provided checker:

```bash
ARG="3 0 1"; ./push_swap $ARG | ./checker_OS $ARG
```

## 🏗️ Technical Choices

### Doubly Linked List

Each element stores a pointer to both the next and previous element.

This makes operations such as rotations (`ra` and `rra`) efficient because the
stack can be accessed from both directions.

### Error Handling

The input parsing checks for invalid input, including:

- Non-integer values
- Duplicate numbers
- Integer overflows
- Values outside the `int` range

When an invalid input is detected, the program outputs:

```text
Error
```

to the standard error.

### Memory Management

The project uses a central `free_stack` function to release allocated memory.

This keeps the cleanup in one place and also makes it possible to free the stack
correctly when an error occurs.

The goal was to keep the program free of memory leaks.

## 🧠 What I Learned

Push_swap helped me understand how algorithms and data structures can be combined
to solve a problem under strict constraints.

During the project I worked with:

- Stack manipulation
- Doubly linked lists
- Sorting algorithms
- Radix Sort
- Bitwise operations
- Index normalization
- Input parsing
- Error handling
- Dynamic memory management
- Algorithm efficiency

The main challenge was finding a way to sort the numbers efficiently while only
being allowed to use the operations provided by the project.

## 📚 Resources

### Sources & Videos

- [Radix Sort Tutorial](https://www.youtube.com/watch?v=XiuSW_mEn7g) — Explanation of the basic Radix Sort and bitwise logic
- [Oceano Push_swap Guide](https://www.youtube.com/watch?v=OaG81sDEpVk) — Project structure and stack manipulation
- Wikipedia — Radix Sort theory, complexity, and implementation concepts

## 🤖 AI Usage

AI was used for project review and README preparation.
