/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 09:55:18 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



// int key_handler(int key, t_program *program)
// {
// 	int flag;
// 	int i;
// 	int j;
// 	char *str;

// 	if (!program->visited_block[program->player.y][program->player.x])
// 		program->visited_block[program->player.y][program->player.x] = true;

// 	str = ft_itoa(program->count);
// 	mlx_put_image_to_window(program->mlx, program->win, program->player.grass, 0, 0);
// 	mlx_put_image_to_window(program->mlx, program->win, program->player.tree, 0, 0);
// 	mlx_put_image_to_window(program->mlx, program->win, program->player.grass, 96, 0);
// 	mlx_put_image_to_window(program->mlx, program->win, program->player.tree, 96, 0);
// 	mlx_string_put(program->mlx, program->win, 10, 10, 0xFFFFFF, "MOVEMENT: ");
// 	mlx_string_put(program->mlx, program->win, 110, 10, 0xFFFFFF, str);
// 	free (str);
// 	str = ft_itoa(program->player.collect);
// 	mlx_string_put(program->mlx, program->win, 10, 40, 0xFFFFFF, "NOT COLLECTED: ");
// 	mlx_string_put(program->mlx, program->win, 150, 40, 0xFFFFFF, str);
// 	free (str);
// 	j = (program->player.y - program->player.y % 10) - 1;
// 	i = (program->player.x - program->player.x % 10) -1;
// 	enemy_movement(&program);
// 	flag = 4;
// 	if (program->player.collect == 0)
// 		flag = 1;
// 	if (key == ESC)
// 		exit(EXIT_SUCCESS);
// 	if (key == DOWN )
// 	{
// 		program->dir = 1;
// 		if (program->map_2d[program->player.y + 1 ][program->player.x] != 1)
// 		{

// 		if (program->map_2d[program->player.y + 1 ][program->player.x] != flag)
// 		{
// 			program->count++;
// 			program->player.down++;
// 			program->player.up++;
// 			if (program->player.down == 1)
// 				program->player.up_down += 10;

// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			program->player.y++;

// 			program->player.pixel_player_y += 96;
// 			if (program->player.down == program->player.up_down)
// 			{
// 				program->player.pixel_player_y = 0;
// 				draw_base_on_screen(program->draw_base, program);
// 				j += 10;

// 				print_map(program, program->map_print, j, i);
// 				program->player.up_down = 11;
// 				if (program->player.up > 19)
// 					program->player.up -= 10;
// 				program->player.down = 1;


// 			}
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.player_down, program->player.pixel_player_x, program->player.pixel_player_y);

// 		}
// 		}
// 	}
// 	if (key == UP)
// 	{
// 		program->dir = 2;
// 	 if (program->map_2d[program->player.y - 1 ][program->player.x] != 1)
// 	{

// 		if (program->map_2d[program->player.y - 1 ][program->player.x] != flag)
// 		{
// 			program->count++;
// 			program->player.down--;
// 			program->player.up--;
// 			if (program->player.up == 1)
// 				program->player.up_down -= 10;

// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			program->player.y--;

// 			program->player.pixel_player_y -= 96;
// 			if (program->player.up == program->player.up_down - 1)
// 			{
// 				program->player.pixel_player_y = 864;
// 				draw_base_on_screen(program->draw_base, program);
// 				j -= 10;

// 				print_map(program, program->map_print, j, i);
// 				program->player.up_down = 11;
// 				if (program->player.up_down == 11)
// 					program->player.down += 10;
// 				program->player.up = 10;
// 			}

// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.player_up, program->player.pixel_player_x, program->player.pixel_player_y);

// 		}
// 	}
// 	}
// 	if (key == RIGHT )
// 	{
// 		program->dir = 4;
// 	  if (program->map_2d[program->player.y][program->player.x + 1] != 1)
// 	{
// 		if (program->map_2d[program->player.y][program->player.x + 1] != flag)
// 		{
// 			program->count++;
// 			program->player.right++;
// 			program->player.left++;
// 			if (program->player.right == 1)
// 				program->player.left_right += 10;

// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			program->player.x++;

// 			program->player.pixel_player_x += 96;
// 			if (program->player.right == program->player.left_right)
// 			{
// 				program->player.pixel_player_x = 0;
// 				draw_base_on_screen(program->draw_base, program);
// 				i += 10;

// 				print_map(program, program->map_print, j, i);
// 				program->player.left_right = 11;
// 				if (program->player.left > 19)
// 					program->player.left -= 10;
// 				program->player.right = 1;

// 			}
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.player_right, program->player.pixel_player_x, program->player.pixel_player_y);
// 		}
// 	}
// 	}
// 	if (key == LEFT )
// 	{
// 		program->dir = 3;
// 	 if (program->map_2d[program->player.y][program->player.x - 1] != 1)
// 	{
// 		if (program->map_2d[program->player.y][program->player.x - 1] != flag)
// 		{
// 			program->count++;
// 			program->player.right--;
// 			program->player.left--;
// 			if (program->player.left == 1)
// 				program->player.left_right -= 10;
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y + 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y + 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y - 1][program->player.x], program->player.pixel_player_x, program->player.pixel_player_y - 96);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x + 1], program->player.pixel_player_x + 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->map_print[program->player.y][program->player.x - 1], program->player.pixel_player_x - 96, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			program->player.x--;

// 			program->player.pixel_player_x -= 96;
// 			if (program->player.left == program->player.left_right - 1)
// 			{
// 				program->player.pixel_player_x = 864;
// 				draw_base_on_screen(program->draw_base, program);
// 				i -= 10;

// 				print_map(program, program->map_print, j, i);
// 				program->player.left_right = 11;
// 				if (program->player.left_right == 11)
// 					program->player.right += 10;
// 				program->player.left = 10;

// 			}
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.player_left, program->player.pixel_player_x, program->player.pixel_player_y);

// 		}
// 	}
// 	}
// 	if (key != FIRE)
// 	if (program->map_2d[program->player.y][program->player.x] == 5)
// 		exit(EXIT_SUCCESS);
// 	if (key == FIRE)
// 	{
// 		if (program->dir == 1)
// 		{
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_down, program->player.pixel_player_x, program->player.pixel_player_y + 96);
// 			if (program->map_2d[program->player.y + 1 ][program->player.x] == 5)
// 			{
// 				program->map_2d[program->player.y + 1 ][program->player.x] = 0;
// 				program->map_print[program->player.y + 1 ][program->player.x] = program->player.poop;
// 			}
// 		}
// 		if (program->dir == 2)
// 		{
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_up, program->player.pixel_player_x, program->player.pixel_player_y - 96);
// 			if (program->map_2d[program->player.y - 1 ][program->player.x] == 5)
// 			{
// 				program->map_2d[program->player.y - 1 ][program->player.x] = 0;
// 				program->map_print[program->player.y - 1 ][program->player.x] = program->player.poop;
// 			}
// 		}
// 		if (program->dir == 3)
// 		{
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_left, program->player.pixel_player_x - 96, program->player.pixel_player_y);
// 		if (program->map_2d[program->player.y][program->player.x - 1] == 5)
// 			{
// 				program->map_2d[program->player.y][program->player.x - 1] = 0;
// 				program->map_print[program->player.y][program->player.x - 1] = program->player.poop;
// 			}
// 		}
// 		if (program->dir == 4)
// 		{
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.fire_right, program->player.pixel_player_x + 96, program->player.pixel_player_y);
// 		if (program->map_2d[program->player.y][program->player.x + 1] == 5)
// 			{
// 				program->map_2d[program->player.y][program->player.x + 1] = 0;
// 				program->map_print[program->player.y][program->player.x + 1] = program->player.poop;
// 			}
// 		}
// 	}
// 	if (program->map_2d[program->player.y][program->player.x] == 3 && !program->visited_block[program->player.y][program->player.x])
// 		{
// 			if (!program->visited_block[program->player.y][program->player.x])
// 				program->visited_block[program->player.y][program->player.x] = true;
// 			program->player.collect--;
// 			program->map_2d[program->player.y][program->player.x] = 0;
// 			program->map_print[program->player.y][program->player.x] = mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm", &program->width, &program->elevation);
// 		}
// 	if (program->player.collect == 0 && ((program->player.y - program->player.y % 10) - 1 == j && (program->player.exit_y - program->player.exit_y % 10) - 1 == j) && ((program->player.x - program->player.x % 10) -1 == i && (program->player.exit_x - program->player.exit_x % 10) - 1 == i))
// 			mlx_put_image_to_window(program->mlx, program->win, program->player.exit_granted, program->player.pixel_exit_x, program->player.pixel_exit_y);
// 	if (program->map_2d[program->player.y][program->player.x] == 4)
// 		exit(EXIT_SUCCESS);



