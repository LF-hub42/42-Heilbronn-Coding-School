
````markdown
*This project has been created as part of the 42 curriculum by ekypraio.*

# 🧙 FuncMage

## Description

FuncMage is a Python project from the 42 curriculum focused on functional
programming.

After working with Python fundamentals, Object-Oriented Programming, exception
handling, collections, packages and data validation, this project introduces a
different way of thinking about functions.

The project uses a fantasy theme where functions become "spells" and gradually
introduces:

- Lambda expressions
- Higher-order functions
- Lexical scoping
- Closures
- `functools`
- `reduce`
- Partial functions
- Memoization
- Single dispatch
- Decorators
- `staticmethod`

The project contains five exercises, each focusing on a different part of
functional programming.

## Instructions

The project uses **Python 3.10+**.

The code must follow the `flake8` coding standard and all function signatures
and return types must use type hints.

Each exercise is placed in its own file with the name specified by the subject.

Exception handling should protect data from corruption and the implementations
should focus on demonstrating the functional programming concepts clearly.

### Authorized Imports

The subject allows:

- `typing`
- `collections.abc` for `Callable`
- `itertools`
- `functools` where specified
- `operator` where specified
- Standard Python classes and collections
- Standard built-in functions

The following are not allowed:

```text
eval()
exec()
```

External libraries are not allowed.

File I/O is also not part of the project. The focus is on in-memory data
processing.

Global variables are forbidden.

## 🧙 Exercise 0 — Lambda Sanctum

**File:** `lambda_spells.py`

The first exercise introduces **lambda expressions**.

The goal is to use anonymous functions for simple transformations instead of
creating unnecessary named functions.

The exercise works with magical artifacts, mages and spells.

### `artifact_sorter()`

```python
def artifact_sorter(artifacts: list[dict]) -> list[dict]
```

Sorts artifacts by their `power` value in descending order.

Each artifact contains:

```python
{
    "name": str,
    "power": int,
    "type": str
}
```

The sorting must use `sorted()` together with a lambda expression.

### `power_filter()`

```python
def power_filter(mages: list[dict], min_power: int) -> list[dict]
```

Filters mages based on their power level.

Only mages with a power greater than or equal to `min_power` should remain.

The exercise requires `filter()` with a lambda expression.

### `spell_transformer()`

```python
def spell_transformer(spells: list[str]) -> list[str]
```

Transforms spell names by adding:

```text
*
```

before the spell and:

```text
 *
```

after it.

The transformation must use `map()` with a lambda expression.

### `mage_stats()`

```python
def mage_stats(mages: list[dict]) -> dict
```

Calculates:

- Maximum power
- Minimum power
- Average power

The average is rounded to two decimal places.

The result has the following structure:

```python
{
    "max_power": int,
    "min_power": int,
    "avg_power": float
}
```

### Example

```text
Testing artifact sorter...
Fire Staff (92 power) comes before Crystal Orb (85 power)

Testing spell transformer...
* fireball * * heal * * shield *
```

The main question of this exercise is when a lambda makes code more concise
and when a regular function is easier to understand.

## ✨ Exercise 1 — Higher Realm

**File:** `higher_magic.py`

The second exercise introduces **higher-order functions**.

In Python, functions are first-class citizens. This means they can be:

- Passed as arguments
- Returned from other functions
- Stored in variables
- Combined with other functions

Every spell follows the same basic contract:

```python
def spell(target: str, power: int) -> str
```

### `spell_combiner()`

```python
def spell_combiner(spell1: Callable, spell2: Callable) -> Callable
```

Combines two spells into a new function.

Both spells receive the same arguments and the combined function returns both
results as a tuple.

### `power_amplifier()`

```python
def power_amplifier(base_spell: Callable, multiplier: int) -> Callable
```

Creates a new spell that multiplies the given power before calling the original
spell.

For example:

```python
mega_fireball = power_amplifier(fireball, 3)
```

### `conditional_caster()`

```python
def conditional_caster(condition: Callable, spell: Callable) -> Callable
```

Creates a spell that only executes when the condition is true.

If the condition fails, it returns:

```text
Spell fizzled
```

Both the condition and the spell receive the same arguments.

### `spell_sequence()`

```python
def spell_sequence(spells: list[Callable]) -> Callable
```

Creates a new function that executes all supplied spells in order.

Each spell receives the same arguments and the results are returned as a list.

