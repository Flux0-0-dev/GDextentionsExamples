# Godot GDExtension Example

This repository contains examples demonstrating how to use GDExtension in Godot 4.4.1.

## Prerequisites

- **Python**: [Download Python](https://www.python.org/downloads/)
- **SCons**: After installing Python, run: `pip install scons`
- **C++ Compiler**: GCC/G++ recommended
- **IDE**: Visual Studio Code recommended

## Setup Instructions

1. Clone or download this repository
2. Remove the existing `godot-cpp` directory (if present)
3. Clone the official Godot C++ bindings:
   ```bash
   git clone --branch 4.4 https://github.com/godotengine/godot-cpp
   ```
4. Build the bindings:
   ```bash
   scons
   ```
   For platform-specific builds, refer to the [Godot build system documentation](https://docs.godotengine.org/en/stable/contributing/development/compiling/introduction_to_the_buildsystem.html)

5. Open `demo/project.godot` in Godot 4.4.1

## Project Structure

- `src/` - GDExtension source code
- `demo/` - Example Godot project demonstrating the extensions
