/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:18:37 by druina            #+#    #+#             */
/*   Updated: 2023/04/08 21:43:48 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			{
				if ((*program)->map_2d[i][j] == 5
					&& (*program)->map_2d[i][j] != (*program)->map_2d
						[check_down[0]][check_down[1]])
				{
					if (i - i % 10 == ((*program)->player.y
							- (*program)->player.y % 10) && j - j
						% 10 == ((*program)->player.x - (*program)->player.x
							% 10))
					{
						if ((*program)->map_2d[i][j + 1] == 0)
						{
							(*program)->map_2d[i][j] = 0;
							(*program)->map_2d[i][j + 1] = 5;
							(*program)->map_print[i][j] = (*program)
								->player.tile_image;
							(*program)->map_print[i][j
								+ 1] = (*program)->player.enemy;
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)->player.enemy,
								((j % 10) + 1) * 96, (i % 10) * 96);
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)
								->player.tile_image, (j % 10)
								* 96, (i % 10) * 96);
							j++;
						}
						else if ((*program)->map_2d[i + 1][j] == 0)
						{
							(*program)->map_2d[i][j] = 0;
							(*program)->map_2d[i + 1][j] = 5;
							(*program)->map_print[i][j] = (*program)
								->player.tile_image;
							(*program)->map_print[i
								+ 1][j] = (*program)->player.enemy;
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)->player.enemy,
								(j % 10) * 96, ((i % 10) + 1) * 96);
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)->player.tile_image,
								(j % 10) * 96, (i % 10) * 96);
							check_down[0] = i + 1;
							check_down[1] = j;
						}
						else if ((*program)->map_2d[i][j - 1] == 0)
						{
							(*program)->map_2d[i][j] = 0;
							(*program)->map_2d[i][j - 1] = 5;
							(*program)->map_print[i][j] = (*program)
								->player.tile_image;
							(*program)->map_print[i][j
								- 1] = (*program)->player.enemy;
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)->player.enemy,
								((j % 10) - 1) * 96, (i % 10) * 96);
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)->player.tile_image,
								(j % 10) * 96, (i % 10) * 96);
						}
						else if ((*program)->map_2d[i - 1][j] == 0)
						{
							(*program)->map_2d[i][j] = 0;
							(*program)->map_2d[i - 1][j] = 5;
							(*program)->map_print[i][j] = (*program)
								->player.tile_image;
							(*program)->map_print[i
								- 1][j] = (*program)->player.enemy;
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)->player.enemy,
								(j % 10) * 96, ((i % 10) - 1) * 96);
							mlx_put_image_to_window((*program)->mlx,
								(*program)->win, (*program)->player.tile_image,
								(j % 10) * 96, (i % 10) * 96);
						}
						else
							continue ;
					}
				}
			}
			j = -1;
		}
	}
}
