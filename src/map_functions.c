/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:42:44 by druina            #+#    #+#             */
/*   Updated: 2023/04/14 09:59:08 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!map_tiles)
		exit(EXIT_FAILURE);
	k = -1;
	while (++k < program->rows + 1)
	{
		map_tiles[k] = (void **)malloc((program->row_len) * sizeof(void **));
		if (!map_tiles[k])
			exit(EXIT_FAILURE);
	}
	assign_map_tiles(map_tiles, program, width, height);
	return (map_tiles);
}

void	***draw_map(t_program *program, int width, int height)
{
	int		x;
	int		y;
	void	***map_tiles;

	while (program->map_2d[++program->k] != 0)
	{
		while (++program->j < program->row_len)
		{
			if (program->map_2d[program->k][program->j] == 2)
			{
				y = program->k;
				x = program->j;
				break ;
			}
		}
		program->j = -1;
	}
	program->k = -1;
	program->j = -1;
	program->draw_base = draw_base(program, width, height);
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
