
````markdown
*This project has been created as part of the 42 curriculum by ekypraio.*

# 🃏 DataDeck

## Description

DataDeck is a Python project from the 42 curriculum focused on advanced
Object-Oriented Programming and design patterns.

The project uses a creature-based card game to build a modular system that can
handle different types of Creatures, capabilities, and battle strategies.

The main goal is to create a flexible architecture that can be extended with
new Creature families and behaviours without having to rewrite the existing
battle system.

The project focuses on:

- Abstract classes
- Abstract Factory Pattern
- Multiple inheritance
- Capabilities
- Polymorphism
- Strategy Pattern
- Type annotations
- Modular and reusable architecture

## Instructions

The project uses **Python 3.10+**.

The code must follow the `flake8` coding standard and all code must include
comprehensive type annotations.

`mypy` can be used to check the type annotations.

External libraries are not allowed.

The project is divided into three exercises:

```text
ex0/
ex1/
ex2/
```

Each exercise folder must contain an `__init__.py` file.

The testing scripts are located at the root of the repository.

The exercises build on each other, so the content from previous exercises is
used in the following ones.

## 🧬 Exercise 0 — Creature Factory

The first exercise introduces the **Abstract Factory Pattern**.

The goal is to create different Creature families while keeping the creation
logic separate from the actual Creature classes.

### Creature

An abstract `Creature` class contains:

- The Creature name
- The Creature type
- An abstract `attack()` method
- A concrete `describe()` method

Four concrete Creatures are implemented:

- `Flameling`
- `Pyrodon`
- `Aquabub`
- `Torragon`

Each Creature has its own attack behaviour.

### CreatureFactory

An abstract `CreatureFactory` is responsible for creating the base and evolved
Creature of a family.

Two concrete factories are implemented:

- `FlameFactory`
- `AquaFactory`

`FlameFactory` creates:

```text
Flameling
Pyrodon
```

`AquaFactory` creates:

```text
Aquabub
Torragon
```

The `ex0` package exposes the factories rather than the concrete Creature
classes.

### Testing

The root `battle.py` script creates both factories and tests:

- Base Creature creation
- Evolved Creature creation
- Creature descriptions
- Creature attacks
- A basic battle between two Creatures

Example:

```text
$> python3 battle.py
Testing factory
Flameling is a Fire type Creature
Flameling uses Ember!
Pyrodon is a Fire/Flying type Creature
Pyrodon uses Flamethrower!

Testing factory
Aquabub is a Water type Creature
Aquabub uses Water Gun!
Torragon is a Water type Creature
Torragon uses Hydro Pump!

Testing battle
Flameling is a Fire type Creature
vs.
Aquabub is a Water type Creature
fight!
Flameling uses Ember!
Aquabub uses Water Gun!
```

## ✨ Exercise 1 — Capabilities

The second exercise adds extra capabilities to the Creature system.

Instead of putting every possible behaviour directly into the `Creature`
hierarchy, capabilities are kept as separate abstract classes.

Two capability interfaces are introduced:

- `HealCapability`
- `TransformCapability`

### HealCapability

`HealCapability` defines an abstract:

```python
heal()
```

method.

Two Creatures use this capability:

- `Sproutling`
- `Bloomelle`

They form a single family and are created through:

```text
HealingCreatureFactory
```

### TransformCapability

`TransformCapability` defines:

```python
transform()
revert()
```

and maintains a persistent transformation state.

Two Creatures use this capability:

- `Shiftling`
- `Morphagon`

They form a single family and are created through:

```text
TransformCreatureFactory
```

The transformation state also changes how the Creature attacks.

### Testing

The root `capacitor.py` script tests both capability types.

For healing Creatures:

```text
Sproutling is a Grass type Creature
Sproutling uses Vine Whip!
Sproutling heals itself for a small amount
```

For transforming Creatures, the attack behaviour changes after
transformation:

```text
Shiftling attacks normally.
Shiftling shifts into a sharper form!
Shiftling performs a boosted strike!
Shiftling returns to normal.
```

The exercise continues to use the factories from Exercise 0 and extends the
existing architecture instead of replacing it.

## 🏆 Exercise 2 — Abstract Strategy

The final exercise introduces the **Strategy Pattern** and uses it to build a
Creature tournament.

