/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:40:16 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 13:52:33 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
