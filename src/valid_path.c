/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:38:29 by druina            #+#    #+#             */
/*   Updated: 2023/03/15 10:24:32 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_boundaries(char *map_lines[] , int i, int j)
{
	int x;
	int y;
	int k;

	k = 0;
	x = 0;
	y = ft_strlen(map_lines[0]);
	while (map_lines[k++] != '\0')
		x++;
	if (i >= 0 && i <= x &&  j >= 0 && j <= y)
		return (true);
	return (false);
}

bool	is_a_path(char *map_lines[], int i, int j, bool *visited_block[])
{
	char arr[2];
	bool up;
	bool down;
	bool left;
	bool right;

	arr[1] = '\0';
	arr[0] = map_lines[i][j];
	if (ft_strncmp(arr, "1", 1) == 0)
		return (false);
	if (check_boundaries(map_lines, i, j) == true  && ft_strncmp(arr, "1", 1) != 0 && !visited_block[i][j])
		visited_block[i][j] = true;
	if (ft_strncmp(arr, "E", 1) == 0)
		return (true);
	if (!visited_block[i-1][j])
		up = is_a_path(map_lines, i - 1, j, visited_block);
	if (up == true)
		return (true);
	if (!visited_block[i+1][j])
		down = is_a_path(map_lines, i + 1, j, visited_block);
	if (down == true)
		return (true);
	if (!visited_block[i][j - 1])
		left = is_a_path(map_lines, i , j - 1, visited_block);
	if (left == true)
		return (true);
	if (!visited_block[i][j + 1])
		right = is_a_path(map_lines, i , j + 1, visited_block);
	if (right == true)
		return (true);
	return (false);
}

bool	check_path_recursion(char *map_lines[], int rows)
{
	int		i;
	int		j;
	bool	*visited_block[rows];
	char arr[2];

	i = -1;
	j = 0;
	while (i++ != rows -1)
		visited_block[i] = malloc(ft_strlen((map_lines[0]) - 1) * sizeof(bool));
	i = 0;
	arr[1] = '\0';

	while (i < rows)
	{
		while (j < ft_strlen(map_lines[0]) -1)
		{
			arr[0] = map_lines[i][j];
			if (ft_strncmp(arr, "P", 1) == 0 && !visited_block[i][j])
				if (is_a_path(map_lines, i, j, visited_block) == true)
					return (true);
			j++;
		}
		j = 0;
		i++;
	}
		return (false);
}

int	check_valid_path(char *map, int rows)
{
	int		fd;
	char	*map_lines[rows + 1];
	int		i;

	i = -1;
	map_lines[rows] = 0;
	fd = open(map, O_RDONLY);
	while (map_lines[i++] != '\0')
		map_lines[i] = get_next_line_multiple(fd);
	if (check_path_recursion(map_lines, rows) == false)
		return (-1);
	return (0);

}