The problem is that different Creatures can have different capabilities and
therefore different ways of fighting.

Instead of making the tournament code directly aware of every capability, the
battle behaviour is moved into separate strategies.

### BattleStrategy

An abstract `BattleStrategy` defines:

```python
act()
is_valid()
```

The `is_valid()` method determines whether a strategy can be used with a
specific Creature.

The `act()` method performs the actual battle behaviour.

Three concrete strategies are implemented:

### NormalStrategy

Works with any Creature.

It simply calls the Creature's `attack()` method.

### AggressiveStrategy

Works with Creatures that have transformation capabilities.

The battle sequence is:

```text
transform
attack
revert
```

### DefensiveStrategy

Works with Creatures that have healing capabilities.

The battle sequence is:

```text
attack
heal
```

If a strategy is used with an incompatible Creature,
`is_valid()` returns `False`.

Calling `act()` with an invalid combination raises a dedicated exception with a
clear error message.

## 🏟️ Tournament

The root `tournament.py` script brings everything together.

A tournament opponent is represented by a tuple containing:

```text
CreatureFactory
BattleStrategy
```

The tournament:

- Creates different Creature factories
- Creates the three strategies
- Receives a list of opponents
- Makes every opponent fight the others
- Uses the strategy associated with each opponent
- Handles invalid Creature-strategy combinations

Example:

```text
Tournament 0 (basic)
[ (Flameling+Normal), (Healing+Defensive) ]

*** Tournament ***
2 opponents involved

* Battle *
Flameling is a Fire type Creature
vs.
Sproutling is a Grass type Creature
now fight!

Flameling uses Ember!
Sproutling uses Vine Whip!
Sproutling heals itself for a small amount
```

An invalid combination is also tested:

```text
Tournament 1 (error)

Battle error, aborting tournament:
Invalid Creature 'Flameling' for this aggressive strategy
```

The final tournament demonstrates how different Creature families and
strategies can work together without putting all battle logic into one large
function.

## 🧠 What I Learned

This project took the Object-Oriented Programming concepts from the previous
Python modules and introduced more advanced design patterns.

During the project I worked with:

- Abstract classes
- Abstract methods
- Abstract factories
- Inheritance
- Multiple inheritance
- Polymorphism
- Capabilities
- Strategy Pattern
- Type annotations
- Modular architecture
- Separation of responsibilities
- Reusable and extensible code

The biggest part of the project was understanding how to separate behaviour
from the objects that use it.

Instead of making one large Creature class responsible for every possible
action, capabilities and strategies allow different behaviours to be added
without changing the whole architecture.

## 🔧 Technical Focus

### Abstract Factory Pattern

The factory pattern separates the creation of Creatures from the Creature
classes themselves.

A factory can create a family of related Creatures while the rest of the
program only needs to work with the factory interface.

### Capabilities

Capabilities are kept separate from the main Creature hierarchy.

This allows a Creature to have additional behaviour such as healing or
transformation without forcing every Creature to implement those methods.

### Multiple Inheritance

Some Creatures inherit from both `Creature` and a capability class.

For example:

```text
Sproutling
├── Creature
└── HealCapability
```

This allows the Creature to keep the common Creature interface while also
providing the additional capability.

### Strategy Pattern

The Strategy Pattern moves battle behaviour into separate strategy classes.

The tournament does not need to know how a Creature fights. It simply uses the
strategy associated with that Creature.

This makes it easier to add new battle strategies later without changing the
main tournament logic.

## 🛠️ Development

I worked through the project step by step.

Exercise 0 established the Creature and factory architecture.

Exercise 1 extended this architecture with independent capabilities such as
healing and transformation.

Exercise 2 then separated battle behaviour from the Creatures using the
Strategy Pattern and used the previous factories and capabilities to build a
complete tournament system.

The exercises build directly on each other, which made it possible to see how a
small object-oriented system can be extended without having to redesign the
whole project.

## 📚 Resources

- 42 DataDeck subject
- Python 3 documentation
- Python `abc` module
- Python `typing` module
- Abstract Factory Pattern
- Strategy Pattern
- `flake8`
- `mypy`
- Personal testing and experimentation

## 🤖 AI Usage

AI was used for project review and README preparation.
````
