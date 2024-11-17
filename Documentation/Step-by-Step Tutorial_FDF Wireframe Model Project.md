# Step-by-Step Tutorial: FDF Wireframe Model Project

### **Step 1: Setting Up Your Development Environment**

Before starting, you need to ensure that your development environment is set up properly.

1. **Install GCC or Clang (C Compiler)**:
   Make sure you have a C compiler installed on your system. You can verify this by typing the following in your terminal:
   
   ```bash
   gcc --version
   ```
   
   or
   
   ```bash
   clang --version
   ```

2. **Install MiniLibX**:
   The **MiniLibX** graphical library is required for this project. It might already be available on your school’s machines, or you can install it manually. You can find MiniLibX in your repository or clone its source from a GitHub repository (usually provided by your school).
   
   To install MiniLibX on your local machine, clone its repository and compile it:
   
   ```bash
   git clone https://github.com/42Paris/minilibx-linux.git
   cd minilibx-linux
   make
   ```
   
   You can write a small test program to verify that MiniLibX is working correctly. Here’s an example of a minimal MiniLibX program that opens a window and waits for the user to close it:
   
   ```c
   // test_mlx.c
   #include "mlx.h"
   
   int main(void)
   {
        void *mlx;
        void *window;// Initialize the connection to the graphical server
       mlx = mlx_init();
       if (!mlx)
       {
           return (1);
       }
   
       // Create a new window
       window = mlx_new_window(mlx, 800, 600, "MiniLibX Test Window");
       if (!window)
       {
            return (1);
       }
   
       // Start the MiniLibX event loop
       mlx_loop(mlx);
   
       return (0);
   }
   ```
   
   Make sure to install the required dependencies. For Linux, you might need to install `X11`, `Xrandr`, and `Xext`. Use the following command:
   
   ```bash
   sudo apt-get install libx11-dev libxext-dev libxrandr-dev
   ```
   
   To compire it, use :
   
   ```bash
   gcc -Wall -Wextra -Werror test_mlx.c -L ./minilibx-linux -lmlx -lX11 -lXext -lm -o test_mlx
   ```
   
   then you execute it :
   
   ```bash
   ./test_mlx
   ```
   
   If MiniLibX is installed correctly:
   
   - A window should appear with the title "MiniLibX Test Window."
   - The window should remain open until you manually close it. (CTRL + C)
   
   If you get errors during compilation or when running the program, it means something went wrong during the installation of MiniLibX. The error messages can help diagnose the issue (missing dependencies, incorrect library path, etc.).
   
   3.**Create the Project Directory**:
   Inside your working directory, create the project folder and essential files:
   
   ```bash
   mkdir fdf_project
   cd fdf_project
   touch Makefile fdf.c fdf.h
   ```

---

### **Step 2: Understanding the .fdf Input File Format**

The `.fdf` file contains 3D coordinates representing a grid of points in space. These points will be linked to create the wireframe.

- Each number in the `.fdf` file represents the **altitude** (`z` value) of a point.
- The position of a number in the file determines its **x** and **y** coordinates.

Example file `map.fdf`:

```
0  0  0  0
0  10 10  0
0  10 10  0
0  0  0  0
```

This file represents a 4x4 grid where points in the center have higher altitudes, which will be rendered as a wireframe landscape.

---

### **Step 3: Create the Makefile**

The Makefile is used to automate the building process of your project. It ensures that your project compiles correctly with the appropriate flags.

Here’s a basic structure for your `Makefile`:

```makefile
NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

SRC = fdf.c \
      draw.c \
      parse_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all
```

Key Points:

- The `NAME` variable defines the output file.
- The `SRC` contains all the source files you will create.
- `MLX` specifies how to link MiniLibX on macOS. For Linux, you would use something like `-lmlx -lXext -lX11 -lm`.
- `all`, `clean`, `fclean`, and `re` are standard rules.

---

### **Step 4: Implement Map Parsing**

You need to read the `.fdf` file to extract the coordinates and store them in a suitable data structure, such as a 2D array.

1. **Read the File**:
   Use functions like `open`, `read`, and `get_next_line` to read the content of the `.fdf` file. Store each line in a list or array.
   
   Here is an example to read the file:
   
   ```c
   #include <fcntl.h>
   #include <stdio.h>
   #include <stdlib.h>
   
   void parse_file(char *filename)
   {
       int fd = open(filename, O_RDONLY);
       if (fd < 0)
       {
           perror("Error opening file");
           exit(EXIT_FAILURE);
       }
   
       char *line;
       while (get_next_line(fd, &line))
       {
           // Process the line to extract coordinates
           printf("%s\n", line); // Replace with actual parsing
           free(line);
       }
   
       close(fd);
   }
   ```

2. **Convert the File Data into Coordinates**:
   Each number in the file represents the altitude (`z` value), and you need to map these to a corresponding `(x, y)` coordinate.
   
   Use `ft_split()` to split each line into an array of integers, representing the grid.
   
   ```c
   // Example function to split and store values
   int **parse_map(char *filename)
   {
       // Implement splitting logic here
   }
   ```

---

### **Step 5: Implement Coordinate Projection (Isometric)**

Once you have the 3D points (`x`, `y`, `z`), you need to transform them into 2D coordinates for rendering. In this project, we use **isometric projection**.

- Isometric projection formula:
  
  ```c
  int iso_x = (x - y) * cos(angle);
  int iso_y = (x + y) * sin(angle) - z;
  ```

These formulas convert 3D coordinates `(x, y, z)` into 2D coordinates `(iso_x, iso_y)`.

