/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:38:29 by druina            #+#    #+#             */
/*   Updated: 2023/03/15 14:38:25 by druina           ###   ########.fr       */
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

bool	is_a_path(char *map_lines[], int i, int j, int *visited_block[])
{
	char arr[2];

	arr[1] = '\0';
	arr[0] = map_lines[i][j];
	if (ft_strncmp(arr, "1", 1) == 0)
	{
		visited_block[i][j] = false;
		return (false);
	}
	if (check_boundaries(map_lines, i, j) == true  && ft_strncmp(arr, "1", 1) != 0 && !visited_block[i][j])
		visited_block[i][j] = true;
	if (ft_strncmp(arr, "E", 1) == 0)
		return (true);
	if (!visited_block[i-1][j])
		if (is_a_path(map_lines, i - 1, j, visited_block) == true)
			return (true);
	if (!visited_block[i+1][j])
		if (is_a_path(map_lines, i + 1, j, visited_block) == true)
			return (true);
	if (!visited_block[i][j - 1])
		if (is_a_path(map_lines, i , j - 1, visited_block) == true)
			return (true);
	if (!visited_block[i][j + 1])
		if (is_a_path(map_lines, i , j + 1, visited_block) == true)
			return (true);
	return (false);
}

void free_arrays(char *array[], int *array_int[])
{
	int i;

	i = -1;
	if (array_int == NULL)
	{
	while (array[i++] != '\0')
		free(array[i]);
	}
	if (array == NULL)
	{
		while (array_int[i++] != '\0')
		free(array_int[i]);
	}
}

bool	check_path_recursion(char *map_lines[], int rows, int lenght)
{
	int		i;
	int		j;
	int		*visited_block[rows + 1];
	char 	arr[2];
	bool 	flag;

	i = -1;
	j = 0;
	visited_block[rows] = 0;
	while (i++ != rows -1)
		visited_block[i] = ft_calloc(lenght, sizeof(int));
	i = 0;
	arr[1] = '\0';
	flag = false;
	while (i < rows)
	{
		while (j < ft_strlen(map_lines[0]) -1)
		{
			arr[0] = map_lines[i][j];
			if (ft_strncmp(arr, "P", 1) == 0 && !visited_block[i][j])
				if (is_a_path(map_lines, i, j, visited_block) == true)
				{
					flag = true;
					free_arrays(NULL, visited_block);
				}
			j++;
		}
		j = 0;
		i++;
	}
	if (flag == false)
		free_arrays(NULL, visited_block);
	return (flag);
}

int	check_valid_path(char *map, int rows)
{
	int		fd;
	char	*map_lines[rows + 1];
	int		i;
	int 	answer;

	i = -1;
	answer = 0;
	map_lines[rows] = 0;
	fd = open(map, O_RDONLY);
	while (map_lines[i++] != '\0')
		map_lines[i] = get_next_line_multiple(fd);
	if (check_path_recursion(map_lines, rows, ft_strlen(map_lines[0])) == false)
		answer = -1;
	free_arrays(map_lines, NULL);
	return (answer);

}
