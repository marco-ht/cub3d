# cub3D

**"My first RayCaster with miniLibX"**

This repository contains my implementation of the **cub3D** project, developed as part of the 42 School curriculum. This project introduces the fundamentals of ray-casting to create a dynamic 3D view inside a maze from a first-person perspective.

> **Note:** This project is for educational and demonstrative purposes only.

## Table of Contents

- [Overview](#overview)
- [Goals](#goals)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#mandatory-part)
  - [Program Requirements](#program-requirements)
  - [Map Format](#map-format)
  - [Scene Configuration](#scene-configuration)
- [Bonus Part](#bonus-part)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Error Handling](#error-handling)
- [Acknowledgments](#acknowledgments)
- [Disclaimer](#disclaimer)
- [License](#license)

## Overview

**cub3D** is a graphic design project that creates a "realistic" 3D graphical representation of the inside of a maze using ray-casting principles. Ray-casting is the rendering technique that gave birth to several 90s iconic games.

This project serves as an introduction to:
- **Ray-casting algorithms** - creating 3D perspectives from 2D maps
- **Graphics programming** - working with the MiniLibX library
- **Texture mapping** - applying different textures based on wall orientation
- **Event handling** - managing keyboard input and window events
- **Mathematical applications** - using geometry and trigonometry for rendering

## Goals

The objectives of this project are to:
- Improve skills in **window management**, **colors**, **events**, and **graphics rendering**
- Explore the **practical applications of mathematics** in game development
- Understand and implement **ray-casting principles**
- Create elegant and efficient algorithms using mathematical tools
- Build a playable first-person maze navigation experience

## Common Instructions

- **Language & Norm:** The project must be written in C and adhere strictly to the Norm.
- **Allowed Functions:** 
  - Standard functions: `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`, `gettimeofday`
  - All functions from the math library (`-lm`)
  - All functions from the MiniLibX library
- **Makefile Requirements:** Your Makefile must compile your source files using `-Wall`, `-Wextra`, and `-Werror` with `cc`. It should include the rules `NAME`, `all`, `clean`, `fclean`, `re`, and `bonus`.
- **libft:** You may use your own libft library.
- **Memory Management:** All heap-allocated memory must be properly freed. Memory leaks will not be tolerated.
- **Error Handling:** The program must not crash (no segmentation faults, bus errors, or double frees).

## Mandatory Part

### Program Requirements

**Program name:** `cub3D`  
**Arguments:** A scene description file with the `.cub` extension

**Graphics Requirements:**
- Use the MiniLibX library (either OS version or from sources)
- Display different wall textures depending on orientation (North, South, East, West)
- Set floor and ceiling to two different colors
- Smooth window management (switching windows, minimizing, etc.)

**Player Controls:**
- Arrow keys (left/right) - look left and right in the maze
- W, A, S, D keys - move through the maze
- ESC key - close window and quit
- Red cross on window frame - close window and quit

### Map Format

The map must be composed of only 6 possible characters:
- `0` - Empty space
- `1` - Wall
- `N`, `S`, `E`, `W` - Player's starting position and orientation

**Example of a valid map:**
```
111111
100101
101001
1100N1
111111
```

**Map Rules:**
- The map must be closed/surrounded by walls
- If not properly enclosed, the program must return an error
- Spaces are valid parts of the map and must be handled
- The map must always be the last element in the `.cub` file

### Scene Configuration

The `.cub` file must contain the following elements (in any order, except the map which must be last):

**Texture Identifiers:**
- `NO ./path_to_north_texture` - North wall texture
- `SO ./path_to_south_texture` - South wall texture  
- `WE ./path_to_west_texture` - West wall texture
- `EA ./path_to_east_texture` - East wall texture

**Color Identifiers:**
- `F R,G,B` - Floor color (values 0-255)
- `C R,G,B` - Ceiling color (values 0-255)

**Example `.cub` file:**
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**Parsing Rules:**
- Each element type can be separated by one or more empty lines
- Each type of information can be separated by one or more spaces
- If any misconfiguration is found, the program must exit with `"Error\n"` followed by an explicit error message

## Bonus Part

Bonus features will only be evaluated if the mandatory part is perfect.

**Possible bonuses:**
- **Wall collisions** - prevent walking through walls
- **Minimap system** - display a top-down view of the map
- **Doors** - interactive doors that can open and close
- **Animated sprites** - moving or animated objects in the scene
- **Mouse controls** - rotate the point of view with the mouse

*Note: You may add symbols on the map or modify the scene file format to accommodate bonuses, as long as the changes are justified during evaluation.*

## Project Structure

```
cub3D/
├── includes/       # Header files
├── srcs/           # Source files
│   ├── parsing/    # Map and scene parsing
│   ├── raycasting/ # Ray-casting engine
│   ├── rendering/  # Graphics rendering
│   └── utils/      # Utility functions
├── textures/       # Wall texture files (.xpm)
├── maps/           # Scene description files (.cub)
├── libft/          # (Optional) libft sources and Makefile
├── Makefile
└── README.md
```

## Installation

1. **Clone the Repository:**

   ```sh
   git clone https://github.com/marco-ht/cub3D.git
   cd cub3D
   ```

2. **Install MiniLibX:**

   Follow the instructions for your operating system to install MiniLibX, or compile from sources included in the project.

3. **Build the Project:**

   ```sh
   make
   ```

   This command will produce the executable named `cub3D`.

## Usage

Run the program with a `.cub` scene description file:

```sh
./cub3D maps/example.cub
```

**Examples:**
```sh
./cub3D maps/simple_maze.cub
./cub3D maps/complex_maze.cub
```

## Controls

**Movement:**
- `W` - Move forward
- `S` - Move backward
- `A` - Strafe left
- `D` - Strafe right

**Camera:**
- `←` (Left Arrow) - Rotate camera left
- `→` (Right Arrow) - Rotate camera right

**System:**
- `ESC` - Exit the program
- Click `X` on window - Exit the program

## Error Handling

The program handles the following error cases:

- **Invalid map file** - file doesn't exist or can't be opened
- **Wrong file extension** - file doesn't end with `.cub`
- **Invalid map configuration** - map not closed by walls, invalid characters
- **Missing textures** - texture files not found or invalid format
- **Invalid colors** - RGB values out of range [0-255]
- **Duplicate identifiers** - same identifier appears multiple times
- **Missing required elements** - not all textures or colors specified

All errors are reported with:
```
Error
<Descriptive error message>
```

## Acknowledgments

- Thanks to the 42 community, mentors, and fellow students for their guidance and support.
- Special thanks to ray-casting tutorials and mathematical resources that made this project possible.

## Disclaimer

**IMPORTANT**:
This project was developed solely as part of the educational curriculum at 42 School. The code in this repository is published only for demonstration purposes to showcase my programming and graphics development skills.

**Academic Integrity Notice**:
It is strictly prohibited to copy or present this code as your own work in any academic submissions at 42 School. Any misuse or uncredited use of this project will be considered a violation of 42 School's academic policies.

## License

This repository is licensed under the Creative Commons - NonCommercial-NoDerivatives (CC BY-NC-ND 4.0) license. You are free to share this repository as long as you:

- Provide appropriate credit.
- Do not use it for commercial purposes.
- Do not modify, transform, or build upon the material.

For further details, please refer to the CC BY-NC-ND 4.0 license documentation.

Developed with passion and in strict adherence to the high standards of 42 School.
