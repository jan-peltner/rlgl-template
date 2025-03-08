# RLGL Shader Template

A simple raylib-based template for creating GLSL shader visualizations.

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

## Performance UI

The application displays real-time performance metrics in the top-left corner:
- FPS
- Frametime

## Customization

To create your own shader effects:
1. Modify `shaders/main.frag` with your custom shader code
2. Update uniform variables in `src/main.c` if needed
3. Run the application to see changes

## Color Palette

Uses color palette from [Catppuccin](https://github.com/catppuccin)
