*This project has been created as part of the 42 curriculum by ekypraio.*

# 🖥️ Born2beRoot

## 📌 Description

Born2beRoot is a system administration project focused on setting up a secure virtual machine using the latest stable version of Debian.

The main goal was to configure a secure Linux environment including:

- Encrypted LVM partitions
- Password and sudo policies
- SSH access without root login
- A firewall
- AppArmor
- An automated monitoring script using cron

The project helped me understand virtualization, Linux security, server configuration, and basic system administration.

## Instructions

### Virtual Machine Setup

The virtual machine was created using VirtualBox with:

- 1024 MB RAM
- 1 vCPU
- 30 GB virtual hard disk
- Latest stable Debian version

### System Configuration

The system was configured with:

- LUKS encrypted LVM
- AppArmor enabled at startup
- OpenSSH installed and configured
- SSH running on port 4243
- Root login through SSH disabled
- User `ekypraio` created

The user was added to:

- `sudo`
- `user42`

### 🔐 Security Configuration

UFW was enabled and only port `4243` was allowed.

The password policy was configured in:

```text
/etc/login.defs
/etc/pam.d/common-password
```

The sudo policy includes:

- Maximum 3 authentication attempts
- Custom error message
- Logging of sudo actions to `/var/log/sudo/`
- Restricted `secure_path`
- TTY mode enforced

### 📊 Monitoring Script

A `monitoring.sh` script was created to display system information.

The script runs:

- Once at startup
- Every 10 minutes using cron

## 🧩 Project Design Choices

### Debian

I chose Debian because it is stable, lightweight, well documented, and recommended by the subject for the project.

It also uses AppArmor, which I found easier to understand and configure than SELinux.

### LVM + LUKS

The partition structure is based on an encrypted LVM setup:

```text
/boot
(unencrypted)

LUKS container
      |
      v
  LVM group
   / | \
  /  /home  swap
```

The main reasons for using this setup are:

- Encryption protects system and user data
- LVM allows flexible partition management
- System and user files are separated

### Password Policy

The following password rules were configured:

- Password expires every 30 days
- Minimum 2 days before changing the password again
- 7-day expiration warning
- Minimum 10 characters
- Uppercase, lowercase, and digit required
- Maximum 3 identical consecutive characters
- Password must not contain the username
- At least 7 characters must differ from the previous password
- The previous-password difference requirement does not apply to root

### SSH

SSH is running on port `4243`.

Port `4242` was tested but did not work on this system. Several other students reported the same issue.

Root login through SSH is disabled, and only the user `ekypraio` is allowed to authenticate.

### Sudo

The sudo configuration includes:

- 3 authentication attempts
- Custom authentication error message
- Logging of sudo actions in `/var/log/sudo/`
- Restricted execution path
- TTY required

## ⚙️ Services

The following services and security tools were configured:

- OpenSSH
- UFW
- Cron
- AppArmor

No bonus services were implemented.

## ⚖️ Comparisons

### Debian vs Rocky Linux

**Debian**

- Uses AppArmor
- Easier to configure
- Beginner-friendly

**Rocky Linux**

- Uses SELinux
- More complex
- More enterprise-oriented

### AppArmor vs SELinux

**AppArmor**

- Profile-based
- Easier to understand and maintain

**SELinux**

- Policy-based
- More granular
- More complex

### UFW vs firewalld

**UFW**

- Simple allow/deny rules
- Works well with Debian

**firewalld**

- Zone-based
- More flexible
- Commonly used with Rocky Linux

### VirtualBox vs UTM

**VirtualBox**

- Recommended by the 42 subject
- Stable and widely compatible

**UTM**

- Useful on Apple Silicon
- Alternative when VirtualBox is not supported

## 📚 Resources

- Debian Handbook
- AppArmor Documentation
- OpenSSH Manual Pages
- UFW Documentation
- LVM and LUKS Encryption Guides
- Born2beRoot Subject PDF

## 🤖 AI Usage

The project was developed through independent work, research, and peer learning. AI was used afterwards as a supporting tool for final review and README preparation.
