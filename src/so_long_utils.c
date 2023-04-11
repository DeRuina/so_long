/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:18:37 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 10:00:51 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int key, t_program *program)
{
	int		flag;
	int		i;
	int		j;
	char	*str;

	if (!program->visited_block[program->player.y][program->player.x])
		program->visited_block[program->player.y][program->player.x] = true;
	str = ft_itoa(program->count);
	mlx_put_image_to_window(program->mlx, program->win, program->player.grass,
		0, 0);
	mlx_put_image_to_window(program->mlx, program->win, program->player.tree, 0,
		0);
	mlx_put_image_to_window(program->mlx, program->win, program->player.grass,
		96, 0);
	mlx_put_image_to_window(program->mlx, program->win, program->player.tree,
		96, 0);
	mlx_string_put(program->mlx, program->win, 10, 10, 0xFFFFFF, "MOVEMENT: ");
	mlx_string_put(program->mlx, program->win, 110, 10, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(program->player.collect);
	mlx_string_put(program->mlx, program->win, 10, 40, 0xFFFFFF,
		"NOT COLLECTED: ");
	mlx_string_put(program->mlx, program->win, 150, 40, 0xFFFFFF, str);
	free(str);
	j = (program->player.y - program->player.y % 10) - 1;
	i = (program->player.x - program->player.x % 10) - 1;
	enemy_movement(&program);
	flag = 4;
	if (program->player.collect == 0)
		flag = 1;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == DOWN)
	{
		program->dir = 1;
		if (program->map_2d[program->player.y + 1][program->player.x] != 1)
		{
			if (program->map_2d[program->player.y
					+ 1][program->player.x] != flag)
			{
				program->count++;
				program->player.down++;
				program->player.up++;
				if (program->player.down == 1)
					program->player.up_down += 10;
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
				program->player.y++;
				program->player.pixel_player_y += 96;
				if (program->player.down == program->player.up_down)
				{
					program->player.pixel_player_y = 0;
					draw_base_on_screen(program->draw_base, program);
					j += 10;
					print_map(program, program->map_print, j, i);
					program->player.up_down = 11;
					if (program->player.up > 19)
						program->player.up -= 10;
					program->player.down = 1;
				}
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.tile_image,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.player_down,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
			}
		}
	}
	if (key == UP)
	{
		program->dir = 2;
		if (program->map_2d[program->player.y - 1][program->player.x] != 1)
		{
			if (program->map_2d[program->player.y
					- 1][program->player.x] != flag)
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
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.tile_image,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.player_up,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
			}
		}
	}
	if (key == RIGHT)
	{
		program->dir = 4;
		if (program->map_2d[program->player.y][program->player.x + 1] != 1)
		{
			if (program->map_2d[program->player.y][program->player.x
				+ 1] != flag)
			{
				program->count++;
				program->player.right++;
				program->player.left++;
				if (program->player.right == 1)
					program->player.left_right += 10;
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
				program->player.x++;
				program->player.pixel_player_x += 96;
				if (program->player.right == program->player.left_right)
				{
					program->player.pixel_player_x = 0;
					draw_base_on_screen(program->draw_base, program);
					i += 10;
					print_map(program, program->map_print, j, i);
					program->player.left_right = 11;
					if (program->player.left > 19)
						program->player.left -= 10;
					program->player.right = 1;
				}
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.tile_image,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.player_right,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
			}
		}
	}
	if (key == LEFT)
	{
		program->dir = 3;
		if (program->map_2d[program->player.y][program->player.x - 1] != 1)
		{
			if (program->map_2d[program->player.y][program->player.x
				- 1] != flag)
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
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.tile_image,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
				mlx_put_image_to_window(program->mlx, program->win,
					program->player.player_left,
					program->player.pixel_player_x,
					program->player.pixel_player_y);
			}
		}
	}
	if (key != FIRE)
		if (program->map_2d[program->player.y][program->player.x] == 5)
			exit(EXIT_SUCCESS);
	if (key == FIRE)
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
	if (program->player.collect == 0 && ((program->player.y - program->player.y
				% 10) - 1 == j && (program->player.exit_y
				- program->player.exit_y % 10) - 1 == j) && ((program->player.x
				- program->player.x % 10) - 1 == i && (program->player.exit_x
				- program->player.exit_x % 10) - 1 == i))
		mlx_put_image_to_window(program->mlx, program->win,
			program->player.exit_granted, program->player.pixel_exit_x,
			program->player.pixel_exit_y);
	if (program->map_2d[program->player.y][program->player.x] == 4)
		exit(EXIT_SUCCESS);
	return (0);
}
