# Fractol

Fractol is a creative and interactive fractal explorer written in C, designed to render mesmerizing mathematical sets such as Mandelbrot, Julia, and more. With real-time controls and beautiful color palettes, Fractol lets you dive into the world of fractals and discover their infinite complexity.

## Features
- **Multiple Fractal Types:** Mandelbrot, Julia, and more
- **Real-Time Zoom & Pan:** Explore fractals interactively
- **Customizable Colors:** Switch between stunning color schemes
- **Keyboard & Mouse Controls:** Intuitive navigation and parameter tweaking
- **Optimized Rendering:** Fast and efficient drawing using the MiniLibX library

## Build & Run
```sh
make
./fractol <fractal_type> [options]
```
Example:
```sh
./fractol mandelbrot
./fractol julia
```

## Controls
- **Arrow Keys / Mouse Drag:** Pan the view
- **Scroll / +/-:** Zoom in and out
- **C:** Change color palette
- **R:** Reset view
- **ESC:** Exit

## Dependencies
- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- X11 libraries (Linux)

## Project Structure
- `src/` — Source files
- `include/` — Header files
- `Makefile` — Build instructions

## License
MIT License

---
*Let the beauty of mathematics unfold before your eyes!*
