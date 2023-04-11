/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:44:34 by druina            #+#    #+#             */
/*   Updated: 2023/04/11 13:45:33 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	program_init_2(t_program **program)
{
	(*program)->count = 0;
	(*program)->dir = 0;
	(*program)->j = -1;
	(*program)->k = -1;
	(*program)->width = 96;
	(*program)->elevation = 96;
	(*program)->map_print = NULL;
	(*program)-> draw_base = NULL;
}

t_program	*program_init(int x, int y, char *map)
{
	t_program	*program;
	int			i;

	i = -1;
	program = malloc(sizeof(t_program));
	program_init_2(&program);
	program->lenght = x;
	program->height = y;
	program->map = map;
	program->map_2d = read_map_to_nbr(map);
	program->row_len = check_rows_lenght(program->map, 1) - 1;
	program->rows = map_rows(program->map);
	program->mlx = mlx_init();
	program->win = mlx_new_window(program->mlx, program->lenght,
			program->height, "so long");
	program->visited_block = (int **)ft_calloc(program->rows + 2,
			sizeof(int *));
	while (i++ != program->rows)
		program->visited_block[i] = ft_calloc((program->row_len + 1),
				sizeof(int));
	return (program);
}

void	player_init_2(t_player *player, int y, int x, int flag)
{
	if (flag == 1)
	{
		player->collect = 0;
		player->pixel_exit_x = 0;
		player->pixel_exit_y = 0;
		player->pixel_player_x = 0;
		player->pixel_player_y = 0;
		player->x = -1;
		player->y = -1;
		player->exit_x = -1;
		player->exit_y = -1;
		player->up_down = 11;
		player->left_right = 11;
	}
	else
	{
		player->up = 1 + (y % 10);
		player->down = 1 + (y % 10);
		player->left = 1 + (x % 10);
		player->right = 1 + (x % 10);
	}
}

void	player_init_3(int number, t_player *player, int y, int x)
{
	if (number == 2)
	{
		player->y = y;
		player->x = x;
		player->pixel_player_y = (y % 10) * 96;
		player->pixel_player_x = (x % 10) * 96;
	}
	if (number == 4)
	{
		player->exit_y = y;
		player->exit_x = x;
		player->pixel_exit_y = (y % 10) * 96;
		player->pixel_exit_x = (x % 10) * 96;
	}
}

t_player	player_init(t_program *program)
{
	t_player	player;

	player.x = 0;
	player.y = 0;
	player_init_2(&player, player.y, player.x, 1);
	while (program->map_2d[++program->k] != 0)
	{
		while (++program->j < program->row_len)
		{
			if (program->map_2d[program->k][program->j] == 2)
				player_init_3(2, &player, program->k, program->j);
			if (program->map_2d[program->k][program->j] == 3)
				player.collect++;
			if (program->map_2d[program->k][program->j] == 4)
				player_init_3(4, &player, program->k, program->j);
		}
		program->j = -1;
	}
	player_init_2(&player, player.y, player.x, 0);
	return (player);
}
