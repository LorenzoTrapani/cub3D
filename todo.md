# RAYCASTING

- Step 1: 
  Calculating the Ray Direction
The first step is to calculate the direction of the ray based on the player’s position and orientation.
- Step 2: Calculating the Delta Distance
The next step is to calculate the delta distance between two consecutive x or y intersections with a grid line.
- Step 3: Calculating the Step and Initial Side Distances
Now we need to calculate the step_x, step_y and the initial side distances for the ray. The step_x and step_y variables determine the direction in which the ray moves through the grid
- Step 4: Performing Digital Differential Analysis
The next step is to perform Digital Differential Analysis (DDA) to determine the distance to the next grid line in the x or y direction. This involves stepping through the grid and calculating the distance to the next grid line in each direction
- Step 5: Calculating the Wall Height
The final step is to calculate the height of the wall based on the distance to the wall and the player’s view.