// 	return (0);
// }

void	enemy_move_up(t_program **program, int *i, int *j)
{
	(*program)->map_2d[(*i)][(*j)] = 0;
	(*program)->map_2d[(*i) - 1][(*j)] = 5;
	(*program)->map_print[(*i)][(*j)] = (*program)->player.tile_image;
	(*program)->map_print[(*i) - 1][(*j)] = (*program)->player.enemy;
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.enemy, ((*j) % 10) * 96, (((*i) % 10) - 1) * 96);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.tile_image, ((*j) % 10) * 96, ((*i) % 10) * 96);
}

void	enemy_move_left(t_program **program, int *i, int *j)
{
	(*program)->map_2d[(*i)][(*j)] = 0;
	(*program)->map_2d[(*i)][(*j) - 1] = 5;
	(*program)->map_print[(*i)][(*j)] = (*program)->player.tile_image;
	(*program)->map_print[(*i)][(*j) - 1] = (*program)->player.enemy;
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.enemy, (((*j) % 10) - 1) * 96, ((*i) % 10) * 96);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.tile_image, ((*j) % 10) * 96, ((*i) % 10) * 96);
}

void	enemy_move_down(t_program **program, int *i, int *j, int check_down[])
{
	(*program)->map_2d[(*i)][(*j)] = 0;
	(*program)->map_2d[(*i) + 1][(*j)] = 5;
	(*program)->map_print[(*i)][(*j)] = (*program)->player.tile_image;
	(*program)->map_print[(*i) + 1][(*j)] = (*program)->player.enemy;
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.enemy, ((*j) % 10) * 96, (((*i) % 10) + 1) * 96);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.tile_image, ((*j) % 10) * 96, ((*i) % 10) * 96);
	check_down[0] = (*i) + 1;
	check_down[1] = (*j);
}

void	enemy_move_right(t_program **program, int *i, int *j)
{
	(*program)->map_2d[(*i)][(*j)] = 0;
	(*program)->map_2d[(*i)][(*j) + 1] = 5;
	(*program)->map_print[(*i)][(*j)] = (*program)->player.tile_image;
	(*program)->map_print[(*i)][(*j) + 1] = (*program)->player.enemy;
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.enemy, (((*j) % 10) + 1) * 96, ((*i) % 10) * 96);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)
		->player.tile_image, ((*j) % 10) * 96, ((*i) % 10) * 96);
	(*j)++;
}

void	enemy_movement2(t_program **program, int *i, int *j, int check_down[])
{
	if ((*program)->map_2d[(*i)][(*j)] == 5 && (*program)->map_2d[(*i)][(*j)]
		!= (*program)->map_2d[check_down[0]][check_down[1]])
	{
		if ((*i) - (*i) % 10 == ((*program)->player.y - (*program)
				->player.y % 10) && (*j) - (*j) % 10 == ((*program)->player.x
				- (*program)->player.x % 10))
		{
			if ((*program)->map_2d[(*i)][(*j) + 1] == 0)
				enemy_move_right(program, i, j);
			else if ((*program)->map_2d[(*i) + 1][(*j)] == 0)
				enemy_move_down(program, i, j, check_down);
			else if ((*program)->map_2d[(*i)][(*j) - 1] == 0)
				enemy_move_left(program, i, j);
			else if ((*program)->map_2d[(*i) - 1][(*j)] == 0)
				enemy_move_up(program, i, j);
		}
	}
}

