# Maya OS

**Maya OS** is a lightweight, x86-based operating system I built from scratch using C and Assembly. The OS features a basic shell, a custom file system, and a set of interactive commands. It runs on QEMU and is compiled and linked using tools installed via the Linux subsystem on Windows.

> This project was part of a coursework initiative and is a personal deep-dive into systems programming, operating system internals, and low-level development workflows.

## 💡 About the Project

Maya OS was built as part of an academic operating systems course, with the goal of gaining hands-on experience in low-level system programming. It showcases:

- A custom shell with basic commands (`help`, `about`, `clear`)
- A file system to `create`, `read`, `write`, `delete`, and `list` files
- Integration of file system with the shell
- Use of QEMU for emulation
- Manual setup of interrupts, segmentation, and boot sequence
- Written in a mix of C and NASM assembly, compiled with GCC and linked with `ld`

---

## 🧠 Project Structure

. ├── Makefile # Build instructions ├── kernel/ # Core OS logic ├── cpu/ # CPU and scheduler ├── user/ # User-level commands ├── include/ # Header files ├── shell.c # Custom shell └── boot/ # Bootloader code

---

## 🚀 Getting Started

To build and run Maya OS, you'll need a Linux development environment with specific system-level tools installed. This project is tested using **WSL (Windows Subsystem for Linux)** with **Ubuntu** on Windows.

### 🐧 Installing WSL & Ubuntu on Windows

If you're using Windows, follow this guide to set up WSL and install Ubuntu:

🔗 [Install WSL and Ubuntu on Windows](https://learn.microsoft.com/en-us/windows/wsl/install)

This will let you run Linux natively on Windows without a virtual machine — perfect for OS-level development.

---

## 🛠 Install Development Tools

Once WSL and Ubuntu are set up, install the necessary tools to build and run your OS:

WSL essentially gives you a Linux-like terminal environment inside Windows, and it's critical because tools like `GCC`, `NASM`, and `Make` work best in a Unix-based system.

### Step 1: Update System

Open Ubuntu in WSL and run:

```bash
sudo apt update
sudo apt upgrade
```

### Step 2: Install GCC (C Compiler)

```bash
sudo apt install gcc
```

Used for compiling the kernel and shell code written in C.

### Step 3: Install NASM (Assembler)

```bash
sudo apt install nasm
```

Assembles .asm files into machine code; critical for writing the bootloader.

### Step 4: Install Binutils (Linking tools)

```bash
sudo apt install binutils
```

Includes tools like ld to link object files into a bootable binary.

### Step 5: Install Make (Build Automation)

```bash
sudo apt install make
```

Make reads the Makefile and compiles the project automatically with correct dependencies.

### Step 6: Install QEMU (Virtual Machine)

```bash
sudo apt install qemu-system-x86
```

QEMU simulates x86 hardware, allowing you to run your OS safely on your own machine.

## ✅ Verifying Installation

Make sure everything is correctly installed:

```bash
gcc --version
nasm -v
ld --version
make --version
qemu-system-x86_64 --version
```

Each command should return a version number, confirming the tool is installed and accessible

## 🔧 Build & Run

### Clone the repo

```bash
git clone https://github.com/yourusername/maya-os.git
cd maya-os
```

### Build

```bash
make
```

### Run in QEMU

```bash
make run
```

Your OS will boot up inside a QEMU window. From there, you can use the shell, execute commands, and explore your build.

## 📜 License

This project is licensed under the MIT License. You are free to use, modify, and distribute the code with attribution.

## 🙌 Acknowledgements

Thanks to the Operating Systems course at Northeastern University and various online OSDev communities and resources that inspired and supported this journey.

## 📚 Note on Academic Integrity

This repository contains a detailed, original implementation of OS internals. Please do not copy-paste this code for any academic assignments.

The purpose of this project is to **inspire learning**, not shortcut it.

> If you're a student working on a similar OS project, I strongly encourage you to explore and build your own version. It’s challenging—but that’s what makes it worth it.

## 🌱 Future Improvements

Add file permissions and ownership

Implement memory-efficient file handling

Introduce basic scheduling and multitasking

Include paging and virtual memory

Add shell scripting support

## 🙋‍♀️ About Me

Hi! I’m Stafny Velitia Karkada, a Master’s student in Computer Science at Northeastern University. I’m passionate about systems programming, low-level design, and building things from the ground up.

Feel free to connect or check out my other work:  
👉 [LinkedIn](https://www.linkedin.com/in/your-username/)  
👨‍💻 [GitHub](https://github.com/your-username)  
🌐 [Portfolio](https://your-portfolio-site.com)
