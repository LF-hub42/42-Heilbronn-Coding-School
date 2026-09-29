````markdown
*This project has been created as part of the 42 curriculum by ekypraio.*

# 💊 The Matrix

## Description

The Matrix is a Python project from the 42 curriculum focused on the tools and
practices used to build a clean and reproducible Python development environment.

The project uses the Matrix as a theme while introducing practical concepts
that are important when working on real Python projects.

The main focus is on:

- Virtual environments
- Package management
- Dependencies
- Environment configuration
- Reproducible development environments
- Building a basic data pipeline

The project contains three exercises that gradually introduce these concepts.

## Instructions

The project uses **Python 3.10+**.

The project is divided into three exercises:

```text
ex0/
ex1/
ex2/
```

The general goal is to create an isolated Python environment, manage the
dependencies required by a project, and configure environment variables without
hard-coding configuration directly into the source code.

## 🟢 Exercise 0 — Entering the Matrix

The first exercise introduces **virtual environments**.

The goal is to create an isolated Python environment for the project.

A virtual environment keeps the project's Python packages separated from the
system-wide Python installation.

This makes it possible to install project-specific dependencies without
affecting other Python projects on the machine.

The exercise introduces the basic workflow:

```text
Create virtual environment
        ↓
Activate environment
        ↓
Install dependencies
        ↓
Work inside isolated environment
```

## 📦 Exercise 1 — Loading Programs

The second exercise focuses on **package management and dependencies**.

A Python project often depends on packages that are not included in the
standard library.

Instead of installing everything manually, dependencies can be described and
installed in a controlled way.

The exercise introduces the idea of keeping track of the packages required by
the project.

A dependency file such as:

```text
requirements.txt
```

can be used to describe the required Python packages.

This makes it easier to recreate the same development environment on another
machine.

The main concepts are:

- Installing packages with `pip`
- Managing dependencies
- Requirements files
- Reproducible environments
- Separating project dependencies from the system Python installation

## 🖥️ Exercise 2 — Accessing the Mainframe

The final exercise focuses on **environment configuration**.

Instead of storing configuration directly inside the Python source code,
environment variables can be used to provide values to the application.

This is useful for configuration that may change between environments, such as:

- Development
- Testing
- Production

The idea is to keep configuration separate from the application logic.

This makes the project easier to configure and avoids hard-coding
environment-specific values directly into the source code.

The exercise combines the previous concepts into a small data-oriented
workflow.

## 🧠 What I Learned

This project introduced some of the tools that are used in real Python
development outside of simple scripts.

During the project I worked with:

- Virtual environments
- `venv`
- `pip`
- Package installation
- Dependency management
- `requirements.txt`
- Environment variables
- Configuration management
- Reproducible development environments
- Python project structure

The biggest idea for me was understanding why a Python project should not
depend on whatever happens to be installed globally on a machine.

A virtual environment gives the project its own isolated space, while a
dependency file makes it possible to reproduce the required setup elsewhere.

Environment variables then provide a clean way to separate configuration from
the actual code.

## 🔧 Technical Focus

### Virtual Environments

A virtual environment creates an isolated Python environment for a project.

Instead of installing packages globally, dependencies can be installed inside
the project's environment.

This helps prevent conflicts between different projects that require different
package versions.

### Package Management

Python packages can be installed and managed using `pip`.

Keeping dependencies clearly defined makes a project easier to set up and share.

### Requirements

A `requirements.txt` file can describe the external packages required by the
project.

For example:

```text
package_name==version
```

This allows the environment to be recreated with the same dependency versions.

### Environment Variables

Environment variables allow configuration values to be provided from outside
the Python source code.

This keeps configuration separate from the application itself and makes it
possible to use different settings in different environments.

## 🛠️ Development

I worked through the project step by step, starting with an isolated Python
environment and then moving towards dependency management and environment
configuration.

The project helped me understand some of the basic tools used when moving from
small Python exercises towards more realistic Python projects.

Instead of only focusing on the code itself, the project also looks at how the
code is installed, configured, and prepared to run in a different environment.

## 📚 Resources

- 42 The Matrix subject
- Python 3 documentation
- `venv`
- `pip`
- Python packaging documentation
- Environment variable documentation
- Personal testing and experimentation

## 🤖 AI Usage

The project was developed through independent work, research, and peer learning. AI was used afterwards as a supporting tool for final review and README preparation. The implementation and project logic were written and understood by me.
````
