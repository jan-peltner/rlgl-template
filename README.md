# RLGL Shader Template

A simple raylib-based template for creating GLSL shader visualizations.

## Overview

This project provides a minimal framework for experimenting with fragment shaders in raylib. The example implements a smooth color-cycling animation using a curated color palette.

## Requirements

- raylib
- C compiler
- OpenGL 3.3+ support

## Usage

```bash
# Build and run
./run.sh

# Build only
./build.sh
```

## Project Structure

- `src/main.c` - Main application logic
- `shaders/` - GLSL shader files
  - `main.vert` - Vertex shader
  - `main.frag` - Fragment shader
- `bin/` - Build output (created during build)

## Customization

To create your own shader effects:
1. Modify `shaders/main.frag` with your custom shader code
2. Update uniform variables in `src/main.c` if needed
3. Run the application to see changes

## Color Palette

Uses color palette from [Catppuccin](https://github.com/catppuccin)
