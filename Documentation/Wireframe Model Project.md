Here’s a detailed overview of the **FDF (Wireframe Model) Project** based on the provided PDF. The goal is to give a big-picture summary of what the project entails, how it works, and its key components. This summary can serve as a starting point for developers tackling this project in C.

# FDF: Wireframe Model Project

## Overview

The **FDF project** is a computer graphics project written in C that involves representing a landscape as a **3D wireframe model**. The program will take a file containing 3D coordinates and display the corresponding landscape using a graphical library called **MiniLibX**.

The objective of this project is to help developers become familiar with basic concepts of **graphics programming**, such as placing points in space, drawing connections (edges) between them, and rendering the scene from a specific viewpoint.

---

## Project Components

### 1. **Introduction to Wireframe Models**

A **wireframe model** is a way of representing 3D objects using lines to outline their shape. In this project, you will be rendering a wireframe landscape based on data provided in an input file. Each point in the landscape is defined by its `(x, y, z)` coordinates.

### 2. **MiniLibX Library**

You will use **MiniLibX**, a simple graphical library developed internally for opening windows, drawing images, and handling keyboard and mouse events. This project introduces basic concepts in **graphics programming** using this library.

### 3. **Objective**

The goal is to generate a basic **3D wireframe** of a landscape. The landscape is rendered from an **isometric perspective**, a method of visually representing 3D objects in two dimensions, making the height, width, and depth visible in equal proportions.

---

## Project Details

### 1. **Mandatory Features**

- **Input Parsing**: The program accepts an `.fdf` file as an argument. This file contains a grid of numbers where each number represents a point’s altitude in a 3D space.
  
  Example of a `.fdf` file:
  
  ```
  0  0  0  0  0
  0  10 10  0  0
  0  10 10  0  0
  0  0  0  0  0
  ```

- **Isometric Projection**: The 3D coordinates `(x, y, z)` must be projected onto a 2D plane using **isometric projection**.

- **Rendering**: Render the landscape as a wireframe model where points are connected by lines to form a grid-like structure.

- **Window Management**: The rendered image must be displayed in a window, and the program should handle window operations such as minimizing and closing.

- **Keyboard Controls**: The `ESC` key should close the window and cleanly exit the program, while clicking the window’s close button should also exit the program.

### 2. **Common Instructions**

- The project must adhere to the school’s coding standards (called **Norm**).
- You must manage **memory allocation** properly (no memory leaks).
- Global variables are forbidden.
- The project requires a `Makefile` with specific rules (`all`, `clean`, `fclean`, `re`).
- You can use the `libft` library, which you need to copy into the project folder if used.

### 3. **Graphics Management**

You must display the rendered model inside a window. The program should handle basic graphical interactions, such as window minimization and mouse/keyboard events, seamlessly.

### 4. **Bonus Features**

You are encouraged to implement additional features, such as:

- **Alternate projections**: Implement another projection, such as **parallel** or **conic**.
- **Zooming and Translating**: Allow the user to zoom in/out and move (translate) the model across the screen.
- **Rotation**: Implement model rotation for a more dynamic visual experience.
- **Other custom features**: You may add any other graphical or interactive features that add value to the project.

Note: The bonus features will only be evaluated if the **mandatory part** is completed perfectly without malfunctions.

---

## File Structure

### Files to Submit:

- **Source Files**: `.c` files for your program logic.
- **Headers**: `.h` files for function declarations and macro definitions.
- **Makefile**: A file to automate the build process. The rules include `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

### Functions to Use:

You are allowed to use standard functions such as:

- **File I/O**: `open`, `close`, `read`, `write`
- **Memory Management**: `malloc`, `free`
- **Error Handling**: `perror`, `strerror`, `exit`
- **Math Functions**: Use the math library (`-lm`) for calculations.
- **MiniLibX Functions**: All functions available in MiniLibX for graphical operations.
- **Your Custom Functions**: Implement your own utility functions for input parsing, rendering, etc.

---

## Project Execution

To run the project, you must provide a `.fdf` file containing the 3D coordinates. The program will read this file, process the coordinates, and render the corresponding wireframe model.

### Example Command:

```
./fdf map.fdf
```

The program should open a window with the rendered 3D landscape.

---

## Final Submission

- **Submission**: The project must be submitted via Git, and only the work in your Git repository will be evaluated.
- **Peer-Evaluation**: Your project will be peer-reviewed, so make sure your code is well-organized and follows the provided guidelines.

---

## Conclusion

This project introduces fundamental concepts of **graphics programming** in C, using the **MiniLibX** library to render a wireframe landscape from 3D coordinates. You’ll explore key areas such as **input parsing**, **projection techniques**, and **window management**, while adhering to good memory management practices and coding standards.

This project serves as an entry point into more advanced graphics programming and is an excellent opportunity to sharpen your understanding of C, particularly in relation to 2D/3D graphics and mathematical transformations.


