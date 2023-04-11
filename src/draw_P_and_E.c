/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_P_&_E.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:46:54 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 13:49:55 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
