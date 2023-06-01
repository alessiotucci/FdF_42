
![image](https://github.com/alessiotucci/FdF_42/assets/116757689/2d0459ec-a4be-4263-b3e8-b01bdcb62955)

# FdF_42
 FdF stands for "Fil de Fer" (Wireframe) and it is a graphical project that involves creating a 3D wireframe representation of a landscape based on height maps.
 
# Bresenham's Algorithm 
Imagine you have a piece of graph paper and you want to draw a straight line between two points on the paper. Bresenham's Algorithm is like a clever strategy that helps you decide which squares on the paper to fill in to create the line.

![prova](https://github.com/alessiotucci/FdF_42/assets/116757689/2bc03250-9633-4c96-a74e-1360efde61c8)

By using Bresenham's Algorithm, the FdF project can efficiently draw lines between the points, avoiding the need to calculate and plot every single pixel along the line. The algorithm works by making decisions based on the slope of the line and the position of pixels to determine which pixels to light up, resulting in a straight line approximation.

# Isometric projection

In the FdF project, the map represents a terrain or landscape with different elevation levels. By applying isometric projection, the project aims to display the map in a visually appealing and intuitive manner. Without isometric projection, the map would appear flat and lose the depth and dimensionality necessary for understanding its structure.


 ![Optical_illusion_in_isometric](https://github.com/alessiotucci/FdF_42/assets/116757689/0ca0cf28-a8a3-4b87-bded-ecba38996ff5)


understanding isometric projection allows the program to transform the map's coordinates and display them in a visually pleasing way. It ensures that the elevation levels are properly represented, and the lines connecting the points follow the correct angles and perspectives, creating the illusion of depth.
 
 
 
 # HOW TO START WITH THE PROJECT


  ### How I structured my project
| STEP TO TAKE                                | How to do that                                    |the function  that  is doing so                          |
| --------------------------------------------| ------------------------------------------------- | ------------------------------------------------------- |
|1) READ FILE                                 | Determine the height (number of lines) and width (number of numbers in each line) of the text file.                                                            Allocate memory for a 2D integer matrix (**int) based on the width and height.     You can use a function similar to ft_strsplit() to split the lines and atoi() to convert the numbers.      Read the file and write the numbers into the matrix.|               ..                                        |
|2) DRAWING LINE FUNCTION                     |Implement a function that draws lines using Bresenham's algorithm. Calculate the increments for the x and y directions based on the starting and ending coordinates of the line. Use floating-point arithmetic to determine how much to increment x and y in each step of the algorithm. Adjust the increments so that y grows faster than x, maintaining a visually smooth line.|               ..                                        |
|3)FUNCTION WHICK DRAWS LINES BETWEEN EVERY DOTS|Create a function that draws lines between each dot in the matrix. Iterate over the matrix and draw lines between adjacent dots. Each dot will have a right line and a down line.|               ..                                        |
|4)ADDING 3D                           |Modify the coordinates using isometric formulas to represent a 3D projection. Apply the formulas x' = (x - y) * cos(angle) and y' = (x + y) * sin(angle) - z, where x' and y' are the new 3D coordinates and angle is the rotation angle (default: 0.8 radians). Update the drawing functions to use the transformed 3D coordinates.|               ..                                        |
|5)ADDING BONUSES, (MOVE ROTATION ZOOM)         |Implement functionality for handling user input, such as keyboard events. Use functions like ``mlx_key_hook(win_ptr, deal_key, NULL)`` to register keyboard event handling. In the event handling function (deal_key), update the parameters based on the user input, clear the window using ``mlx_clear_window(mlx_ptr, win_ptr)``, and redraw the picture with the updated parameters.|               ..                                        |
|6)ERROR HANDLING                      |Check if the program is executed with the correct number of arguments ``(argc == 2)``. Check if the file exists and can be opened ``(if ((fd = open(file_name, O_RDONLY) > 0)))``.|               ..                                        |
|7)FIX LEAKS                                    |Perform memory leak checks using tools like leaks a.out or leaks fdf in your shell. Ensure that all dynamically allocated memory is properly freed before the program exits.|               ..                                        |