### Example

```text
Testing spell combiner...
Combined spell result: Fireball hits Dragon, Heals Dragon

Testing power amplifier...
Original: 10, Amplified: 30
```

This exercise demonstrates how higher-order functions make it possible to
reuse and compose existing behaviour.

## 🔮 Exercise 2 — Memory Depths

**File:** `scope_mysteries.py`

The third exercise focuses on **lexical scoping and closures**.

A closure allows a function to remember values from the environment where it was
created, even after that surrounding function has finished executing.

The exercise demonstrates how functions can maintain their own state without
using global variables.

### `mage_counter()`

```python
def mage_counter() -> Callable
```

Creates a counter closure.

Each call returns the current count, starting at `1`.

Separate counters must maintain separate states.

### `spell_accumulator()`

```python
def spell_accumulator(initial_power: int) -> Callable
```

Creates a function that accumulates power.

Each call adds a new amount to the stored total and returns the new total.

The accumulator starts with `initial_power`.

### `enchantment_factory()`

```python
def enchantment_factory(enchantment_type: str) -> Callable
```

Creates an enchantment function.

The returned function receives an item name and returns:

```text
enchantment_type item_name
```

For example:

```text
Flaming Sword
Frozen Shield
```

Different factories can therefore create functions with different enchantment
types.

### `memory_vault()`

```python
def memory_vault() -> dict[str, Callable]
```

Creates a small memory system using a closure.

It returns a dictionary containing:

```text
store
recall
```

`store` saves a key-value pair.

`recall` returns the stored value or:

```text
Memory not found
```

The actual memory is kept privately inside the closure.

### Example

```text
Testing mage counter...
counter_a call 1: 1
counter_a call 2: 2
counter_b call 1: 1

Testing spell accumulator...
Base 100, add 20: 120
Base 100, add 30: 150

Testing enchantment factory...
Flaming Sword
Frozen Shield

Testing memory vault...
Store 'secret' = 42
Recall 'secret': 42
Recall 'unknown': Memory not found
```

This exercise demonstrates how closures can preserve state without relying on
global variables.

## 📚 Exercise 3 — Ancient Library

**File:** `functools_artifacts.py`

The fourth exercise introduces the `functools` and `operator` modules.

The main concepts are:

- `functools.reduce`
- `functools.partial`
- `functools.lru_cache`
- `functools.singledispatch`
- `operator`

### `spell_reducer()`

```python
def spell_reducer(spells: list[int], operation: str) -> int
```

Reduces a list of spell powers into a single value.

The supported operations are:

```text
add
multiply
max
min
```

The implementation uses `functools.reduce()` together with functions from the
`operator` module.

If the list is empty, the function returns `0`.

Unknown operations should be handled properly.

### `partial_enchanter()`

```python
def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]
```

Uses `functools.partial` to create three specialized versions of a base
enchantment function.

Each version pre-fills:

```text
power = 50
```

and a different element.

### `memoized_fibonacci()`

```python
def memoized_fibonacci(n: int) -> int
```

Calculates Fibonacci numbers using:

```python
functools.lru_cache
```

The cache avoids recalculating values that have already been computed.

The cache can be inspected using:

```python
memoized_fibonacci.cache_info()
```

### `spell_dispatcher()`

```python
def spell_dispatcher() -> Callable[[Any], str]
```

Creates a single-dispatch spell system using:

```python
functools.singledispatch
```

Different input types receive different behaviour:

- `int` → damage spell
- `str` → enchantment
- `list` → multi-cast
- Unknown types → default behaviour

### Example

```text
Testing spell reducer...
Sum: 100
Product: 240000
Max: 40

Testing memoized fibonacci...
Fib(0): 0
Fib(1): 1
Fib(10): 55
Fib(15): 610

Testing spell dispatcher...
Damage spell: 42 damage
Enchantment: fireball
Multi-cast: 3 spells
Unknown spell type
```

This exercise shows how `functools` provides tools for composing, optimizing
and dispatching functions.

## 🏰 Exercise 4 — Master's Tower

**File:** `decorator_mastery.py`

The final exercise introduces **decorators** and class methods.

Decorators wrap existing functions and allow their behaviour to be extended
without changing the original function itself.

The exercise also introduces `@staticmethod`.

### `spell_timer()`

```python
def spell_timer(func: Callable) -> Callable
```

Creates a decorator that measures how long a function takes to execute.