void	enemy_movement(t_program **program)
{
	int	i;
	int	j;
	int	check_down[2];

	i = -1;
	j = -1;
	check_down[0] = 0;
	check_down[1] = 0;
	if ((*program)->count % 5 == 0)
	{
		while ((*program)->map_2d[++i] != 0)
		{
			while (++j < (*program)->row_len)
				enemy_movement2(program, &i, &j, check_down);
			j = -1;
		}
	}
}


void	assign_map_lines(char **map_lines, int ***map_lines_nbr, int count)
{
	int	i;
	int	k;

	k = -1;
	i = -1;
	while (map_lines[++i] != 0)
	{
		while (map_lines[i][++k] != '\n')
		{
			if (map_lines[i][k] == '0' && count % 8 == 0)
				(*map_lines_nbr)[i][k] = 5;
			else if (map_lines[i][k] == 'P')
				(*map_lines_nbr)[i][k] = 2;
			else if (map_lines[i][k] == 'C')
				(*map_lines_nbr)[i][k] = 3;
			else if (map_lines[i][k] == 'E')
				(*map_lines_nbr)[i][k] = 4;
			else
				(*map_lines_nbr)[i][k] = map_lines[i][k] - '0';
			if (map_lines[i][k] == '0')
				count++;
		}
		k = -1;
	}
}

int	**read_map_to_nbr(char *map)
{
	char	**map_lines;
	int		**map_lines_nbr;
	int		fd;
	int		i;
	int		count;

	count = 0;
	i = -1;
	map_lines = (char **)malloc((map_rows(map) + 1) * sizeof(char *));
	map_lines_nbr = malloc((map_rows(map) + 1) * sizeof(int *));
	while (++i < (map_rows(map)))
		map_lines_nbr[i] = malloc((check_rows_lenght(map, 1) - 1)
				* sizeof(int));
	map_lines_nbr[map_rows(map)] = 0;
	fd = open(map, O_RDONLY);
	i = -1;
	while (i++ < map_rows(map))
		map_lines[i] = get_next_line_multiple(fd);
	assign_map_lines(map_lines, &map_lines_nbr, count);
	free_arrays(map_lines, NULL, map_rows(map), NULL);
	free(map_lines);
	return (map_lines_nbr);
}

void	draw_base_on_screen(void **map_tiles, t_program *program)
{
	int	j;
	int	k;
	int	x;

	j = 0;
	k = 0;
	x = 0;
	while (map_tiles[x] != NULL)
	{
		while (program->row_len-- != 0)
		{
			mlx_put_image_to_window(program->mlx, program->win, map_tiles[x++],
				k, j);
			k += 96;
		}
		k = 0;
		j += 96;
		program->row_len = check_rows_lenght(program->map, 1) - 1;
	}
}

void	**draw_base(t_program *program, int width, int height)
{
	int		j;
	int		k;
	int		x;
	void	**map_tiles;

	j = -1;
	k = -1;
	x = 0;
	map_tiles = ft_calloc((program->rows * program->row_len) + 1,
			sizeof(void *));
	map_tiles[program->rows * program->row_len] = 0;
	while (program->map_2d[++j] != 0)
	{
		while (++k < program->row_len)
			map_tiles[x++] = mlx_xpm_file_to_image(program->mlx,
					"./img/grass2.xpm", &width, &height);
		k = -1;
	}
	draw_base_on_screen(map_tiles, program);
	return (map_tiles);
}

void	player_init_2(t_player *player, int y, int x, int flag)
{
	if (flag == 1)
	{
		player->collect = 0;
		player->pixel_exit_x = 0;
		player->pixel_exit_y = 0;
		player->pixel_player_x = 0;
		player->pixel_player_y = 0;
		player->x = -1;
		player->y = -1;
		player->exit_x = -1;
		player->exit_y = -1;
		player->up_down = 11;
		player->left_right = 11;
	}
	else
	{
		player->up = 1 + (y % 10);
		player->down = 1 + (y % 10);
		player->left = 1 + (x % 10);
		player->right = 1 + (x % 10);
	}
}

