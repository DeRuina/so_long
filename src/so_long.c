/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/04/04 15:36:44 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC 53
#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123
#define FIRE 49



int key_handler(int key, t_program *program)
{
	int flag;
	int i;
	int j;

	if (!program->visited_block[program->player.y][program->player.x])
		program->visited_block[program->player.y][program->player.x] = true;



	j = (program->player.y - program->player.y % 10) - 1;
	i = (program->player.x - program->player.x % 10) -1;
	enemy_movement(&program, j + 1, i + 1);
	flag = 4;
	if (program->player.collect == 0)
		flag = 1;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	// enemy_movement(&program);
	if (key == DOWN )
	{
		// enemy_movement(&program);
		program->dir = 1;
		if (program->map_2d[program->player.y + 1 ][program->player.x] != 1)
		{

		if (program->map_2d[program->player.y + 1 ][program->player.x] != flag)
		{
			program->count++;
			program->player.down++;
			program->player.up++;
			if (program->player.down == 1)
				program->player.up_down += 10;

			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.y++;

			program->player.pixel_player_y += 96;
			if (program->player.down == program->player.up_down)
			{
				program->player.pixel_player_y = 0;
				draw_base(program, program->width, program->elevation);
				j += 10;

				print_map(program, program->map_print, j, i);
				program->player.up_down = 11;
				if (program->player.up > 19)
					program->player.up -= 10;
				program->player.down = 1;


			}
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_down, program->player.pixel_player_x, program->player.pixel_player_y);

			ft_printf("tile is %d\n",  program->map_2d[program->player.y][program->player.x]);
		}
		}
	}
	if (key == UP)
	{
		// enemy_movement(&program);
		program->dir = 2;
	 if (program->map_2d[program->player.y - 1 ][program->player.x] != 1)
	{

		if (program->map_2d[program->player.y - 1 ][program->player.x] != flag)
		{
			program->count++;
			program->player.down--;
			program->player.up--;
			if (program->player.up == 1)
				program->player.up_down -= 10;

			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.y--;

			program->player.pixel_player_y -= 96;
			if (program->player.up == program->player.up_down - 1)
			{
				program->player.pixel_player_y = 864;
				draw_base(program, program->width, program->elevation);
				j -= 10;

				print_map(program, program->map_print, j, i);
				program->player.up_down = 11;
				if (program->player.up_down == 11)
					program->player.down += 10;
				program->player.up = 10;
			}

			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_up, program->player.pixel_player_x, program->player.pixel_player_y);

		}
	}
	}
	if (key == RIGHT )
	{
		// enemy_movement(&program);
		program->dir = 4;
	  if (program->map_2d[program->player.y][program->player.x + 1] != 1)
	{
		if (program->map_2d[program->player.y][program->player.x + 1] != flag)
		{
			program->count++;
			program->player.right++;
			program->player.left++;
			if (program->player.right == 1)
				program->player.left_right += 10;

			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.x++;

			program->player.pixel_player_x += 96;
			if (program->player.right == program->player.left_right)
			{
				program->player.pixel_player_x = 0;
				draw_base(program, program->width, program->elevation);
				i += 10;

				print_map(program, program->map_print, j, i);
				program->player.left_right = 11;
				if (program->player.left > 19)
					program->player.left -= 10;
				program->player.right = 1;

			}
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_right, program->player.pixel_player_x, program->player.pixel_player_y);
		}
	}
	}
	if (key == LEFT )
	{
		// enemy_movement(&program);
		program->dir = 3;
	 if (program->map_2d[program->player.y][program->player.x - 1] != 1)
	{
		if (program->map_2d[program->player.y][program->player.x - 1] != flag)
		{
			program->count++;
			program->player.right--;
			program->player.left--;
			if (program->player.left == 1)
				program->player.left_right -= 10;
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.x--;

			program->player.pixel_player_x -= 96;
			if (program->player.left == program->player.left_right - 1)
			{
				program->player.pixel_player_x = 864;
				draw_base(program, program->width, program->elevation);
				i -= 10;

				print_map(program, program->map_print, j, i);
				program->player.left_right = 11;
				if (program->player.left_right == 11)
					program->player.right += 10;
				program->player.left = 10;

			}
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_left, program->player.pixel_player_x, program->player.pixel_player_y);

		}
	}
	}
	if (key != FIRE)
		ft_printf("%d moves\n", program->count);
	if (program->map_2d[program->player.y][program->player.x] == 5)
		exit(EXIT_SUCCESS);
		// mlx_put_image_to_window(program->mlx, program->win, program->player.game_over, 0, 0);
	if (key == FIRE)
	{
		if (program->dir == 1)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_down, program->player.pixel_player_x, program->player.pixel_player_y + 96);
			if (program->map_2d[program->player.y + 1 ][program->player.x] == 5)
			{
				program->map_2d[program->player.y + 1 ][program->player.x] = 0;
				program->map_print[program->player.y + 1 ][program->player.x] = program->player.tile_image;
			}
		}
		if (program->dir == 2)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_up, program->player.pixel_player_x, program->player.pixel_player_y - 96);
			if (program->map_2d[program->player.y - 1 ][program->player.x] == 5)
			{
				program->map_2d[program->player.y - 1 ][program->player.x] = 0;
				program->map_print[program->player.y - 1 ][program->player.x] = program->player.tile_image;
			}
		}
		if (program->dir == 3)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_left, program->player.pixel_player_x - 96, program->player.pixel_player_y);
		if (program->map_2d[program->player.y][program->player.x - 1] == 5)
			{
				program->map_2d[program->player.y][program->player.x - 1] = 0;
				program->map_print[program->player.y][program->player.x - 1] = program->player.tile_image;
			}
		}
		if (program->dir == 4)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_right, program->player.pixel_player_x + 96, program->player.pixel_player_y);
		if (program->map_2d[program->player.y][program->player.x + 1] == 5)
			{
				program->map_2d[program->player.y][program->player.x + 1] = 0;
				program->map_print[program->player.y][program->player.x + 1] = program->player.tile_image;
			}
		}
	}
	// enemy_movement(&program);
	if (program->map_2d[program->player.y][program->player.x] == 3 && !program->visited_block[program->player.y][program->player.x])
		{
			if (!program->visited_block[program->player.y][program->player.x])
				program->visited_block[program->player.y][program->player.x] = true;
				program->player.collect--;
			program->map_2d[program->player.y][program->player.x] = 0;
			program->map_print[program->player.y][program->player.x] = mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm", &program->width, &program->elevation);
			// ft_printf(" collectable are %d\n", program->player.collect);
		}
	if (program->player.collect == 0 && ((program->player.y - program->player.y % 10) - 1 == j && (program->player.exit_y - program->player.exit_y % 10) - 1 == j) && ((program->player.x - program->player.x % 10) -1 == i && (program->player.exit_x - program->player.exit_x % 10) - 1 == i))
			mlx_put_image_to_window(program->mlx, program->win, program->player.exit_granted, program->player.pixel_exit_x, program->player.pixel_exit_y);
	if (program->map_2d[program->player.y][program->player.x] == 4)
		exit(EXIT_SUCCESS);



	return (0);
}