Before execution it prints:

```text
Casting function_name...
```

After execution it prints the execution time with three decimal places:

```text
Spell completed in X.XXX seconds
```

The decorator uses:

```python
functools.wraps
```

to preserve the original function metadata.

### `power_validator()`

```python
def power_validator(min_power: int) -> Callable
```

Creates a parameterized decorator that validates a spell's power.

If the power is greater than or equal to the minimum required power, the
original function runs normally.

Otherwise it returns:

```text
Insufficient power for this spell
```

The decorator also uses `functools.wraps`.

### `retry_spell()`

```python
def retry_spell(max_attempts: int) -> Callable
```

Creates a decorator that retries a failed spell.

If the decorated function raises an exception, it is retried until the maximum
number of attempts is reached.

During the retries it prints:

```text
Spell failed, retrying... (attempt n/max_attempts)
```

If every attempt fails, the final result is:

```text
Spell casting failed after max_attempts attempts
```

If an attempt succeeds, its result is returned normally.

### `MageGuild`

The exercise also introduces a class called:

```python
class MageGuild:
```

It contains the static method:

```python
@staticmethod
def validate_mage_name(name: str) -> bool
```

A valid mage name must:

- Contain at least 3 characters
- Contain only letters and spaces

The class also contains:

```python
def cast_spell(self, spell_name: str, power: int) -> str
```

`cast_spell()` uses the `power_validator` decorator with a minimum power of
`10`.

When the power is sufficient, it returns:

```text
Successfully cast spell_name with <power> power
```

Otherwise:

```text
Insufficient power for this spell
```

### Example

```text
Testing spell timer...
Casting fireball...
Spell completed in 0.101 seconds
Result: Fireball cast!

Testing retrying spell...
Spell failed, retrying... (attempt 1/3)
Spell failed, retrying... (attempt 2/3)
Spell casting failed after 3 attempts

Testing MageGuild...
True
False
Successfully cast Lightning with 15 power
Insufficient power for this spell
```

## 🧠 What I Learned

This project was the biggest step so far into functional programming with
Python.

During the exercises I worked with:

- Lambda expressions
- `map()`
- `filter()`
- `sorted()`
- Higher-order functions
- Functions as first-class objects
- Closures
- Lexical scoping
- `nonlocal`
- `functools.reduce()`
- `functools.partial()`
- `functools.lru_cache()`
- `functools.singledispatch`
- Decorators
- `functools.wraps`
- `staticmethod`
- `Callable`
- Function composition
- Memoization

The main idea behind the project is that functions can be treated like data.

They can be passed around, stored, returned from other functions and modified
through wrappers.

Closures also showed how a function can keep access to variables from the scope
where it was created.

Decorators take this one step further by allowing additional behaviour to be
added around an existing function without changing its original implementation.

## 🔧 Technical Focus

### Lambda Expressions

Lambda expressions are useful for short, simple functions that are needed
locally, especially when working with functions such as `map()`, `filter()` or
`sorted()`.

### Higher-Order Functions

A higher-order function either receives another function as an argument or
returns a function.

This allows existing behaviour to be combined and reused.

### Closures

Closures allow returned functions to remember values from their creation
environment.

This makes it possible to keep private state without global variables.

### `functools`

The `functools` module provides several tools for functional programming.

In this project I worked with:

- `reduce`
- `partial`
- `lru_cache`
- `singledispatch`
- `wraps`

### Decorators

Decorators wrap functions and add behaviour around them.

This is useful for separating concerns such as:

- Timing
- Validation
- Retrying failed operations

The original function can remain focused on its actual task.

## 🛠️ Development

I worked through the project step by step, starting with simple lambda
expressions and gradually moving towards higher-order functions and closures.

The last two exercises then introduced more advanced functional programming
tools through `functools` and decorators.

Each exercise builds on the previous Python knowledge and focuses more on
understanding why these functional programming patterns are useful rather than
just implementing them.

## 📚 Resources

- 42 FuncMage subject
- Python 3 documentation
- `functools` documentation
- `operator` documentation
- `collections.abc`
- `typing`
- `flake8`
- `mypy`
- `data_generator.py` provided with the project
- Personal testing and experimentation

## 🤖 AI Usage

The project was developed through independent work, research, and peer learning. AI was used afterwards as a supporting tool for final review and README preparation. The implementation and project logic were written and understood by me.
````
