/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 13:49:33 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	render(t_program *program)
{
	if (program->win == NULL)
		return (1);
	mlx_hook(program->win, 2, 1L << 0, &key_handler, program);
	mlx_hook(program->win, 17, 1L << 17, &press_exit, program);
	return (0);
}

int	so_long(int x, int y, char *map)
{
	t_program	*program;

	if (x > 960 || y > 960)
	{
		if (x > 960)
			x = 960;
		if (y > 960)
			y = 960;
	}
	program = program_init(x, y, map);
	program->map_print = draw_map(program, (*program).width,
			(*program).elevation);
	draw_p_and_e(&program);
	mlx_loop_hook((*program).mlx, &render, program);
	if (program->mlx == NULL)
		exit(0);
	mlx_loop((*program).mlx);
	exit(0);
}