void	player_init_3(int number, t_player *player, int y, int x)
{
	if (number == 2)
	{
		player->y = y;
		player->x = x;
		player->pixel_player_y = (y % 10) * 96;
		player->pixel_player_x = (x % 10) * 96;
	}
	if (number == 4)
	{
		player->exit_y = y;
		player->exit_x = x;
		player->pixel_exit_y = (y % 10) * 96;
		player->pixel_exit_x = (x % 10) * 96;
	}
}

t_player	player_init(t_program *program)
{
	t_player	player;

	player.x = 0;
	player.y = 0;
	player_init_2(&player, player.y, player.x, 1);
	while (program->map_2d[++program->k] != 0)
	{
		while (++program->j < program->row_len)
		{
			if (program->map_2d[program->k][program->j] == 2)
				player_init_3(2, &player, program->k, program->j);
			if (program->map_2d[program->k][program->j] == 3)
				player.collect++;
			if (program->map_2d[program->k][program->j] == 4)
				player_init_3(4, &player, program->k, program->j);
		}
		program->j = -1;
	}
	player_init_2(&player, player.y, player.x, 0);
	return (player);
}


void	draw_p_and_e_2(t_program **program)
{
	(*program)->player.player_down = mlx_xpm_file_to_image((*program)->mlx,
			"./img/down.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.enemy = mlx_xpm_file_to_image((*program)->mlx,
			"./img/hitler.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_up = mlx_xpm_file_to_image((*program)->mlx,
			"./img/fire2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_down = mlx_xpm_file_to_image((*program)->mlx,
			"./img/fire_down.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_right = mlx_xpm_file_to_image((*program)->mlx,
			"./img/fire_right.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.fire_left = mlx_xpm_file_to_image((*program)->mlx,
			"./img/fire_left.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.game_over = mlx_xpm_file_to_image((*program)->mlx,
			"./img/game_over.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.grass = mlx_xpm_file_to_image((*program)->mlx,
			"./img/grass2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.tree = mlx_xpm_file_to_image((*program)->mlx,
			"./img/tree2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.poop = mlx_xpm_file_to_image((*program)->mlx,
			"./img/poop.xpm", &(*program)->width, &(*program)->elevation);
}

void	draw_p_and_e(t_program **program)
{
	(*program)->player = player_init((*program));
	(*program)->player.player_image = mlx_xpm_file_to_image((*program)->mlx,
			"./img/basic96.xpm", &(*program)->width, &(*program)->elevation);
	mlx_put_image_to_window((*program)->mlx, (*program)->win,
		(*program)->player.player_image, (*program)->player.pixel_player_x,
		(*program)->player.pixel_player_y);
	(*program)->player.exit_image = mlx_xpm_file_to_image((*program)->mlx,
			"./img/burn_door.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.tile_image = mlx_xpm_file_to_image((*program)->mlx,
			"./img/grass2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.exit_granted = mlx_xpm_file_to_image((*program)->mlx,
			"./img/door1.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.water_image = mlx_xpm_file_to_image((*program)->mlx,
			"./img/water.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.player_right = mlx_xpm_file_to_image((*program)->mlx,
			"./img/right.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.player_left = mlx_xpm_file_to_image((*program)->mlx,
			"./img/left.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.player_up = mlx_xpm_file_to_image((*program)->mlx,
			"./img/up.xpm", &(*program)->width, &(*program)->elevation);
	draw_p_and_e_2(program);
}


int	press_exit(void)
{
	exit(0);
}

int	render(t_program *program)
{
	if (program->win == NULL)
		return (1);
	mlx_hook(program->win, 2, 1L << 0, &key_handler, program);
	mlx_hook(program->win, 17, 1L << 17, &press_exit, program);
	return (0);
}

