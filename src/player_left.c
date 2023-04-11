/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:55:57 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 10:56:30 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_left3(t_program *program)
{
	mlx_put_image_to_window(program->mlx, program->win,
		program->player.tile_image,
		program->player.pixel_player_x,
		program->player.pixel_player_y);
	mlx_put_image_to_window(program->mlx, program->win,
		program->player.player_left,
		program->player.pixel_player_x,
		program->player.pixel_player_y);
}

void	player_left2(t_program *program)
{
	program->count++;
	program->player.right--;
	program->player.left--;
	if (program->player.left == 1)
		program->player.left_right -= 10;
	mlx_put_image_to_window(program->mlx, program->win,
		program->map_print[program->player.y
		+ 1][program->player.x], program->player.pixel_player_x,
		program->player.pixel_player_y + 96);
	mlx_put_image_to_window(program->mlx, program->win,
		program->map_print[program->player.y
		- 1][program->player.x], program->player.pixel_player_x,
		program->player.pixel_player_y - 96);
	mlx_put_image_to_window(program->mlx, program->win,
		program->map_print[program->player.y][program->player.x
		+ 1], program->player.pixel_player_x + 96,
		program->player.pixel_player_y);
	mlx_put_image_to_window(program->mlx, program->win,
		program->map_print[program->player.y][program->player.x
		- 1], program->player.pixel_player_x - 96,
		program->player.pixel_player_y);
	mlx_put_image_to_window(program->mlx, program->win,
		program->player.tile_image,
		program->player.pixel_player_x,
		program->player.pixel_player_y);
}

void	player_left(t_program *program, int flag, int j, int i)
{
	program->dir = 3;
	if (program->map_2d[program->player.y][program->player.x - 1] != 1)
	{
		if (program->map_2d[program->player.y][program->player.x
			- 1] != flag)
		{
			player_left2(program);
			program->player.x--;
			program->player.pixel_player_x -= 96;
			if (program->player.left == program->player.left_right - 1)
			{
				program->player.pixel_player_x = 864;
				draw_base_on_screen(program->draw_base, program);
				i -= 10;
				print_map(program, program->map_print, j, i);
				program->player.left_right = 11;
				if (program->player.left_right == 11)
					program->player.right += 10;
				program->player.left = 10;
			}
			player_left3(program);
		}
	}
}
