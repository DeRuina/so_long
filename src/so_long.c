/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/03/29 10:49:13 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC 53
#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123
#define SHOOT 49



int key_handler(int key, t_program *program)
{
	int flag;
	static int i = -1;



	flag = 4;
	if (program->player.collect == 0)
		flag = 1;
	if (key == ESC)
		exit(EXIT_SUCCESS);

	if (key == DOWN && program->map_2d[program->player.y + 1 ][program->player.x] != 1)
	{
		if (program->map_2d[program->player.y + 1 ][program->player.x] != flag)
		{
			++program->map_up_down;
			ft_printf("up/down %d\n, target is %d\n", program->map_up_down, program->player.up_down);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.y++;
			program->player.pixel_player_y += 96;
			if (program->map_up_down == program->player.up_down)
			{
				program->player.pixel_player_y = 0;
				draw_base(program, program->width, program->elevation);
				print_map(program, program->map_print, 9, -1);

			}
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);
		}

	}
	if (key == UP && program->map_2d[program->player.y - 1 ][program->player.x] != 1)
	{
		if (program->map_2d[program->player.y - 1 ][program->player.x] != flag)
		{
			--program->map_up_down;
			ft_printf("up/down %d\n, target is %d\n", program->map_up_down, (program->player.up_down - 1));
			// draw_base(program, program->width, program->elevation);
			// print_map(program, program->map_print, --program->map_up_down, program->map_right_left);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.y--;
			program->player.pixel_player_y -= 96;
			if (program->map_up_down == program->player.up_down - 1)
			{
				program->player.pixel_player_y = 864;
				draw_base(program, program->width, program->elevation);
				print_map(program, program->map_print, -1, -1);
			}
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);

		}
	}
	if (key == RIGHT && program->map_2d[program->player.y][program->player.x + 1] != 1)
	{
			++program->map_right_left;
			ft_printf("right/left %d\n, target is %d\n", program->map_right_left, program->player.left_right);
		if (program->map_2d[program->player.y][program->player.x + 1] != flag)
		{
			// draw_base(program, program->width, program->elevation);
			// print_map(program, program->map_print, program->map_up_down, ++program->map_right_left);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.x++;
			program->player.pixel_player_x += 96;
			if (program->map_right_left == program->player.left_right)
			{
				program->player.pixel_player_x = 0;
				draw_base(program, program->width, program->elevation);
				i += 10;
				print_map(program, program->map_print, -1, i);
				program->map_right_left = -1;
				program->player.left_right = 9;

			}
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);

		}
	}
	if (key == LEFT && program->map_2d[program->player.y][program->player.x - 1] != 1)
	{
		if (program->map_2d[program->player.y][program->player.x - 1] != flag)
		{
			--program->map_right_left;
			ft_printf("right/left %d\n, target is %d\n", program->map_right_left, (program->player.left_right - 1));
			// draw_base(program, program->width, program->elevation);
			// print_map(program, program->map_print, program->map_up_down, --program->map_right_left);
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.x--;
			program->player.pixel_player_x -= 96;
			if (program->map_right_left == program->player.left_right - 1)
			{
				program->player.pixel_player_x = 864;
				draw_base(program, program->width, program->elevation);
				print_map(program, program->map_print, -1, -1);
			}
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);

		}
	}
	if (program->map_2d[program->player.y][program->player.x] == 3)
		{
			program->player.collect--;
			chnage_value(&program, program->player.y, program->player.x);
		}
	if (program->player.collect == 0)
			mlx_put_image_to_window(program->mlx, program->win, program->player.exit_granted, program->player.pixel_exit_x, program->player.pixel_exit_y);
	if (program->map_2d[program->player.y][program->player.x] == 4)
		exit(EXIT_SUCCESS);



	return (0);
}

void chnage_value(t_program **program, int i, int k)
{
	(*program)->map_2d[i][k] = 0;
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
			if (map_lines[i][k] == 'P')
				map_lines_nbr[i][k] = 2;
			else if (map_lines[i][k] == 'C')
				map_lines_nbr[i][k] = 3;
			else if (map_lines[i][k] == 'E')
				map_lines_nbr[i][k] = 4;
			else
				map_lines_nbr[i][k] = map_lines[i][k] - '0';
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
	while (program->map_2d[++i] != 0)
	{
		while (++j < program->row_len)
		{
			if (program->map_2d[i][j] == 2)
			{
				player.y = i;
				player.x = j;
			}
			if (program->map_2d[i][j] == 3)
				player.collect++;
			if (program->map_2d[i][j] == 4)
			{
				player.exit_y = i;
				player.exit_x = j;
			}
			if (player.x == -1)
				player.pixel_player_x += 96;
			if (player.exit_x == -1)
				player.pixel_exit_x += 96;
		}
		if (player.x == -1)
		{
			player.pixel_player_x = 0;
			player.pixel_player_y += 96;
		}
		if (player.exit_x == -1)
		{
			player.pixel_exit_x = 0;
			player.pixel_exit_y += 96;
		}
		j = -1;

	}
	player.y2 = player.y;
	player.x2 = player.x;
	player.up_down = 9 - player.y2;
	player.left_right = 9 - player.x2;
	return (player);
}

