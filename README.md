# FdF_42
 FdF stands for "Fil de Fer" (Wireframe) and it is a graphical project that involves creating a 3D wireframe representation of a landscape based on height maps.

 [![my project overview](https://ytcards.demolab.com/?id=QVobB3pZoIY&ab_channel=AlessioTucci&title=Fdf+project+overview+42)](https://youtu.be/QVobB3pZoIY?feature=shared)


# Bresenham's Algorithm 
I have watched the video to start understanding the functionality of the algorithm, then I have tried to implementing according to the school norm

<img width="360" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/2bc03250-9633-4c96-a74e-1360efde61c8">

|Useful yt videos| Description |
|----------------|-------------|
| [![bersenham's ALGORITHM](https://ytcards.demolab.com/?id=RGB-wlatStc)](https://youtu.be/RGB-wlatStc) | [`abdul bari`](https://www.youtube.com/@abdul_bari) is one of the greates when it comes to explain how algorithm works | 
| [![Useful detailed video](https://ytcards.demolab.com/?id=y_SPO_b-WXk)](https://youtu.be/y_SPO_b-WXk?feature=shared) |This video is a little bit shorter and help me understand better the overrall logic.| 

By using Bresenham's Algorithm, the FdF project can efficiently draw lines between the points, avoiding the need to calculate and plot every single pixel along the line. The algorithm works by making decisions based on the slope of the line and the position of pixels to determine which pixels to light up, resulting in a straight line approximation.

The other choiche was the DDA but I didn't want to work with float points and I have seen around that most of the people haven't used this algorithm.



# Isometric projection

<img width="490" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/e34cb88f-126c-4939-b7ac-f1f665a63bf3">

<img width="355" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/0ca0cf28-a8a3-4b87-bded-ecba38996ff5">

In the FdF project, the map represents a terrain or landscape with different elevation levels.

By applying isometric projection, the project aims to display the map in a visually appealing and intuitive manner. 

It ensures that the elevation levels are properly represented, and the lines connecting the points follow the correct angles and perspectives, creating the illusion of depth.
 
 # THE LONG JOURNEY (almost 4 month)
 <img width="200" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/77dfd5c2-e649-4c81-9c63-96fbf2d8146a">
<img width="200" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/86633a24-7856-45f8-a9dd-29d0a0a10b0d">
<img width="200" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/b26975ec-8164-4c47-86b8-387f57985ea1">
<img width="200" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/53b2535d-d81d-4108-80de-ef46d635470f">

 
 during the long journey to try to understand this project, I have changed OS (from MacOs to Ubuntu), worked by myself and in couple with a friend, and I wasted a lot of days, so in August I decided to freeze it because I was going on Holidays in asia.

<img width="401" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/5b00c7a5-8442-4ee6-832b-d24e3816abec">
<br>


When I come back I was working on it by myself and I was able to finished it. I wasted a lot of days on this project.

<br>

<img width="401" alt="image" src="https://github.com/alessiotucci/FdF_42/assets/116757689/635bfaed-d792-46dc-9afe-e1bddc74a107">


 
 # HOW TO START WITH THE PROJECT


  ### How I structured my project
| STEP TO TAKE       | How to do that                                    |the function  that  is doing so                          |
| -------------------| ------------------------------------------------- | ------------------------------------------------------- |
|1) READ FILE        | Determine the height (number of lines) and width (number of numbers in each line) of the text file. Create a data structure based on the width and height and store values inside of it. You can use a function similar to ft_split() to split the lines and atoi() to convert the numbers. Read the file using get_next_line and write the numbers into the data structure of your choiche.|   [``check_the_map``](https://github.com/alessiotucci/FdF_42/blob/main/fdf.c#L30)|
|2) DRAWING LINE FUNCTION|Implement a function that draws lines using Bresenham's algorithm. Calculate the increments for the x and y directions based on the starting and ending coordinates of the line.|[``bresenham ``](https://github.com/alessiotucci/FdF_42/blob/main/bresenham.c)|
|3)FUNCTION WHICH DRAWS LINES BETWEEN EVERY DOTS|Create a function that draws lines between the points of the map. Iterate over the map and draw lines between adjacent dots. Each dot will have a right line and a down line.|[``draw_lines``](https://github.com/alessiotucci/FdF_42/blob/main/isometric.c#L44)|
|4)ADDING 3D |Modify the coordinates using isometric formulas to represent a 3D projection. Apply the formulas ``x' = (x - y) * cos(angle) and y' = (x + y) * sin(angle) - z``, where x' and y' are the new 3D coordinates and angle is the rotation angle (default: 0.8 radians). Update the drawing functions to use the transformed 3D coordinates.|[``int_to_isometric_pixel``](https://github.com/alessiotucci/FdF_42/blob/main/isometric.c#L26)|
|5)ADDING BONUSES, (MOVE ROTATION ZOOM)|Implement functionality for handling user input, such as keyboard events. Use functions like ``mlx_key_hook(win_ptr, deal_key, NULL)`` to register keyboard event handling. In the event handling function (deal_key), update the parameters based on the user input, clear the window using ``mlx_clear_window(mlx_ptr, win_ptr)``, and redraw the picture with the updated parameters.|I havent done the bonus but still there is need to handle certain events [``close windows``](https://github.com/alessiotucci/FdF_42/blob/main/windows_manag.c)|
|6)ERROR HANDLING |Check if the program is executed with the correct number of arguments ``(argc == 2)``. Check if the file exists and can be opened ``(if ((fd = open(file_name, O_RDONLY) > 0)))``.|[``check stuff``](https://github.com/alessiotucci/FdF_42/blob/main/fdf.c#L133C1-L134C1)|
|7)FIX LEAKS      |Perform memory leak checks using tools like leaks a.out or leaks fdf in your shell. Ensure that all dynamically allocated memory is properly freed before the program exits.|         [``increment and free``](https://github.com/alessiotucci/FdF_42/blob/main/extra_color.c#L17)|



# tutorial on how to work with Images:
|Useful blog post|
|----------------|
|[how to create a image in mlx](https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html)|
|[Pixel drawing with the minilibx](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)|

| Step | Description                               | MiniLibX Function                   | Inside my code |
|------|-------------------------------------------|------------------------------------|-----------------|
| 1    | Initialize the mlx connection             | `mlx_init`                         | [``windows_manage``](https://github.com/alessiotucci/FdF_42/blob/main/windows_manag.c#L61C1-L62C1)|
| 2    | Create a window                           | `mlx_new_window`                   | [``new_windows``](https://github.com/alessiotucci/FdF_42/blob/main/windows_manag.c#L65)|
| 3    | Create an image                           | `mlx_new_image`                    | [``new_image``](https://github.com/alessiotucci/FdF_42/blob/main/windows_manag.c#L18C1-L19C1)|
| 4    | Get the image data                        | `mlx_get_data_addr`                | [``new_image``](https://github.com/alessiotucci/FdF_42/blob/main/windows_manag.c#L20C1-L21C1)|
| 5    | Draw on the image                         | Modify pixel data                  |    ...|
| 6    | Put the image onto the window             | `mlx_put_image_to_window`          |  [``new_windows``](https://github.com/alessiotucci/FdF_42/blob/main/windows_manag.c#L71C1-L72C1)|
| 7    | Start the event loop                      | `mlx_loop`                         |  [``new_windows``](https://github.com/alessiotucci/FdF_42/blob/main/windows_manag.c#L74C8-L74C8)|



