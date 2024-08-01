What to do:

- check leaks
- check norminette
- compiler cc or gcc?

Raycasting Algorithm Explanation
The raycasting algorithm implemented in this project is based on Permadi's raycasting tutorial, a well-known method for rendering a 3D perspective from a 2D grid-based map. This technique is commonly used in first-person games to create the illusion of depth and realism. Here's a detailed explanation of the raycasting algorithm:

Overview
Raycasting works by projecting rays from the player's viewpoint into the game world to determine the distance to the nearest wall. Each ray represents a single vertical slice of the screen. The intersections of these rays with the walls are used to calculate the height and texture of the walls to be drawn, giving the impression of a 3D environment.

Steps of the Algorithm
Initialization:
The player’s position and viewing direction are initialized.
The camera plane is set up to determine the field of view, typically 60 degrees.

Raycasting Loop:
For each vertical stripe of the screen, a ray is cast into the environment.
The direction of each ray is calculated based on the player's viewing direction and the camera plane.

DDA Algorithm (Digital Differential Analyzer):
The DDA algorithm is used to step through the grid cells that the ray intersects.
It determines the initial step and the distance to the next side in the grid, incrementally checking each step until a wall is hit.
The steps are taken in either the x or y direction, based on which distance to the next side is smaller.

Calculate Distance to Wall:
Once a wall is hit, the distance from the player to the wall is calculated. This distance is adjusted to avoid the fish-eye effect, which distorts the view by making walls appear curved.

Determine Wall Height:
The height of the wall slice is calculated based on the distance to the wall. Closer walls appear taller, while distant walls appear shorter, simulating perspective.

Texturing the Walls:
The correct texture for the wall is determined based on the wall’s orientation (north, south, east, or west).
The exact position on the texture is calculated to ensure the correct part of the texture is displayed for the current wall slice.

Rendering:
Each ray determines the color and height of a vertical slice on the screen.
All vertical slices are combined to render the complete frame, creating a realistic 3D view from the player's perspective.