void enemy_movement(t_program **program, int y, int x)
{
	int i;
	int j;
	int check_down[2];
	x = 0;
	y = 0;
	i = -1;
	j = -1;
	check_down[0] = 0;
	check_down[1] = 0;
	if ((*program)->count % 5 == 0)
	{
		ft_printf("ENTERED ENEMY\n");
		while ((*program)->map_2d[++i] != 0)
		{
			while (++j < (*program)->row_len)
			{
				if ((*program)->map_2d[i][j] == 5 && (*program)->map_2d[i][j] != (*program)->map_2d[check_down[0]][check_down[1]])
				{
					if (i - i % 10 == ((*program)->player.y - (*program)->player.y % 10) && j -j % 10 == ((*program)->player.x - (*program)->player.x % 10))
					{
					  if ((*program)->map_2d[i][j + 1] == 0)
					{
						(*program)->map_2d[i][j] = 0;
						(*program)->map_2d[i][j + 1] = 5;

						(*program)->map_print[i][j] = (*program)->player.tile_image;
						(*program)->map_print[i][j + 1] = (*program)->player.enemy;
							mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.enemy, ((j % 10) + 1) * 96, (i % 10) * 96);
							mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.tile_image, (j % 10) * 96, (i % 10) * 96);
							j++;


					}
					else if ((*program)->map_2d[i + 1][j] == 0)
					{
						(*program)->map_2d[i][j] = 0;
						(*program)->map_2d[i + 1][j] = 5;
						(*program)->map_print[i][j] = (*program)->player.tile_image;
						(*program)->map_print[i + 1][j] = (*program)->player.enemy;
							mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.enemy, (j % 10) * 96, ((i % 10) + 1) * 96);
							mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.tile_image, (j % 10) * 96, (i % 10) * 96);
							check_down[0] = i + 1;
							check_down[1] = j;

					}
					else if ((*program)->map_2d[i][j - 1] == 0)
					{
						(*program)->map_2d[i][j] = 0;
						(*program)->map_2d[i][j - 1] = 5;
						(*program)->map_print[i][j] = (*program)->player.tile_image;
						(*program)->map_print[i][j - 1] = (*program)->player.enemy;
						mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.enemy, ((j % 10) - 1) * 96, (i % 10) * 96);
						mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.tile_image, (j % 10) * 96, (i % 10) * 96);

					}
					else if ((*program)->map_2d[i - 1][j] == 0)
					{
						(*program)->map_2d[i][j] = 0;
						(*program)->map_2d[i - 1][j] = 5;
						(*program)->map_print[i][j] = (*program)->player.tile_image;
						(*program)->map_print[i - 1][j] = (*program)->player.enemy;
						mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.enemy, (j % 10) * 96, ((i % 10) - 1) * 96);
						mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.tile_image, (j % 10) * 96, (i % 10) * 96);

					}
					else
						continue;
					}
				}
			}
			j = -1;
		}

	}

}


