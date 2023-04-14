
# so_long

## Description

My game was made in C with the graphical library [MLX42](https://github.com/codam-coding-college/MLX42)

The goal of the game is to collect all the collectables (water drops), only when you picked them all you can stop the burning door and go through it to exit, Ah ... and try not get killed in the process by some Hitlers, You can burn them though. You're sort of a pyro. You is actually me cuz I use my real face for the main character. If there are any issues with running the game, refer to MLX42 for guidance. 

### How to play
The game is playble with any kind of map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |


* The map must be a rectangle surrounded by walls ‘1’.
* It must have one exit ‘E’, at least one collectable ‘C’, and only one player ‘P’.

See some examples in the ``maps`` folder of this project.

#### Controls
Use arrow key arrows to move. You move one tile at a time. Enemies move randomley every 5 steps of yours, also one tile at a time, and will kill you when you move into their tile or they move into yours. After picking up all water drops, the burning door opens and you may leave succesfully.
Your moves and amount of uncollected waterdrops is showed on the top left of the screen.

You can close the game with ``esc`` or by clicking on the x in the left corner.

## LET ME PLAY ##

```bash
# Clone this project
$ git clone https://github.com/DeRuina/so_long.git

# Access
$ cd so_long

# Compile the program
$ make

# Run the project
$ ./so_long maps/<map of your choice>.ber

```
### Evaluated by 42 

![125/100](img/125.png)


## Author

- [@DeRuina](https://github.com/DeRuina)