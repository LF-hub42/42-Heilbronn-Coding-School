

````markdown
*This project has been created as part of the 42 curriculum by ekypraio.*

# 🧪 The Codex

## Description

The Codex is a Python project from the 42 curriculum focused on understanding
how Python imports and packages work.

The project uses an alchemist laboratory as a theme and builds a small Python
package step by step.

The main goal is not complex program logic, but understanding how different
modules and packages can access each other.

The project focuses on four main topics:

- Package initialization with `__init__.py`
- Different import styles
- Absolute and relative imports
- Circular dependencies

The project gradually builds a package structure called `alchemy` and uses
small test scripts to demonstrate how Python resolves imports.

## Instructions

The project uses **Python 3.10+**.

The code must follow the `flake8` coding standard and all code must include
comprehensive type annotations.

`mypy` can be used to check the type annotations.

Standard Python classes and collections are allowed, as well as their methods.

The project allows imports of the modules and files created within the project.

The following built-in functions are authorized, except:

```python
eval()
exec()
```

Modifying `sys.path` is not allowed.

The exercises are designed around import mechanisms, so the functions themselves
are intentionally simple and mainly return strings.

## 📁 Project Structure

The project builds the following package structure:

```text
.
├── alchemy
│   ├── __init__.py
│   ├── elements.py
│   ├── grimoire
│   │   ├── __init__.py
│   │   ├── dark_spellbook.py
│   │   ├── dark_validator.py
│   │   ├── light_spellbook.py
│   │   └── light_validator.py
│   ├── potions.py
│   └── transmutation
│       ├── __init__.py
│       └── recipes.py
├── elements.py
├── ft_alembic_0.py
├── ft_alembic_1.py
├── ft_alembic_2.py
├── ft_alembic_3.py
├── ft_alembic_4.py
├── ft_alembic_5.py
├── ft_distillation_0.py
├── ft_distillation_1.py
├── ft_kaboom_0.py
├── ft_kaboom_1.py
├── ft_transmutation_0.py
├── ft_transmutation_1.py
└── ft_transmutation_2.py
```

## 🧪 Part I — The Alembic

The first part introduces the basic Python import mechanisms.

The project starts with two `elements.py` files.

The root `elements.py` contains:

- `create_fire()`
- `create_water()`

The `alchemy/elements.py` file contains:

- `create_earth()`
- `create_air()`

The different test scripts demonstrate several ways of importing these
functions.

### `ft_alembic_0.py`

Uses:

```python
import ...
```

to access the root `elements.py` and create the fire element.

### `ft_alembic_1.py`

Uses:

```python
from ... import ...
```

to access the root `elements.py` and create the water element.

### `ft_alembic_2.py`

Uses:

```python
import ...
```

to access `alchemy/elements.py` and create the earth element.

### `ft_alembic_3.py`

Uses:

```python
from ... import ...
```

to access `alchemy/elements.py` and create the air element.

### `ft_alembic_4.py`

Uses:

```python
import alchemy
```

to access the package.

The `__init__.py` file controls which functions are exposed through the
package interface.

`create_air()` is available, while `create_earth()` is intentionally hidden
and therefore raises an exception when accessed through the package.

This exercise also intentionally produces a `mypy` error.

### `ft_alembic_5.py`

Uses:

```python
from alchemy import ...
```

to access the `alchemy` package and create the air element.

Example:

```text
$> python3 ft_alembic_0.py
=== Alembic 0 ===
Using: 'import ...' structure to access elements.py
Testing create_fire: Fire element created

$> python3 ft_alembic_1.py
=== Alembic 1 ===
Using: 'from ... import ...' structure to access elements.py
Testing create_water: Water element created
```

## ⚗️ Part II — Distillation

The second part introduces imports between different levels of the package.

A new file is added:

```text
alchemy/potions.py
```

It contains two functions:

- `healing_potion()`
- `strength_potion()`

The healing potion uses the earth and air elements.

The strength potion uses the fire and water elements.

### `ft_distillation_0.py`

Uses:

```python
from ... import ...
```

to access `alchemy/potions.py` directly and brew both potions.

### `ft_distillation_1.py`

Uses:

```python
import alchemy
```

to access the package.

The `__init__.py` file is updated so that the package exposes the required
potion functions, including `heal` as an alias for `healing_potion`.

Example:

```text
$> python3 ft_distillation_0.py
=== Distillation 0 ===
Direct access to alchemy/potions.py
Testing strength_potion: Strength potion brewed with 'Fire element created' and 'Water element created'
Testing healing_potion: Healing potion brewed with 'Earth element created' and 'Air element created'
```

## 🔮 Part III — The Great Transmutation

The third part focuses on the difference between **absolute and relative
imports**.

A new package is added:

```text
alchemy/transmutation/
```

