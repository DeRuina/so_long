/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:53:35 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 10:54:13 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up3(t_program *program)
{
	mlx_put_image_to_window(program->mlx, program->win,
		program->player.tile_image,
		program->player.pixel_player_x,
		program->player.pixel_player_y);
	mlx_put_image_to_window(program->mlx, program->win,
		program->player.player_up,
		program->player.pixel_player_x,
		program->player.pixel_player_y);
}

void	player_up2(t_program *program)
{
	program->count++;
	program->player.down--;
	program->player.up--;
	if (program->player.up == 1)
		program->player.up_down -= 10;
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

void	player_up(t_program *program, int flag, int j, int i)
{
	program->dir = 2;
	if (program->map_2d[program->player.y - 1][program->player.x] != 1)
	{
		if (program->map_2d[program->player.y
				- 1][program->player.x] != flag)
		{
			player_up2(program);
			program->player.y--;
			program->player.pixel_player_y -= 96;
			if (program->player.up == program->player.up_down - 1)
			{
				program->player.pixel_player_y = 864;
				draw_base_on_screen(program->draw_base, program);
				j -= 10;
				print_map(program, program->map_print, j, i);
				program->player.up_down = 11;
				if (program->player.up_down == 11)
					program->player.down += 10;
				program->player.up = 10;
			}
			player_up3(program);
		}
	}
}
