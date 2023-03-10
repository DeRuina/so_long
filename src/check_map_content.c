/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:13 by druina            #+#    #+#             */
/*   Updated: 2023/03/10 18:13:08 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	first_and_last_row(char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (ft_atoi(*line) != 1)
			return (-1);
		count++;
		line++;
	}
	return (count);
}

int	map_rows(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else
			count++;
		free(line);
	}
	return (count);
}

int check_surrounding_wall(char *line)
{
	int lenght;
	int count;

	count = 1;
	lenght = ft_strlen(line);
	while (*line)
	{
		if (count == 1 || count == lenght)
			if (ft_atoi(*line) != 1)
				return (-1);
		line++;
		count++;
	}
	return (count);
}

int	check_map_content(char *map)
{
	int			fd;
	char		*line;
	int			count;
	t_map_check	check;
	int			map_rows_count;

	count = 1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	map_rows_count = map_rows(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (count == 1 || count == map_rows_count)
			if (first_and_last_row(line) == -1)
				return (-1);
		if (check_surrounding_wall(line) == -1)
			return(-1);

		free(line);
		count++;
	}
	return (0);
}
