# Simple Shell

A simple UNIX command line interpreter written in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Acknowledgements](#acknowledgements)

## Introduction

This project is a simple shell implementation written in C. It mimics the basic functionality of a UNIX shell, allowing users to interact with the operating system via command-line instructions. The shell reads commands from standard input, executes them, and displays the results.

## Features

- Command execution
- Input redirection
- Output redirection
- Built-in commands
  - `cd`
  - `exit`
  - `env`
- Error handling

## Installation

To install and run the simple shell, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/Jaaf4r/simple_shell.git
    ```
2. Navigate to the project directory:
    ```sh
    cd simple_shell
    ```
3. Compile the source code:
    ```sh
    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
    ```

## Usage

To start the shell, run the compiled executable:
    ```sh
    ./hsh
    ```
You can then enter commands as you would in a regular shell. For example:
    ```sh
    $ ls -l
    $ pwd
    $ cd /path/to/directory
    $ echo "Hello, world!"
    ```
To exit the shell, use the exit command:
    ```sh
    $ exit
    ```

## Built-in Commands

- The following built-in commands are supported:
    - cd [directory]: Change the current directory to the specified directory.
    - exit [status]: Exit the shell with an optional status code.
    - env: Print the current environment variables.

## Acknowledgements

- This project was inspired by the need to understand the inner workings of a UNIX shell.
- Special thanks to all the contributors who helped in improving this project.
