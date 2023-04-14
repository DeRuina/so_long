/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:18:37 by druina            #+#    #+#             */
/*   Updated: 2023/04/14 13:36:54 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keep_score(t_program **program)
{
	char	*str;

	str = ft_itoa((*program)->count);
	mlx_string_put((*program)->mlx, (*program)->win, 10, 10,
		0x000000, "MOVEMENT: ");
	mlx_string_put((*program)->mlx, (*program)->win, 10, 10,
		0xFFFFFF, "MOVEMENT: ");
	mlx_string_put((*program)->mlx, (*program)->win, 110, 10, 0x000000, str);
	mlx_string_put((*program)->mlx, (*program)->win, 110, 10, 0xFFFFFF, str);
	free(str);
	str = ft_itoa((*program)->player.collect);
	mlx_string_put((*program)->mlx, (*program)->win, 10, 40, 0x000000,
		"NOT COLLECTED: ");
	mlx_string_put((*program)->mlx, (*program)->win, 10, 40, 0xFFFFFF,
		"NOT COLLECTED: ");
	mlx_string_put((*program)->mlx, (*program)->win, 150, 40, 0x000000, str);
	mlx_string_put((*program)->mlx, (*program)->win, 150, 40, 0xFFFFFF, str);
	free(str);
}

void	player_collect(t_program *program)
{
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
}

void	assign_map_lines(char **map_lines, int ***map_lines_nbr, int count)
{
	int	i;
	int	k;

	k = -1;
	i = -1;
	while (map_lines[++i] != 0)
	{
		while (map_lines[i][++k] != '\n')
		{
			if (map_lines[i][k] == '0' && count % 8 == 0)
				(*map_lines_nbr)[i][k] = 5;
			else if (map_lines[i][k] == 'P')
				(*map_lines_nbr)[i][k] = 2;
			else if (map_lines[i][k] == 'C')
				(*map_lines_nbr)[i][k] = 3;
			else if (map_lines[i][k] == 'E')
				(*map_lines_nbr)[i][k] = 4;
			else
				(*map_lines_nbr)[i][k] = map_lines[i][k] - '0';
			if (map_lines[i][k] == '0')
				count++;
		}
		k = -1;
	}
}

int	**read_map_to_nbr(char *map)
{
	char	**map_lines;
	int		**map_lines_nbr;
	int		fd;
	int		i;

	i = -1;
	map_lines = (char **)malloc((map_rows(map) + 1) * sizeof(char *));
	if (!map_lines)
		exit(EXIT_FAILURE);
	map_lines_nbr = malloc((map_rows(map) + 1) * sizeof(int *));
	if (!map_lines_nbr)
		exit(EXIT_FAILURE);
	while (++i < (map_rows(map)))
		map_lines_nbr[i] = malloc((check_rows_lenght(map, 1) - 1)
				* sizeof(int));
	map_lines_nbr[map_rows(map)] = 0;
	fd = open(map, O_RDONLY);
	i = -1;
	while (i++ < map_rows(map))
		map_lines[i] = get_next_line_multiple(fd);
	assign_map_lines(map_lines, &map_lines_nbr, 1);
	free_arrays(map_lines, NULL, map_rows(map), NULL);
	free(map_lines);
	return (map_lines_nbr);
}

int	press_exit(void)
{
	exit(0);
}
