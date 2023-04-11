/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:50:28 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 13:51:30 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
