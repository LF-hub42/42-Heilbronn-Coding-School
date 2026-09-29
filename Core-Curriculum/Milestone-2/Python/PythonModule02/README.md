*This project has been created as part of the 42 curriculum by ekypraio.*

# 🌿 Garden Guardian

## 📌 Description

Garden Guardian is a Python project from the 42 curriculum focused on error
handling and building more reliable programs.

The project builds on the Python fundamentals from Module 00 and the
Object-Oriented Programming concepts from Module 01.

The main focus is learning how to deal with unexpected situations instead of
letting the program crash.

The exercises use a smart agriculture scenario with sensor data, where invalid
readings, corrupted data and other problems need to be handled properly.

The project introduces:

- Exception handling
- `try` / `except`
- `finally`
- `raise`
- Built-in exceptions
- Custom exception types
- Error recovery
- Data validation
- Fault-tolerant program design

## Instructions

The project uses **Python 3.10+**.

Each exercise is placed in its own file.

All functions and methods must include type hints and the code should follow
the `flake8` standards.

`mypy` can be used to check the type hints.

The exercises are designed to demonstrate both normal operations and error
situations. Programs should handle errors properly and must not crash.

## 🌱 Exercises

### Exercise 0 — Agricultural Data Validation

`ft_first_exception`

The first exercise introduces basic exception handling.

A temperature reading is received as a string and needs to be converted into
an integer.

The function:

```python
input_temperature(temp_str)
```

takes a string, converts it to a number and returns the temperature as an
integer.

A second function:

```python
test_temperature()
```

is used to test both valid and invalid input.

The exercise tests:

- Valid input: `"25"`
- Invalid input: `"abc"`
- Handling the resulting error
- Printing an error message
- Continuing the program after the error

The expected behaviour demonstrates that an invalid sensor reading should not
stop the complete monitoring system.

Example:

```text
$> python3 ft_first_exception.py
=== Garden Temperature ===
Input data is '25'
Temperature is now 25°C
Input data is 'abc'
Caught input_temperature error: invalid literal for int() with base 10: 'abc'
All tests completed - program didn't crash!
```

The authorized functions for this exercise are:

- `int()`
- `print()`

### Exercise 1 — Agricultural Data Validation Pipeline

This exercise continues the error-handling concepts introduced in Exercise 0
and applies them to a larger agricultural data validation scenario.

The focus is on handling problems inside a data pipeline while keeping the
program running.

### Exercise 2 — Different Types of Problems

This exercise focuses on handling different kinds of errors.

Python provides several built-in exception types, and the project encourages
using the exception that matches the actual problem.

Examples include:

- `ValueError`
- `TypeError`
- `ZeroDivisionError`
- `FileNotFoundError`
- `KeyError`
- `IndexError`
- `AttributeError`
- `Exception`

### Exercise 3 — Making Your Own Error Types

This exercise introduces custom exception types.

Instead of relying only on Python's built-in exceptions, custom errors can be
created for situations that are specific to the application.

This is useful when a program needs to communicate a more specific problem,
for example an agricultural or sensor-related error.

### Exercise 4 — Finally Block - Always Clean Up

The final exercise introduces the `finally` block.

`finally` is used for code that should run regardless of whether an exception
occurred.

This is especially useful when something needs to be cleaned up after an
operation, even when the operation fails.

## 🧠 What I Learned

This project was a step towards writing Python programs that can deal with
unexpected situations more reliably.

During the exercises I worked with:

- `try`
- `except`
- `finally`
- `raise`
- Built-in exceptions
- Custom exceptions
- Error messages
- Type hints
- `mypy`
- `flake8`
- Data validation
- Fault-tolerant program design

The main idea was not simply to prevent errors, but to make sure the program
can react to them properly and continue running when possible.

## 🔧 Project Rules

The main requirements of the project are:

- Python 3.10+
- Each exercise in its own file
- All functions and methods must include type hints
- Code must respect `flake8` standards
- `mypy` can be used for type checking
- Use `try` / `except` for error handling
- Show both normal and error situations
- Use appropriate built-in exceptions
- Keep the solutions simple and focused
- Programs must not crash

The keywords `try`, `except`, `finally` and `raise` are fundamental Python
features and do not need to be listed as authorized functions.

## 🛠️ Development

I worked through the exercises step by step, starting with a simple example of
handling invalid temperature data and then moving towards different exception
types, custom errors and guaranteed cleanup.

The project builds on the Python and Object-Oriented Programming concepts from
the previous modules and puts more focus on making programs robust when
something unexpected happens.

## 📚 Resources

- 42 Garden Guardian subject
- Python 3 documentation
- `flake8`
- `mypy`
- Personal testing and experimentation

## 🤖 AI Usage

The project was developed through independent work, research, and peer learning. AI was used afterwards as a supporting tool for final review and README preparation.
