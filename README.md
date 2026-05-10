# Hangman

Console-based Hangman game developed in C with modular source code organization, structured folders, and Windows console customization.

![C](https://img.shields.io/badge/C-Programming-blue)
![CMake](https://img.shields.io/badge/CMake-Build%20System-green)
![Windows](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Console App](https://img.shields.io/badge/Application-Console%20App-informational)

## Demo

https://github.com/user-attachments/assets/40bb7064-8f5e-4173-9cb5-69b56e21cb3a

## What is it?

Hangman is a desktop console application that implements the classic Hangman word-guessing game for Windows.

The software allows one player to enter a hidden word and another player to guess it by entering single letters or attempting the full word.

The game manages word formatting, input validation, available alphabet letters, progressive hangman drawing, error counting, win detection, loss detection, and final result visualization directly inside a Windows console interface.

The project is organized into separate source and header files, with a structured division between core game logic and user interface components.

## Features

- Console-based Hangman gameplay
- Hidden word input
- Single-letter guessing
- Full-word guessing
- Input validation for words and letters
- Exit command using `0`
- Automatic word formatting
- Available alphabet visualization
- Already-used letter removal
- Progressive hangman drawing based on the number of errors
- Maximum limit of 7 errors
- Win and loss detection
- Final result message
- Fixed and centered Windows console window
- Custom executable icon through Windows resource files
- Modular C source code organization with separated `core` and `ui` folders

## Key Technical Aspects

- Modular separation between game logic, input handling, state updates, verification logic, console configuration, drawing functions, and interface layout
- Structured project organization with dedicated `core` and `ui` modules
- Windows-specific console customization using the Windows API
- Dynamic memory allocation for alphabet, revealed letters, and word symbol representation
- Input validation for hidden words, guessed letters, full-word attempts, and exit commands
- Progressive ASCII drawing updated according to the number of wrong attempts
- CMake-based build configuration
- Custom executable icon integration through a Windows resource file
- Clear separation between source files and header files

## Technology Stack

- C
- CMake
- Windows API
- Windows resource file `.rc`
- CLion or another CMake-compatible IDE

## Requirements

- Windows operating system
- CMake
- A C compiler supported by CMake
- CLion, Visual Studio, or another CMake-compatible development environment

## Quick Start

### Clone the repository

```bash
git clone https://github.com/MattiaBenati/Hangman.git
cd Hangman
```

### Build the project

Generate the build files:

```bash
cmake -S . -B build
```

Build the executable:

```bash
cmake --build build
```

### Run the application

Run the generated executable from the build directory or directly from the IDE.

## Usage

1. Start the application
2. The initial console window is displayed
3. Enter the word that must be guessed
4. The game screen is opened
5. The hidden word is displayed using visible symbols
6. Enter a single letter or attempt the full word
7. The program validates the input
8. Correct guesses update the revealed letters
9. Wrong guesses increase the number of errors and update the hangman drawing
10. The game ends when the word is guessed or when the maximum number of errors is reached
11. The final result is displayed in the console
12. Press `Enter` to continue playing or use `0` to exit

## Controls

| Input | Action |
| --- | --- |
| `letter` | Guess a single letter |
| `word` | Attempt the full hidden word |
| `0` | Exit the game |
| `Enter` | Continue after the final result screen |

The program accepts only alphabetic characters and apostrophes for word input.

Repeated single-letter attempts are rejected when the letter has already been used.

## Project Structure

```text
Hangman/
├── assets/
│   ├── icon.ico
│   ├── icon.png
│   └── resource.rc
├── include/
│   ├── core/
│   │   ├── aggiornamento.h
│   │   ├── gioco.h
│   │   ├── inizializzazione.h
│   │   ├── input.h
│   │   └── verifica.h
│   └── ui/
│       ├── console.h
│       ├── disegno.h
│       └── grafica.h
├── src/
│   ├── core/
│   │   ├── aggiornamento.c
│   │   ├── gioco.c
│   │   ├── inizializzazione.c
│   │   ├── input.c
│   │   └── verifica.c
│   ├── ui/
│   │   ├── console.c
│   │   ├── disegno.c
│   │   └── grafica.c
│   └── main.c
└── CMakeLists.txt
```

## Architecture Overview

The project follows a modular C structure with a clear separation between core gameplay logic and user interface management.

- `main.c`: starts the application, sets the console window title, and launches the game
- `core/gioco.c`: manages the main game loop, screen transitions, game state, memory cleanup, and replay flow
- `core/input.c`: handles word input, letter input, full-word attempts, validation rules, and exit commands
- `core/inizializzazione.c`: initializes the available alphabet, revealed letters, and symbol representation of the hidden word
- `core/aggiornamento.c`: updates revealed letters and removes already-used letters from the alphabet
- `core/verifica.c`: verifies correct letters and checks whether the full word has been guessed
- `ui/console.c`: configures the Windows console title, input mode, window behavior, and screen position
- `ui/disegno.c`: manages the progressive hangman ASCII drawing, alphabet display, and revealed word display
- `ui/grafica.c`: manages cursor positioning, panel borders, instructions, and final result messages
- `include/`: contains the header files organized by module
- `assets/`: contains the application icon and Windows resource file
- `CMakeLists.txt`: defines the CMake build configuration

## Output

The software runs entirely inside the Windows console.

During execution, it displays the initial word input screen, the game panel, the available alphabet, the hidden word representation, the progressive hangman drawing, the current guessing state, and the final result.

The final output indicates whether the word was correctly guessed or whether the maximum number of errors was reached.
