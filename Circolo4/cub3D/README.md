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
Detailed Steps

Initialization:
The player's direction and position are initialized. The camera plane is also set up to represent the field of view.

DDA Algorithm:
The DDA algorithm calculates the distance from the player’s position to the next grid line in the x or y direction.
It steps through each cell the ray passes through until it hits a wall.
The algorithm increments the ray’s position by the smallest distance to the next grid line, either horizontally or vertically.

Calculating Wall Distance and Height:
Once a wall is hit, the perpendicular distance to the wall is calculated to ensure accurate rendering without distortion.
The wall height is then calculated based on this distance, determining how tall the wall appears on the screen.

Texturing:
The texture coordinates are calculated to map the correct part of the texture to the wall slice.
Adjustments are made based on the side of the wall that is hit to ensure textures are oriented correctly.

Rendering:
After all rays have been cast and wall slices calculated, the frame is rendered by drawing each vertical slice on the screen.
This process creates the final image that simulates a 3D perspective, allowing the player to navigate and view the game world in first-person.

The raycasting algorithm is an efficient way to render a 3D-like environment from a 2D map by casting rays and calculating intersections with walls. This method provides a balance between computational efficiency and visual realism, making it ideal for games that require a first-person perspective.