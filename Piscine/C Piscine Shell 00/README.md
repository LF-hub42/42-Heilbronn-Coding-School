# C Piscine Shell 00

*This project has been created as part of the 42 curriculum by ekypraio.*

## Description

Shell 00 was my introduction to the Unix shell during the 42 Piscine.

The exercises introduced basic terminal commands, file permissions,
archives, SSH and Git.

This repository contains the exercises I completed during my Piscine.

## Exercises

### ex00: Z

Created a simple file named `z`.

**Focus:** File creation and terminal basics.

### ex01: testShell00

Worked with file permissions and timestamps and created a TAR archive.

**File:** `testShell00.tar`

**Focus:** Permissions, file attributes and `tar`.

### ex02: Oh yeah, mooore...

Created files and directories with specific permissions, links and
timestamps.

**File:** `exo2.tar`

**Focus:** Files, directories, permissions and links.

### ex03: SSH me!

Worked with an SSH public key for remote authentication.

**File:** `id_rsa_pub`

**Focus:** SSH keys and Git authentication.

> The archived solution uses an RSA public key. The included subject
> currently refers to an Ed25519 public key.

### ex04: midLS

Created a command that lists files using specific sorting and formatting.

**File:** `midLS`

**Focus:** `ls`, sorting and command options.

### ex05: GiT commit

Created a shell script that displays the five most recent Git commit IDs.

```sh
git rev-list -n 5 HEAD
```

**File:** `git_commit.sh`

**Focus:** Git history and shell scripting.

### ex06: gitignore

Created a shell script that displays files ignored by Git.

```sh
git ls-files --others --ignored --exclude-standard
```

**File:** `git_ignore.sh`

**Focus:** Git ignored files and repository inspection.

## What I Learned

During Shell 00 I learned how to:

- work with the Unix filesystem
- manage file permissions
- create and inspect TAR archives
- work with symbolic and hard links
- use SSH keys
- inspect Git repositories
- combine basic shell commands

These basics became part of my workflow for later 42 projects.

## Technical Focus

- Unix / Linux
- Shell
- Git
- SSH
- File permissions
- Files and directories
- TAR archives

## Resources

- Unix manual pages (`man`)
- Git documentation
- 42 subject
- Peer learning

## 🤖 AI Usage

AI was used for project review and README preparation.
