*This project has been created as part of the 42 curriculum by ekypraio.*

# 🌱 Python Module 00

## 📌 Description

Python Module 00 is an introductory project focused on learning the basic
building blocks of Python.

The exercises use a community garden theme to introduce Python syntax and
semantics step by step. Starting with simple functions and output, the module
gradually introduces input, variables, calculations, conditions, loops,
recursion, and type annotations.

The project contains 8 exercises, from `ex0` to `ex7`.

## Instructions

The project uses **Python 3.10+**.

Each exercise has to be placed in its own file and should contain only the
requested function.

A `main.py` helper is provided to test the exercises. It imports the functions
automatically and can be used to test individual exercises or all exercises.

### Testing

```bash
python3 main.py
```

The code should also respect **flake8** standards.

For exercises 0 to 6, type hints are optional. For exercise 7, type hints are
required and can be checked using `mypy`.

## 🌱 Exercises

### Exercise 0 — Hello Garden

`ft_hello_garden`

The first exercise introduces Python functions and `print()`.

The function displays:

```text
Hello, Garden Community!
```

### Exercise 1 — Garden Name

`ft_garden_name`

The function asks the user for a garden name and then displays the entered name
together with the fixed message:

```text
Status: Growing well!
```

This exercise introduces `input()` and basic string handling.

### Exercise 2 — Garden Plot Area

`ft_plot_area`

The function asks for the length and width of a rectangular garden plot and
calculates its area.

This exercise introduces integer conversion with `int()` and basic arithmetic.

### Exercise 3 — Harvest Total

`ft_harvest_total`

The function asks for the harvest weight from three different days and calculates
the total harvest.

This exercise focuses on variables, input, integer conversion, and calculations.

### Exercise 4 — Plant Age Check

`ft_plant_age`

The function asks for the age of a plant in days and checks whether it is ready
to harvest.

A plant is ready when it is **strictly more than 60 days** old.

Depending on the result, the function displays either:

```text
Plant is ready to harvest!
```

or:

```text
Plant needs more time to grow.
```

### Exercise 5 — Water Reminder

`ft_water_reminder`

The function asks how many days have passed since the plants were last watered.

If more than 2 days have passed, it displays:

```text
Water the plants!
```

Otherwise:

```text
Plants are fine
```

### Exercise 6 — Count to Harvest

`ft_count_harvest_iterative`
`ft_count_harvest_recursive`

This exercise implements the same task in two different ways.

The iterative version uses a loop to count from 1 to the given number.

The recursive version uses recursion to produce the same output.

Both functions should finish with:

```text
Harvest time!
```

The recursive version can use a nested helper function, default parameters,
or a separate helper function.

### Exercise 7 — Seed Inventory

`ft_seed_inventory`

The final exercise introduces type annotations.

The required function signature is:

```python
def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
```

The function supports three units:

- `packets`
- `grams`
- `area`

The seed type is displayed with its first letter capitalized.

For example:

```text
Tomato seeds: 15 packets available
Carrot seeds: 8 grams total
Lettuce seeds: covers 12 square meters
```

For an unsupported unit, the function only displays:

```text
Unknown unit type
```

## 🧠 What I Learned

This module gave me my first structured introduction to Python.

During the exercises I worked with:

- Functions
- Variables
- `input()` and `print()`
- Integer conversion
- Arithmetic operations
- `if` / `else` conditions
- Loops and `range()`
- Recursion
- String methods
- Type annotations
- Basic testing with imports
- `flake8`
- `mypy`

The exercises build on each other, starting with very simple functions and
gradually introducing more Python concepts.

## 🔧 Project Rules

The main rules of the project are:

- Python 3.10+
- Each exercise in its own file
- Function names must match the subject exactly
- Each file should contain only the requested function
- No `main` program inside the exercise files
- No direct function calls inside the submitted files
- Code should respect flake8 standards
- Type hints are optional for exercises 0 to 6
- Type hints are required for exercise 7

Input validation and error handling are not required unless explicitly mentioned
in the exercise.

## 🛠️ Development

I worked through the exercises step by step, starting with basic Python syntax
and gradually moving towards conditions, loops, recursion, and type annotations.

The provided `main.py` helper was used to test the functions without adding a
main program to the individual exercise files.

The project was developed using Python 3.

## 📚 Resources

- 42 Python Module 00 subject
- Python 3 documentation
- `flake8`
- `mypy`
- Provided `main.py` testing helper
- Personal testing and experimentation

## 🤖 AI Usage

The project was developed through independent work, research, and peer learning. AI was used afterwards as a supporting tool for final review and README preparation.
