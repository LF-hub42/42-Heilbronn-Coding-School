# C Piscine Shell 01

*This project has been created as part of the 42 curriculum by ekypraio.*

## Description

Shell 01 continued my introduction to shell scripting during the
42 Piscine.

The exercises focused on combining Unix commands to search, filter and
format information directly from the terminal.

This repository contains the exercises I completed during my Piscine.

## Exercises

### ex01: print_groups

Created a script that displays the groups of a specified user.

```sh
id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'
```

**File:** `print_groups.sh`

**Focus:** User groups, environment variables and output formatting.

### ex02: find_sh

Created a script that finds `.sh` files and displays their names without
the file extension.

```sh
find . -type f -name "*sh" -execdir basename -s ".sh" {} +
```

**File:** `find_sh.sh`

**Focus:** `find`, file names and command execution.

### ex03: count_files

Created a script that counts files and directories.

```sh
find | wc -l
```

**File:** `count_files.sh`

**Focus:** `find`, pipes and `wc`.

### ex04: MAC

Created a script that displays the MAC addresses of the machine.

```sh
ifconfig | grep ether | tr -d '\t' | awk '{print $2}'
```

**File:** `MAC.sh`

**Focus:** Network information, filtering and `awk`.

### ex05: Can you create it?

Created a file with a special filename containing shell metacharacters.

**Focus:** Quoting, escaping and special characters.

### ex06: Skip

Created a command that displays every second line of an `ls -l` output.

```sh
ls -l | awk 'NR % 2 == 1'
```

**File:** `skip.sh`

**Focus:** Pipes, `ls` and `awk`.

## What I Learned

During Shell 01 I learned how to:

- combine commands using pipes
- search files with `find`
- manipulate command output
- use environment variables
- work with `grep`, `tr`, `awk` and `wc`
- handle special characters in filenames
- retrieve basic system and network information

These exercises helped me understand how small Unix tools can be
combined to solve more complex tasks.

## Technical Focus

- Shell scripting
- Unix / Linux
- Pipes
- Environment variables
- `find`
- `grep`
- `awk`
- `tr`
- `wc`

## Resources

- Unix manual pages (`man`)
- 42 subject
- Peer learning

## 🤖 AI Usage

These solutions are from my original Piscine work. AI was only used afterwards as a supporting tool for project review and GitHub documentation.