int mouse_handler(int key, t_program *program)
{


	program = NULL;
	if (key == 1)
	{
		exit(0);
	}
	if (key == 2)
		ft_printf("CHAKALAK\n");
	return(0);
}

int mouse_movement_handler(int x, int y)
{
	ft_printf("location is %d.%d\n", x, y);
	return(0);
}


int **read_map_to_nbr(char *map)
{
	char	*map_lines[map_rows(map) + 1];
	int		**map_lines_nbr;
	int		fd;
	int		i;
	int		k;
	int		count;

	count = 0;
	k = -1;
	i = -1;
	map_lines_nbr = malloc((map_rows(map) + 1) * sizeof(int *));
	while (++i < (map_rows(map)))
		map_lines_nbr[i] = malloc((check_rows_lenght(map, 1) - 1) * sizeof(int));
	map_lines[map_rows(map)] = 0;
	map_lines_nbr[map_rows(map)] = 0;
	fd = open(map, O_RDONLY);
	i = -1;
	while (i++ < map_rows(map))
		map_lines[i] = get_next_line_multiple(fd);
	i = -1;
	while (map_lines[++i] != 0)
	{
		while (map_lines[i][++k] != '\n')
		{
			if (map_lines[i][k] == '0' && count % 8 == 0)
				map_lines_nbr[i][k] = 5;
			else if (map_lines[i][k] == 'P')
				map_lines_nbr[i][k] = 2;
			else if (map_lines[i][k] == 'C')
				map_lines_nbr[i][k] = 3;
			else if (map_lines[i][k] == 'E')
				map_lines_nbr[i][k] = 4;
			else
				map_lines_nbr[i][k] = map_lines[i][k] - '0';
			if (map_lines[i][k] == '0')
				count++;
		}
		k = -1;
	}
	free_arrays(map_lines, NULL, map_rows(map));
	return (map_lines_nbr);
}

void draw_base(t_program *program, int width, int height)
{
	int		j;
	int 	k;
	int		x;
	void	*map_tiles[(program->rows * program->row_len) + 1];

	j = -1;
	k = -1;
	x = 0;
	map_tiles[program->rows * program->row_len] = 0;
	while (program->map_2d[++j] != 0)
	{
		while (++k < program->row_len)
			map_tiles[x++] = mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm", &width, &height);
		k = -1;
	}
	j = 0;
	k = 0;
	x = 0;
	while (map_tiles[x] != NULL)
	{
		while (program->row_len-- != 0)
		{
			mlx_put_image_to_window(program->mlx, program->win, map_tiles[x++], k, j);
			k += 96;
		}
		k = 0;
		j += 96;
		program->row_len = check_rows_lenght(program->map,1) - 1;
	}
}