void	program_init_2(t_program **program)
{
	(*program)->count = 0;
	(*program)->dir = 0;
	(*program)->j = -1;
	(*program)->k = -1;
	(*program)->width = 96;
	(*program)->elevation = 96;
	(*program)->map_print = NULL;
	(*program)-> draw_base = NULL;
}

t_program	*program_init(int x, int y, char *map)
{
	t_program	*program;
	int			i;

	i = -1;
	program = malloc(sizeof(t_program));
	program_init_2(&program);
	program->lenght = x;
	program->height = y;
	program->map = map;
	program->map_2d = read_map_to_nbr(map);
	program->row_len = check_rows_lenght(program->map, 1) - 1;
	program->rows = map_rows(program->map);
	program->mlx = mlx_init();
	program->win = mlx_new_window(program->mlx, program->lenght,
			program->height, "so long");
	program->visited_block = (int **)ft_calloc(program->rows + 2,
			sizeof(int *));
	while (i++ != program->rows)
		program->visited_block[i] = ft_calloc((program->row_len + 1),
				sizeof(int));
	return (program);
}

void	assign_map_tiles(void ***map_tiles, t_program *program, int width,
		int height)
{
	while (++program->j != program->rows)
	{
		while (++program->k < program->row_len)
		{
			if (program->map_2d[program->j][program->k] == 1)
				map_tiles[program->j][program->k] = mlx_xpm_file_to_image
					(program->mlx, "./img/tree2.xpm", &width, &height);
			else if (program->map_2d[program->j][program->k] == 4)
				map_tiles[program->j][program->k] = mlx_xpm_file_to_image
					(program->mlx, "./img/burn_door.xpm", &width, &height);
			else if (program->map_2d[program->j][program->k] == 3)
				map_tiles[program->j][program->k] = mlx_xpm_file_to_image
					(program->mlx, "./img/water.xpm", &width, &height);
			else if (program->map_2d[program->j][program->k] == 5)
				map_tiles[program->j][program->k] = mlx_xpm_file_to_image
					(program->mlx, "./img/hitler.xpm", &width, &height);
			else
				map_tiles[program->j][program->k] = mlx_xpm_file_to_image
					(program->mlx, "./img/grass2.xpm", &width, &height);
		}
		program->k = -1;
	}
}

void	***map_tiles_array(t_program *program, int width, int height)
{
	void	***map_tiles;
	int		k;

	map_tiles = (void ***)malloc((program->rows + 1) * sizeof(void ***));
	k = -1;
	while (++k < program->rows + 1)
		map_tiles[k] = (void **)malloc((program->row_len) * sizeof(void **));
	assign_map_tiles(map_tiles, program, width, height);
	return (map_tiles);
}


void	***draw_map(t_program *program, int width, int height)
{
	int		x;
	int		y;
	void	***map_tiles;

	program->draw_base = draw_base(program, width, height);
	x = 0;
	y = 0;
	map_tiles = map_tiles_array(program, program->width, program->elevation);
	y = y - y % 10;
	x = x - x % 10;
	print_map(program, map_tiles, y - 1, x - 1);
	return (map_tiles);
}

void	print_map(t_program *program, void ***map_tiles, int i, int l)
{
	int	j;
	int	k;
	int	x;

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
			mlx_put_image_to_window(program->mlx, program->win, map_tiles[i][l],
				k, j);
			k += 96;
		}
		k = 0;
		j += 96;
		l = x;
	}
}

int	so_long(int x, int y, char *map)
{
	t_program	*program;

	if (x > 960 || y > 960)
	{
		if (x > 960)
			x = 960;
		if (y > 960)
			y = 960;
	}
	program = program_init(x, y, map);
	program->map_print = draw_map(program, (*program).width,
			(*program).elevation);
	draw_p_and_e(&program);
	mlx_loop_hook((*program).mlx, &render, program);
	if (program->mlx == NULL)
		exit(0);
	mlx_loop((*program).mlx);
	exit(0);
}
