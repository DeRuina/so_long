/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:18:37 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 11:40:55 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keep_score(t_program **program)
{
	char	*str;

	str = ft_itoa((*program)->count);
	mlx_put_image_to_window((*program)->mlx, (*program)->win,
		(*program)->player.grass, 0, 0);
	mlx_put_image_to_window((*program)->mlx, (*program)->win,
		(*program)->player.tree, 0, 0);
	mlx_put_image_to_window((*program)->mlx, (*program)->win,
		(*program)->player.grass, 96, 0);
	mlx_put_image_to_window((*program)->mlx, (*program)->win,
		(*program)->player.tree, 96, 0);
	mlx_string_put((*program)->mlx, (*program)->win, 10, 10,
		0xFFFFFF, "MOVEMENT: ");
	mlx_string_put((*program)->mlx, (*program)->win, 110, 10, 0xFFFFFF, str);
	free(str);
	str = ft_itoa((*program)->player.collect);
	mlx_string_put((*program)->mlx, (*program)->win, 10, 40, 0xFFFFFF,
		"NOT COLLECTED: ");
	mlx_string_put((*program)->mlx, (*program)->win, 150, 40, 0xFFFFFF, str);
	free(str);
}

void	burn_up_and_down(t_program *program)
{
	if (program->dir == 1)
	{
		mlx_put_image_to_window(program->mlx, program->win,
			program->player.fire_down, program->player.pixel_player_x,
			program->player.pixel_player_y + 96);
		if (program->map_2d[program->player.y + 1][program->player.x] == 5)
		{
			program->map_2d[program->player.y + 1][program->player.x] = 0;
			program->map_print[program->player.y
				+ 1][program->player.x] = program->player.poop;
		}
	}
	if (program->dir == 2)
	{
		mlx_put_image_to_window(program->mlx, program->win,
			program->player.fire_up, program->player.pixel_player_x,
			program->player.pixel_player_y - 96);
		if (program->map_2d[program->player.y - 1][program->player.x] == 5)
		{
			program->map_2d[program->player.y - 1][program->player.x] = 0;
			program->map_print[program->player.y
				- 1][program->player.x] = program->player.poop;
		}
	}
}

void	burn_right_and_left(t_program *program)
{
	burn_up_and_down(program);
	if (program->dir == 3)
	{
		mlx_put_image_to_window(program->mlx, program->win,
			program->player.fire_left, program->player.pixel_player_x
			- 96, program->player.pixel_player_y);
		if (program->map_2d[program->player.y][program->player.x - 1] == 5)
		{
			program->map_2d[program->player.y][program->player.x - 1] = 0;
			program->map_print[program->player.y][program->player.x
				- 1] = program->player.poop;
		}
	}
	if (program->dir == 4)
	{
		mlx_put_image_to_window(program->mlx, program->win,
			program->player.fire_right, program->player.pixel_player_x
			+ 96, program->player.pixel_player_y);
		if (program->map_2d[program->player.y][program->player.x + 1] == 5)
		{
			program->map_2d[program->player.y][program->player.x + 1] = 0;
			program->map_print[program->player.y][program->player.x
				+ 1] = program->player.poop;
		}
	}
}

void	exit_granted(t_program *program, int i, int j)
{
	if (program->player.collect == 0 && ((program->player.y - program->player.y
				% 10) - 1 == j && (program->player.exit_y
				- program->player.exit_y % 10) - 1 == j) && ((program->player.x
				- program->player.x % 10) - 1 == i && (program->player.exit_x
				- program->player.exit_x % 10) - 1 == i))
		mlx_put_image_to_window(program->mlx, program->win,
			program->player.exit_granted, program->player.pixel_exit_x,
			program->player.pixel_exit_y);
}

void	player_collect(t_program *program)
{
	if (program->map_2d[program->player.y][program->player.x] == 3
		&& !program->visited_block[program->player.y][program->player.x])
	{
		if (!program->visited_block[program->player.y][program->player.x])
			program->visited_block[program->player.y][program->player.x] = true;
		program->player.collect--;
		program->map_2d[program->player.y][program->player.x] = 0;
		program->map_print[program->player.y][program->player.x]
			= mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm",
				&program->width, &program->elevation);
	}
}

void	key_handler2(int key, t_program *program, int i, int j)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key != FIRE)
		if (program->map_2d[program->player.y][program->player.x] == 5)
			exit(EXIT_SUCCESS);
	if (key == FIRE)
		burn_right_and_left(program);
	player_collect(program);
	exit_granted(program, i, j);
	if (program->map_2d[program->player.y][program->player.x] == 4)
		exit(EXIT_SUCCESS);
}

int	key_handler(int key, t_program *program)
{
	int		flag;
	int		i;
	int		j;

	if (!program->visited_block[program->player.y][program->player.x])
		program->visited_block[program->player.y][program->player.x] = true;
	flag = 4;
	keep_score(&program);
	j = (program->player.y - program->player.y % 10) - 1;
	i = (program->player.x - program->player.x % 10) - 1;
	enemy_movement(&program);
	if (program->player.collect == 0)
		flag = 1;
	if (key == DOWN)
		player_down(program, flag, j, i);
	if (key == UP)
		player_up(program, flag, j, i);
	if (key == RIGHT)
		player_right(program, flag, j, i);
	if (key == LEFT)
		player_left(program, flag, j, i);
	key_handler2(key, program, i, j);
	return (0);
}
