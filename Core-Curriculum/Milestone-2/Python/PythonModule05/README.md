

````markdown
*This project has been created as part of the 42 curriculum by ekypraio.*

# 🧬 Code Nexus

## Description

Code Nexus is a Python project from the 42 curriculum focused on advanced
Object-Oriented Programming.

The project introduces abstract classes, inheritance, method overriding and
polymorphism. The goal is to build a system where different types of data can
be processed through a common interface while keeping their own specific
behaviour.

The project uses a digital data stream scenario where different processors
handle different kinds of data.

The main concepts are:

- Abstract classes
- Inheritance
- Method overriding
- Polymorphism
- Type annotations
- Data processing
- Processing pipelines
- Protocols
- Duck typing

## Instructions

The project uses **Python 3.10+**.

The code must follow the `flake8` coding standard and all code must include
type annotations.

`mypy` can be used to check the type annotations.

The authorized imports are:

- `abc`
- `typing`

Standard Python classes, collections and built-in functions are also allowed.

The project is divided into three exercises:

```text
ex0/
ex1/
ex2/
```

## 🧬 Exercises

### Exercise 0 — Data Processor

`data_processor.py`

The first exercise builds the foundation of the data processing system.

An abstract base class called `DataProcessor` defines the common interface for
different types of processors.

Three specialized processors inherit from it:

- `NumericProcessor`
- `TextProcessor`
- `LogProcessor`

`DataProcessor` provides two abstract methods:

```python
validate(self, data: Any) -> bool
ingest(self, data: Any) -> None
```

It also provides the common:

```python
output(self) -> tuple[int, str]
```

method.

Each specialized processor overrides the required methods and handles its own
type of data.

### NumericProcessor

`NumericProcessor` accepts:

- `int`
- `float`
- Lists containing these types
- Mixed lists of integers and floats

The values are converted to strings and stored internally.

### TextProcessor

`TextProcessor` accepts:

- `str`
- Lists of strings

The data is stored internally until it is extracted using `output()`.

### LogProcessor

`LogProcessor` accepts dictionaries containing string key-value pairs and
lists of these dictionaries.

The log information is converted into strings and stored internally.

### Output

The `output()` method retrieves the oldest stored piece of data together with
its processing rank.

After being extracted, the item is removed from the processor.

The exercise also tests valid and invalid data and verifies that an exception
is raised when invalid data is passed to `ingest()` without being validated
first.

Example:

```text
=== Code Nexus - Data Processor ===
Testing Numeric Processor...
Trying to validate input '42': True
Trying to validate input 'Hello': False
Test invalid ingestion of string 'foo' without prior validation:
Got exception: Improper numeric data
Processing data: [1, 2, 3, 4, 5]
Extracting 3 values...
Numeric value 0: 1
Numeric value 1: 2
Numeric value 2: 3
```

### Exercise 1 — Polymorphic Processing of a Data Stream

`data_stream.py`

The second exercise builds on the processors from Exercise 0.

A new `DataStream` class is introduced to handle a stream containing different
types of data.

Processors can be registered using:

```python
register_processor(self, proc: DataProcessor) -> None
```

The stream is processed using:

```python
process_stream(self, stream: list[typing.Any]) -> None
```

For every element in the stream, `DataStream` checks the registered processors
and sends the data to the processor that can handle it.

If no processor can handle an element, an error message is displayed.

The class also provides:

```python
print_processors_stats(self) -> None
```

to display statistics about the registered processors.

This exercise demonstrates how polymorphism allows the `DataStream` to work
with different processor implementations without needing to know their
specific internal behaviour.

Example:

```text
=== Code Nexus - Data Stream ===
Initialize Data Stream...
== DataStream statistics ==
No processor found, no data
Registering Numeric Processor
```

After additional processors are registered, the same stream can contain
numeric values, text and log entries, with each type automatically routed to
the appropriate processor.

### Exercise 2 — Data Pipeline

`data_pipeline.py`

The final exercise extends the `DataStream` into a complete processing
pipeline.

The output side of the pipeline is implemented using a plugin system.

An `ExportPlugin` class is created using the `Protocol` type. It defines the
interface that compatible export plugins have to provide:

```python
process_output(self, data: list[tuple[int, str]]) -> None
```

The `DataStream` receives an export plugin through:

```python
output_pipeline(self, nb: int, plugin: ExportPlugin) -> None
```

This method consumes data from all registered processors and sends the results
to the selected export plugin.

Two export plugins are implemented:

- CSV
- JSON

The CSV and JSON output is created manually without using specific imports for
these formats.

Example:

```text
=== Code Nexus - Data Pipeline ===
Initialize Data Stream...
== DataStream statistics ==
No processor found, no data
Registering Processors
```

The pipeline can then process multiple batches of data and export the results
in different formats.

Example CSV output:

```text
3.14,-1,2.71
Hello world,Hi,five
WARNING: Telnet access! Use ssh instead,INFO: User wil is connected
```

Example JSON output:

```text
{"item_3": "42", "item_4": "21", "item_5": "32", "item_6": "42", "item_7": "64"}
```

## 🧠 What I Learned

This project took the Object-Oriented Programming concepts from the previous
modules and pushed them further.

During the project I worked with:

- Abstract Base Classes
- Inheritance
- Abstract methods
- Method overriding
- Polymorphism
- Type annotations
- `typing.Any`
- `Protocol`
- Duck typing
- Data processing pipelines
- Plugin-style architecture

The main concept for me was understanding how different classes can share the
same interface while still implementing their own behaviour.

For example, `NumericProcessor`, `TextProcessor` and `LogProcessor` all inherit
from `DataProcessor`, but each one knows how to validate and process its own
kind of data.

The `DataStream` does not need to know the internal implementation of each
processor. It can work with them through the common interface.

## 🔧 Technical Focus

### Abstract Classes

`DataProcessor` acts as the common base class for all processors.

It defines the methods that every processor has to provide while also providing
shared functionality such as `output()`.

### Inheritance

The specialized processors inherit from `DataProcessor`.

This avoids duplicating the common structure while allowing each processor to
implement its own validation and ingestion behaviour.

### Polymorphism

Polymorphism allows the `DataStream` to work with different processors through
the same interface.

The stream can send an element to a processor without having to know exactly
how that processor handles the data internally.

### Method Overriding

Each specialized processor overrides the abstract methods from
`DataProcessor`.

The same method names can therefore have different behaviour depending on the
processor receiving the data.

### Protocols and Duck Typing

Exercise 2 introduces `Protocol` for the export plugin system.

The `DataStream` does not require a specific export class. Any compatible
object implementing the required `process_output()` method can be used as a
plugin.

This makes the pipeline easier to extend with additional output formats.

## 🛠️ Development

I worked through the project step by step.

Exercise 0 established the processor architecture. Exercise 1 then connected
the different processors through a common data stream. Finally, Exercise 2
extended the system into a complete pipeline with export plugins.

Each exercise builds directly on the previous one, making the project a good
practical example of how an object-oriented design can grow without replacing
the existing architecture.

## 📚 Resources

- 42 Code Nexus subject
- Python 3 documentation
- Python `abc` module
- Python `typing` module
- `mypy`
- `flake8`
- Personal testing and experimentation

## 🤖 AI Usage

AI was used during the project to help clarify concepts such as abstract
classes, polymorphism, method overriding, `Protocol` and duck typing.

AI was also used to help structure this README.

The code and concepts were reviewed and understood before being used in the
project.
````

**Beispiel:** Genau wie bei deinen vorherigen READMEs kannst du hier den **gesamten Block einmal kopieren** und direkt als `README.md` in dein Repository einsetzen.