t_player player_init(t_program *program)
{
	t_player player;
	int i;
	int j;

	i = -1;
	j = -1;
	player.collect = 0;
	player.pixel_exit_x = 0;
	player.pixel_exit_y = 0;
	player.pixel_player_x = 0;
	player.pixel_player_y = 0;
	player.x = -1;
	player.y = -1;
	player.exit_x = -1;
	player.exit_y = -1;
	player.up_down = 11;
	player.left_right = 11;
	while (program->map_2d[++i] != 0)
	{
		while (++j < program->row_len)
		{
			if (program->map_2d[i][j] == 2)
			{
				player.y = i;
				player.x = j;
				player.pixel_player_y = (i % 10) * 96;
				player.pixel_player_x = (j % 10) * 96;
			}
			if (program->map_2d[i][j] == 3)
				player.collect++;
			if (program->map_2d[i][j] == 4)
			{
				player.exit_y = i;
				player.exit_x = j;
				player.pixel_exit_y = (i % 10) * 96;
				player.pixel_exit_x = (j % 10) * 96;
			}
		}

		j = -1;

	}
	player.up = 1 + (player.y % 10);
	player.down = 1 + (player.y % 10);
	player.left = 1 + (player.x % 10);
	player.right = 1 + (player.x % 10);
	player.collect_array = (int **)malloc(player.collect + 2 * sizeof(int *));
	i = -1;
	j = -1;
	while (++i < player.collect)
		player.collect_array[i] = (int *)malloc(4 * sizeof(int));
	return (player);
}

// t_enemy enemy_init(t_program *program)
// {
// 	t_enemy enemy;
// 	int i;
// 	int j;

// 	i = -1;
// 	j = -1;
// 	enemy.x = 0;
// 	enemy.y = 0;
// 	enemy.pixel_enemy_y = 0;
// 	enemy.pixel_enemy_x = 0;
// 	enemy.x2 = 0;
// 	enemy.y2 = 0;
// 	enemy.pixel_enemy_y2 = 0;
// 	enemy.pixel_enemy_x2 = 0;
// 	enemy.x3 = 0;
// 	enemy.y3 = 0;
// 	enemy.pixel_enemy_y3 = 0;
// 	enemy.pixel_enemy_x3 = 0;
// 	while (program->map_2d[++i] != 0)
// 	{
// 		while (++j < program->row_len)
// 		{
// 			if (program->map_2d[i][j] == 2)
// 			{
// 				player.y = i;
// 				player.x = j;
// 				player.pixel_player_y = (i % 10) * 96;
// 				player.pixel_player_x = (j % 10) * 96;
// 			}
// 			if (program->map_2d[i][j] == 3)
// 				player.collect++;
// 			if (program->map_2d[i][j] == 4)
// 			{
// 				player.exit_y = i;
// 				player.exit_x = j;
// 				player.pixel_exit_y = (i % 10) * 96;
// 				player.pixel_exit_x = (j % 10) * 96;
// 			}
// 		}

// 		j = -1;

// 	}

// 	return (enemy);
// }

