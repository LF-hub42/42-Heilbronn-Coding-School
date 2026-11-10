# Milestone 3 — Codexion

## Description

Codexion is a multithreaded C project from the 42 core curriculum.

It simulates coders sharing a limited set of USB dongles. Each coder needs two
dongles to compile, then continues with debugging and refactoring. The main
focus is coordinating access to shared resources between concurrent threads.

## Technical Choices

- Each coder runs in its own POSIX thread.
- Mutexes and condition variables protect shared state and coordinate dongle access.
- FIFO orders dongle requests by arrival; Earliest Deadline First (EDF) gives
  priority to the earliest burnout deadline.
- A monitor thread detects burnout and checks whether all coders have completed
  the required number of compiles.
- Timestamped event logs are serialized with a mutex.

The project builds with a Makefile using `cc` and `-pthread`.

See the [Codexion project](./Codexion/) for the source code, build instructions,
and technical documentation.