void draw_P_and_E(t_program **program)
{
	(*program)->player = player_init((*program));
	(*program)->player.player_image = mlx_xpm_file_to_image((*program)->mlx, "./img/basic96.xpm", &(*program)->width, &(*program)->elevation);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.player_image, (*program)->player.pixel_player_x, (*program)->player.pixel_player_y);
	(*program)->player.exit_image = mlx_xpm_file_to_image((*program)->mlx, "./img/burn_door.xpm", &(*program)->width, &(*program)->elevation);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.exit_image, (*program)->player.pixel_exit_x, (*program)->player.pixel_exit_y);
	(*program)->player.tile_image = mlx_xpm_file_to_image((*program)->mlx, "./img/grass2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.exit_granted = mlx_xpm_file_to_image((*program)->mlx, "./img/door1.xpm", &(*program)->width, &(*program)->elevation);
}

int render(t_program *program)
{

	if (program->win == NULL)
		return (1);

	// program->player = player_init(program);
	// program->player.player_image = mlx_xpm_file_to_image(program->mlx, "./img/basic96.xpm", &program->width, &program->elevation);
	// mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);
	// program->player.exit_image = mlx_xpm_file_to_image(program->mlx, "./img/burn_door.xpm", &program->width, &program->elevation);
	// mlx_put_image_to_window(program->mlx, program->win, program->player.exit_image, program->player.pixel_exit_x, program->player.pixel_exit_y);
	mlx_key_hook(program->win, &key_handler, program);
	mlx_mouse_hook(program->win, &mouse_handler, program);
	mlx_hook(program->win, 6, 1L<<6, mouse_movement_handler, program);
	return (0);
}

t_program *program_init(int x, int y, char *map)
{
	t_program *program;

	program = malloc( sizeof(t_program));
	program->width = 96;
	program->elevation = 96;
	program->lenght = x;
	program->height = y;
	program->map = map;
	program->map_2d = read_map_to_nbr(map);
	program->row_len = check_rows_lenght(program->map,1) - 1;
	program->rows = map_rows(program->map);
	program->map_print= NULL;
	program->map_up_down = -1;
	program->map_right_left = -1;
	program->mlx  = mlx_init();
	program->win = mlx_new_window(program->mlx, program->lenght, program->height, "so long");
	return (program);
}

void ***draw_map(t_program *program, int width, int height)
{
	int		i;
	int		j;
	int 	k;
	void ***map_tiles;

	map_tiles = (void ***)malloc((program->rows + 1) * sizeof(void ***));

	draw_base(program, width, height);
	j = -1;
	k = -1;
	while (++k < program->rows + 1)
		map_tiles[k] = (void **)malloc((program->row_len) * sizeof(void **));

	k = -1;
	i = 0;
	while (++j != program->rows)
	{
		while (++k < program->row_len)
		{
			if (program->map_2d[j][k] == 1)
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/tree2.xpm", &width, &height);
			else if (program->map_2d[j][k] == 3)
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/water.xpm", &width, &height);
			// else if (program->map_2d[j][k] == 2)
			// 	map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/basic96.xpm", &width, &height);
			else if (program->map_2d[j][k] == 4)
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/burn_door.xpm", &width, &height);
			else
				map_tiles[j][k] = mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm", &width, &height);
		}
		k = -1;
	}

	print_map(program, map_tiles, -1, -1);
	return(map_tiles);
}

void print_map(t_program *program, void ***map_tiles, int i, int l)
{

	int j;
	int k;
	int x;
	// draw_base(program, program->width, program->elevation);
	if (i < -1)
		i = -1;
	if (l < -1)
		l = -1;
	j = 0;
	k = 0;
	x = l;
	// if (program->height > 960)
	// 	program->rows = 10;
	// if (program->lenght > 960)
	// 	program->row_len = 10;
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
	// key_handler(0, program);
	// mlx_mouse_hook(program->win, &mouse_handler, program);
	// // mlx_hook(program.win, 6, 1L<<6, mouse_movement_handler, &program);
	mlx_loop_hook((*program).mlx, &render, program);
	mlx_loop((*program).mlx);
	exit(0);
}
