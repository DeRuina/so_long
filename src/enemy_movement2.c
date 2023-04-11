/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:52:09 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 13:52:35 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
