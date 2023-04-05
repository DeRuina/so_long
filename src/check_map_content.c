/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:13 by druina            #+#    #+#             */
/*   Updated: 2023/04/05 15:54:38 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_check	map_check_init(void)
{
	t_map_check	new;

	new.collectible = 0;
	new.empty_space = 0;
	new.exit = 0;
	new.player = 0;
	new.player_x = 0;
	new.player_y = 0;
	new.exit_x = 0;
	new.exit_y = 0;
	return (new);
}

int	free_close_exit(int fd, char *line, int flag)
{
	if (fd != 0)
	{
		close(fd);
		close(fd + 1);
		close(fd + 2);
		close(fd + 3);
	}
	if (line)
		free(line);
	if (flag == -1)
		return (-1);
	else
		return (0);
}

int	check_quanity_and_path(int fd, char *map, int map_rows_count,
		t_map_check *check)
{
	if (check->exit != 1 || check->player != 1 || check->collectible < 1)
		return (free_close_exit(fd, NULL, -1));
	if (check_valid_path(map, map_rows_count, "E", 1) == -1)
		return (free_close_exit(fd, NULL, -1));
	if (check_valid_path(map, map_rows_count, "C", check->collectible) == -1)
		return (free_close_exit(fd, NULL, -1));
	return (0);
}

int	assign(t_map_check *check, char *map, int *fd, int *map_rows_count)
{
	(*check) = map_check_init();
	(*fd) = open(map, O_RDONLY);
	if ((*fd) == -1 || check_rows_lenght(map, 0) == -1)
		return (-1);
	(*map_rows_count) = map_rows(map);
	return (0);
}

int	check_map_content(char *map)
{
	int			fd;
	char		*line;
	int			count;
	t_map_check	check;
	int			map_rows_count;

	count = 1;
	if (assign(&check, map, &fd, &map_rows_count) == -1)
		return (-1);
	while (1)
	{
		line = get_next_line_multiple(fd);
		if (line == NULL)
			break ;
		if (count == 1 || count == map_rows_count)
			if (first_and_last_row(line) == -1)
				return (free_close_exit(fd, line, -1));
		if (check_surrounding_wall(line) == -1)
			return (free_close_exit(fd, line, -1));
		check_p_e_x(&check.player, &check.exit, &check.collectible, line);
		free(line);
		count++;
	}
	return (check_quanity_and_path(fd, map, map_rows_count, &check));
}
