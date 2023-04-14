/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:26:29 by druina            #+#    #+#             */
/*   Updated: 2023/04/14 09:09:50 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	first_and_last_row(char *line)
{
	int		count;
	char	arr[2];

	arr[1] = '\0';
	count = 0;
	while (*line != '\n')
	{
		if (*line != '0' && *line != '1' && *line != 'C'
			&& *line != 'P' && *line != 'E')
			return (-1);
		arr[0] = *line;
		if (ft_atoi(arr) != 1)
			return (-1);
		count++;
		line++;
	}
	return (count);
}

int	map_rows(char *map)
{
	int		count;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	count = 0;
	while (1)
	{
		line = get_next_line_multiple(fd);
		if (line == NULL)
			break ;
		else
			count++;
		free(line);
	}
	return (count);
}

int	check_rows_lenght(char *map, int flag)
{
	char	*line;
	int		lenght;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line_multiple(fd);
	lenght = ft_strlen(line);
	free(line);
	if (flag == 1)
	{
		return (lenght);
	}
	while (1)
	{
		line = get_next_line_multiple(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) != lenght)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}

int	check_surrounding_wall(char *line)
{
	int		lenght;
	int		count;
	char	arr[2];

	arr[1] = '\0';
	count = 1;
	lenght = ft_strlen(line);
	while (*line != '\n')
	{
		arr[0] = *line;
		if (count == 1 || count == (lenght - 1))
			if (ft_atoi(arr) != 1)
				return (-1);
		line++;
		count++;
	}
	return (count);
}

void	check_p_e_x(int *player, int *exit, int *collectible, char *line)
{
	char	arr[2];

	arr[1] = '\0';
	while (*line != '\n')
	{
		arr[0] = *line;
		if (ft_strncmp(arr, "P", 1) == 0)
			(*player)++;
		if (ft_strncmp(arr, "E", 1) == 0)
			(*exit)++;
		if (ft_strncmp(arr, "C", 1) == 0)
			(*collectible)++;
		line++;
	}
}
