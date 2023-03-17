/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:13 by druina            #+#    #+#             */
/*   Updated: 2023/03/17 13:51:19 by druina           ###   ########.fr       */
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
		return (lenght);
	while (1)
	{
		line = get_next_line_multiple(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) != lenght)
			return (-1);
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

void	check_P_E_X(int *player, int *exit, int *collectible, char *line)
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

void	check_P_E_locations(int *location_x, int *location_y, char *map_lines[],
		char *letter)
{
	int		i;
	int		j;
	char	arr[2];

	arr[1] = '\0';
	i = 0;
	j = 0;
	while (map_lines[j] != '\0')
	{
		while (map_lines[j][i] != '\n')
		{
			arr[0] = map_lines[j][i];
			if (ft_strncmp(arr, letter, 1) == 0)
			{
				(*location_x) = j;
				(*location_y) = i;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int	check_map_content(char *map)
{
	int			fd;
	char		*line;
	int			count;
	t_map_check	check;
	int			map_rows_count;

	check = map_check_init();
	count = 1;
	fd = open(map, O_RDONLY);
	if (fd == -1 || check_rows_lenght(map, 0) == -1)
		return (-1);
	map_rows_count = map_rows(map);
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
		check_P_E_X(&check.player, &check.exit, &check.collectible, line);
		free(line);
		count++;
	}
	if (check.exit != 1 || check.player != 1 || check.collectible < 1)
		return(free_close_exit(fd, NULL, -1));
	if (check_valid_path(map, map_rows_count, "E", 1) == -1)
		return(free_close_exit(fd, NULL, -1));
	if (check_valid_path(map, map_rows_count, "C", check.collectible) == -1)
		return(free_close_exit(fd, NULL, -1));
	return (0);
}