void draw_P_and_E(t_program **program)
{
	(*program)->player = player_init((*program));
	// (*program)->enemy = enemy_init((*program));
	(*program)->player.player_image = mlx_xpm_file_to_image((*program)->mlx, "./img/basic96.xpm", &(*program)->width, &(*program)->elevation);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.player_image, (*program)->player.pixel_player_x, (*program)->player.pixel_player_y);
	(*program)->player.exit_image = mlx_xpm_file_to_image((*program)->mlx, "./img/burn_door.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.tile_image = mlx_xpm_file_to_image((*program)->mlx, "./img/grass2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.exit_granted = mlx_xpm_file_to_image((*program)->mlx, "./img/door1.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.water_image = mlx_xpm_file_to_image((*program)->mlx, "./img/water.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.player_right = mlx_xpm_file_to_image((*program)->mlx, "./img/right.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.player_left = mlx_xpm_file_to_image((*program)->mlx, "./img/left.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.player_up = mlx_xpm_file_to_image((*program)->mlx, "./img/up.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.player_down = mlx_xpm_file_to_image((*program)->mlx, "./img/down.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.enemy = mlx_xpm_file_to_image((*program)->mlx, "./img/basic96.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_up = mlx_xpm_file_to_image((*program)->mlx, "./img/fire2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_down = mlx_xpm_file_to_image((*program)->mlx, "./img/fire_down.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_right = mlx_xpm_file_to_image((*program)->mlx, "./img/fire_right.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_left = mlx_xpm_file_to_image((*program)->mlx, "./img/fire_left.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.game_over = mlx_xpm_file_to_image((*program)->mlx, "./img/game_over.xpm", &(*program)->width, &(*program)->elevation);


}

int render(t_program *program)
{
	if (program->win == NULL)
		return (1);
	// enemy_movement(&program);
	mlx_hook(program->win, 2, 1L<<0, &key_handler, program);
	// mlx_key_hook(program->win, &key_handler, program);
	mlx_mouse_hook(program->win, &mouse_handler, program);
	mlx_hook(program->win, 6, 1L<<6, mouse_movement_handler, program);
	return (0);
}

t_program *program_init(int x, int y, char *map)
{
	t_program *program;
	int i;

	i = -1;
	program = malloc( sizeof(t_program));
	program->width = 96;
	program->elevation = 96;
	program->lenght = x;
	program->height = y;
	program->map = map;
	program->count = 0;
	program->dir = 0;
	program->map_2d = read_map_to_nbr(map);
	program->row_len = check_rows_lenght(program->map,1) - 1;
	program->rows = map_rows(program->map);
	program->map_print= NULL;
	program->mlx  = mlx_init();
	program->win = mlx_new_window(program->mlx, program->lenght, program->height, "so long");
	program->visited_block = (int **)ft_calloc(program->rows + 2, sizeof(int *));
	while (i++ != program->rows)
		program->visited_block[i] = ft_calloc((program->row_len +  1), sizeof(int));
	return (program);
}

void ***map_tiles_array(t_program *program, int width, int height)
{
	void	***map_tiles;
	int		j;
	int		k;

	map_tiles = (void ***)malloc((program->rows + 1) * sizeof(void ***));
	j = -1;
	k = -1;
	while (++k < program->rows + 1)
		map_tiles[k] = (void **)malloc((program->row_len) * sizeof(void **));
	k = -1;
	while (++j != program->rows)
	{
		while (++k < program->row_len)
		{
			if (program->map_2d[j][k] == 1)
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/tree2.xpm", &width, &height);
			else if (program->map_2d[j][k] == 4)
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/burn_door.xpm", &width, &height);
			else if (program->map_2d[j][k] == 3)
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/water.xpm", &width, &height);
			else if (program->map_2d[j][k] == 5)
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/basic96.xpm", &width, &height);
			else
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm", &width, &height);
		}
		k = -1;
	}
	return(map_tiles);
}

void ***draw_map(t_program *program, int width, int height)
{
	int		x;
	int		y;
	void ***map_tiles;

	draw_base(program, width, height);
	x = 0;
	y = 0;
	map_tiles = map_tiles_array(program, program->width, program->elevation);
	 y = y - y % 10;
	 x = x - x % 10;
	print_map(program, map_tiles, y - 1, x - 1);
	return(map_tiles);
}

void print_map(t_program *program, void ***map_tiles, int i, int l)
{

	int j;
	int k;
	int x;
	if (i < -1)
		i = -1;
	if (l < -1)
		l = -1;
	j = 0;
	k = 0;
	x = l;
	while (++i < program->rows)
	{
		while (++l < program->row_len)
		{
			mlx_put_image_to_window(program->mlx, program->win, map_tiles[i][l], k, j);
			k += 96;
		}
		k = 0;
		j += 96;
		l = x;
	}
}

int	so_long(int x, int y, char *map)
{

	t_program *program;

	if (x > 960 || y > 960)
	{
		if (x > 960)
			x = 960;
		if (y > 960)
			y = 960;
	}

	program = program_init(x, y, map);
	program->map_print= draw_map(program, (*program).width, (*program).elevation);
	draw_P_and_E(&program);
	mlx_loop_hook((*program).mlx, &render, program);
	mlx_loop((*program).mlx);
	exit(0);
}
