# Chip-8 Emulator/Interpreter
Chip-8 Emulator in Qt Framework (C++)

Plan: Qt Desktop app running app of CHIP-8 interpreter.

# Sources Consulted:
1. Chip-8 language overview: https://tobiasvl.github.io/blog/write-a-chip-8-emulator/
2. JavaScript tutorial: https://www.freecodecamp.org/news/creating-your-very-own-chip-8-emulator/

# Project Structure
```
├── CMakeLists.txt
├── Chip8.h
├── Cpu.cpp (handles memory, reading and executing instructions)
├── Cpu.h
├── Display.cpp
├── Display.h (a QWidget representing the emulator application window)
├── Keyboard.cpp
├── Keyboard.h (handles keyboard input)
├── Speaker.cpp
├── Speaker.h (handles audio)
├── audio
│   └── hit.mp3
├── main.cpp
└── roms
```
