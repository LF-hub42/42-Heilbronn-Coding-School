
```markdown
*This project has been created as part of the 42 curriculum by ekypraio.*

# 🌌 Cosmic Data

## Description

Cosmic Data is a Python project from the 42 curriculum focused on data
validation with **Pydantic**.

The project takes place in the Cosmic Data Observatory, where incoming data
from space missions, alien contact reports, and station monitoring systems
needs to be validated before it can be processed.

The project starts with basic Pydantic models and gradually introduces more
advanced validation rules and nested data structures.

The main focus is on:

- Pydantic models
- Data validation
- Type conversion
- Custom validation
- Nested models
- Complex data structures
- Data integrity

## Instructions

The project uses **Python** together with the Pydantic library.

The exercises build on each other and introduce Pydantic concepts step by step.

Pydantic can automatically convert compatible input types and provides
detailed validation errors when invalid data is supplied.

This makes it useful for applications where incoming data needs to be checked
before it is processed further.

## 🌌 Exercises

### Exercise 0 — Space Station Data

The first exercise introduces the basic concepts of Pydantic data validation.

The scenario is based around **Space Station Data** and focuses on creating
basic validated data models.

The goal is to make sure that incoming station information follows the
expected structure and data types.

This exercise introduces the foundation for working with Pydantic models.

### Exercise 1 — Alien Contact Logs

The second exercise focuses on **Alien Contact Logs**.

The validation becomes more specific and introduces custom validation rules
and logic.

Instead of only checking basic data types, the model can also enforce rules
that are specific to the data being processed.

This demonstrates how Pydantic can be used for domain-specific validation.

### Exercise 2 — Space Crew Management

The final exercise focuses on **Space Crew Management**.

This part introduces nested models and more complex relationships between
different pieces of data.

Instead of working with completely independent values, multiple validated
models can be combined into a larger structure.

This makes it possible to represent more realistic data while keeping
validation inside the models.

## 🧠 What I Learned

This project introduced me to Pydantic and showed how data validation can be
built directly into Python models.

During the project I worked with:

- Pydantic models
- Field validation
- Automatic type conversion
- Validation errors
- Custom validation rules
- Nested models
- Structured data
- Data integrity
- Type-based validation

One of the useful things about Pydantic is that compatible input values can be
converted automatically.

For example, values that arrive in a different but compatible format can be
converted to the expected Python type during validation.

At the same time, invalid data produces structured validation errors instead
of silently being accepted.

## 🔧 Technical Focus

### Pydantic Models

Pydantic models provide a structured way to define what data an object should
contain and which types are expected.

Instead of manually checking every value, validation can be handled by the
model.

### Data Validation

Validation ensures that incoming data matches the expected structure and
rules.

This is especially useful when data comes from external sources such as APIs,
files, sensors, or other systems.

### Automatic Type Conversion

Pydantic can automatically convert compatible values into the expected Python
types.

This makes it easier to work with data coming from different sources while
still keeping the final model strongly structured.

### Custom Validation

Basic type checking is not always enough.

The project also introduces custom validation rules so that data can be
checked against requirements specific to the application.

### Nested Models

The final exercise introduces nested structures.

A model can contain other models, allowing more complex relationships to be
represented while keeping validation organized.

## 🛠️ Development

I worked through the project step by step, starting with basic Pydantic
models and validation and then moving towards custom rules and nested
structures.

The project shows how validation can move from simple type checking towards
more complete data integrity rules.

The space-themed exercises make it possible to work with increasingly complex
data while keeping the focus on understanding how Pydantic handles that data.

## 📚 Resources

- 42 Cosmic Data subject
- Pydantic documentation
- Python 3 documentation
- Personal testing and experimentation

## 🤖 AI Usage

The project was developed through independent work, research, and peer learning. AI was used afterwards as a supporting tool for final review and README preparation. The implementation and project logic were written and understood by me.
```