### **Understanding the Angle in Isometric Projection**

In **isometric projection**, the goal is to project 3D coordinates `(x, y, z)` onto a 2D plane in such a way that all three axes (`x`, `y`, and `z`) appear equally foreshortened. This makes it possible to view all three dimensions clearly in a single 2D image. To achieve this, the points must be rotated and projected onto a 2D plane.

In an isometric projection:

- The **x-axis** and **y-axis** are rotated relative to the screen (usually by 30 degrees or `π/6` radians).
- The **z-axis** is used to control the height of the points in the 2D plane, and its contribution should be adjusted accordingly.

### **Angle in the Projection Formula**

In the projection formula I mentioned earlier, the **angle** refers to the **isometric rotation angle**. In isometric projection, the common angles used are 30 degrees (for x and y axis) and 45 degrees in some variations. Typically, this is approximated using the following values:

- **cos(30°) = √3 / 2 ≈ 0.866**
- **sin(30°) = 1 / 2 = 0.5**

Thus, the general formula for isometric projection is:

```c
int iso_x = (x - y) * cos(angle);
int iso_y = (x + y) * sin(angle) - z;
```

Where `angle` would typically be `30°` (or `π/6` radians), because that’s a common angle used for the isometric projection of the **x** and **y** axes. For this purpose, we substitute:

- `cos(30°)` = `0.866`
- `sin(30°)` = `0.5`

This yields the final projection formulas:

```c
int iso_x = (x - y) * 0.866;  // cos(30°)
int iso_y = (x + y) * 0.5 - z;  // sin(30°)
```

### **How to Calculate the Angle (Optional)**

If you want more flexibility, you can calculate the angle dynamically. For example, if you decide to rotate the model interactively, you might want to compute the angle at runtime. Here's how you can do it in **C**:

```c
#include <math.h>

#define PI 3.14159265

double angle = 30.0;  // The isometric angle in degrees
double radian = angle * (PI / 180);  // Convert degrees to radians

int iso_x = (x - y) * cos(radian);
int iso_y = (x + y) * sin(radian) - z;
```

- Here, `30.0` is the angle in degrees for isometric projection.
- `cos(radian)` and `sin(radian)` calculate the cosine and sine of the angle in radians.

---

### **Summary of Key Points**

- In **isometric projection**, the typical angle between the **x** and **y** axes is **30 degrees** (or **π/6 radians**).
- You can directly use **cos(30°) = 0.866** and **sin(30°) = 0.5** in the projection formulas for simplicity.
- If you want to dynamically change the projection angle, you can compute it at runtime using trigonometric functions like `cos()` and `sin()`.

By applying this transformation, you will project the 3D coordinates onto a 2D plane while keeping the visual representation of depth.

---

### **Step 6: Drawing the Wireframe**

You will now use the MiniLibX library to draw lines between the points in 2D space. Each point in the grid is connected to its adjacent points (right and below) to form the wireframe.

1. **Create a Window**:
   Use MiniLibX to open a window:
   
   ```c
   void setup_window(void)
   {
       void *mlx;
       void *window;
   
       mlx = mlx_init();
       window = mlx_new_window(mlx, 800, 600, "Wireframe Model");
   }
   ```

2. **Draw Lines**:
   Use the `mlx_pixel_put` or `mlx_line_put` function from MiniLibX to draw lines between points. Implement a simple **Bresenham’s line algorithm** to draw lines between two points.
   
   ```c
   void draw_line(int x0, int y0, int x1, int y1)
   {
       // Implement Bresenham’s line algorithm
   }
   ```

---

### **Step 7: Handle Events (Keyboard/Mouse)**

To make the program interactive, you need to handle keyboard and mouse events. Use MiniLibX functions like `mlx_key_hook()` to bind keyboard keys to certain actions (like exiting the program).

Example of closing the program when the `ESC` key is pressed:

```c
int handle_keypress(int key, void *param)
{
    if (key == 53) // ESC key
        exit(0);
    return 0;
}

void setup_window(void)
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "Wireframe Model");
    mlx_key_hook(window, handle_keypress, NULL);
    mlx_loop(mlx);
}
```

---

### **Step 8: Bonus Features (Optional)**

Once you have completed the mandatory part, consider implementing some of these bonus features:

- **Zooming**: Implement zooming in and out using keyboard keys (`+`/`-`).
- **Translation**: Allow the user to move the model left, right, up, and down.
- **Rotation**: Rotate the model on different axes to provide different perspectives.
- **Different Projection Types**: Add support for another projection method, such as parallel projection.

---

### **Step 9: Test and Debug**

Once you have written your code, compile the project using the Makefile and test it with different `.fdf` files.

1. Compile the project:
   
   ```bash
   make
   ```

2. Run the project:
   
   ```bash
   ./fdf map.fdf
   ```

3. Debug and fix any issues related to:
   
   - Memory leaks (use `valgrind` to check).
   - Incorrect file parsing.
   - Graphical errors in rendering.

---

### **Step 10: Submission and Peer Evaluation**

Finally, you need to submit your project to the provided Git repository. Make sure all the files (Makefile, `.c` and `.h` files) are included. Follow the submission guidelines carefully.

---

## Conclusion

By following this step-by-step guide, you should be able to complete the **FDF Wireframe Model** project. You'll not only become more familiar with **C programming** but also get an introduction to **graphics programming** using **MiniLibX**. Be patient with the graphical aspects, as they can be tricky, and test your program thoroughly to ensure all the features are working correctly.