with:

```text
__init__.py
recipes.py
```

The `recipes.py` file contains:

```python
lead_to_gold()
```

This function combines the air element, the strength potion and the fire
element to create the final transmutation recipe.

The file must demonstrate both:

- An absolute import
- A relative import

Three test scripts are used.

### `ft_transmutation_0.py`

Directly imports:

```text
alchemy/transmutation/recipes.py
```

and performs the transformation.

### `ft_transmutation_1.py`

Imports the `transmutation` module directly and performs the same
transformation.

### `ft_transmutation_2.py`

Imports only the `alchemy` module and reaches the transmutation functionality
through the package.

The three scripts demonstrate that different import paths can reach the same
functionality.

## 💥 Part IV — Avoid the Explosion

The final part deals with **circular dependencies**.

Two different spell systems are created:

```text
alchemy/grimoire/light_spellbook.py
alchemy/grimoire/light_validator.py

alchemy/grimoire/dark_spellbook.py
alchemy/grimoire/dark_validator.py
```

### Light Magic

The light spellbook allows these ingredients:

```text
earth
air
fire
water
```

The validator checks whether the provided ingredients contain at least one
allowed ingredient, without being case-sensitive.

The spell can then be recorded as either valid or invalid.

### Dark Magic

The dark spellbook uses:

```text
bats
frogs
arsenic
eyeball
```

The dark spellbook and validator intentionally create a circular dependency.

### `ft_kaboom_0.py`

Accesses the grimoire and records a light spell.

The circular dependency is avoided using one possible solution.

Example:

```text
$> python3 ft_kaboom_0.py
=== Kaboom 0 ===
Using grimoire module directly
Testing record light spell: Spell recorded: Fantasy (Earth, wind and fire - VALID)
```

### `ft_kaboom_1.py`

Directly accesses:

```text
alchemy/grimoire/dark_spellbook.py
```

The import causes a circular dependency between the dark spellbook and the
dark validator.

The program therefore raises an `ImportError`.

Example:

```text
$> python3 ft_kaboom_1.py
=== Kaboom 1 ===
Access to alchemy/grimoire/dark_spellbook.py directly
Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION

ImportError: cannot import name 'dark_spell_allowed_ingredients'
from partially initialized module 'alchemy.grimoire.dark_spellbook'
```

## 🧠 What I Learned

This project helped me understand how Python organizes and connects different
modules and packages.

The main concepts I worked with were:

- `import`
- `from ... import ...`
- Packages
- Modules
- `__init__.py`
- Absolute imports
- Relative imports
- Nested packages
- Package interfaces
- Import paths
- Circular dependencies
- Type annotations
- `mypy`
- `flake8`

The biggest part for me was understanding that importing a module is not just
about finding a file. Python follows the package structure and the imports
defined inside the different modules.

The project also showed why circular dependencies can become a problem.

If module A needs module B while module B simultaneously needs module A, Python
can end up trying to use a module that has not finished initializing yet.

## 🔧 Technical Focus

### `__init__.py`

The `__init__.py` files are used to define and control package behaviour.

They can expose selected functions so that users can access them directly
through the package instead of importing the underlying module.

### Absolute Imports

Absolute imports describe the full path from the package structure.

They are useful when the location of the imported module should be explicit.

### Relative Imports

Relative imports refer to modules based on their position inside the current
package.

They can make relationships between modules inside the same package clearer.

### Method of Avoiding Circular Dependencies

The light magic system demonstrates that circular dependencies can be avoided
by restructuring how modules access each other.

The dark magic system intentionally keeps the circular dependency so that the
resulting `ImportError` can be observed and understood.

## 🛠️ Development

I worked through the project step by step.

The first part introduced simple imports and package initialization. The second
part connected multiple modules together through nested imports.

The third part focused on absolute versus relative imports, while the final
part demonstrated what happens when modules depend on each other in a circular
way.

The project is intentionally built around simple functions and strings so that
the main focus stays on understanding Python's import system rather than
complex application logic.

## 📚 Resources

- 42 The Codex subject
- Python 3 documentation
- Python `abc` and `typing` concepts
- `flake8`
- `mypy`
- Personal testing and experimentation

## 🤖 AI Usage

AI was used during the project to help clarify Python import concepts and to
structure this README.

The project itself was reviewed and tested, and the import mechanisms and
package structure were understood before being used or explained.

````

**Beispiel:** Der wichtigste Punkt für die Evaluation bei diesem Projekt ist nicht nur, dass `import` funktioniert, sondern dass du **`__init__.py`, `import` vs. `from ... import ...`, absolute vs. relative Imports und den Circular-Import bei `dark_spellbook` erklären kannst** – genau darauf weist auch das Subject bei der Abgabe/Evaluation hin.
