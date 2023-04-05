/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:38:29 by druina            #+#    #+#             */
/*   Updated: 2023/04/05 17:17:00 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_boundaries(char *map_lines[], int i, int j)
{
	int	x;
	int	y;
	int	k;

	k = 0;
	x = -1;
	y = ft_strlen(map_lines[1]);
	while (map_lines[k++] != 0)
		x++;
	if (i >= 0 && i <= x && j >= 0 && j <= y)
		return (true);
	return (false);
}

t_bool	visiting_blocks(char *map_lines[], int i, int j, int *visited_block[])
{
	if (!visited_block[i - 1][j])
		if (is_a_path(map_lines, i - 1, j, visited_block) == true)
			return (true);
	if (!visited_block[i + 1][j])
		if (is_a_path(map_lines, i + 1, j, visited_block) == true)
			return (true);
	if (!visited_block[i][j - 1])
		if (is_a_path(map_lines, i, j - 1, visited_block) == true)
			return (true);
	if (!visited_block[i][j + 1])
		if (is_a_path(map_lines, i, j + 1, visited_block) == true)
			return (true);
	return (false);
}

t_bool	is_a_path(char *map_lines[], int i, int j, int *visited_block[])
{
	char	arr2[2];
	int		amount;

	arr2[1] = '\0';
	arr2[0] = map_lines[0][0];
	amount = ft_atoi(map_lines[0] + 1);
	if (map_lines[i][j] - '0' == 1)
	{
		visited_block[i][j] = false;
		return (false);
	}
	if (check_boundaries(map_lines, i, j) == true && map_lines[i][j] - '0' != 1
		&& !visited_block[i][j])
		visited_block[i][j] = true;
	if (map_lines[i][j] == map_lines[0][0])
	{
		amount--;
		map_lines[0] = join_and_free_item_and_amount(arr2, amount,
				map_lines[0]);
	}
	if (amount == 0)
		return (true);
	if (visiting_blocks(map_lines, i, j, visited_block) == true)
		return (true);
	return (false);
}

t_bool	check_path_recursion(char *map_lines[], int rows, int lenght,
		int amount)
{
	int		i;
	int		j;
	int		**visited_block;
	char	arr[2];
	t_bool	flag;

	i = -1;
	j = 0;
	visited_block = (int **)ft_calloc(rows + 2, sizeof(int *));
	visited_block[rows + 1] = 0;
	while (i++ != rows)
		visited_block[i] = ft_calloc(lenght, sizeof(int));
	i = 1;
	arr[1] = '\0';
	flag = false;
	while (i < rows)
	{
		while (j < ft_strlen(map_lines[1]) - 1)
		{
			arr[0] = map_lines[i][j];
			if (ft_strncmp(arr, "P", 1) == 0 && !visited_block[i][j])
			{
				while (amount-- != 0)
				{
					if (is_a_path(map_lines, i, j, visited_block) == true)
					{
						flag = true;
						if (amount == 0)
							free_arrays(NULL, visited_block, 0);
					}
					else
						flag = false;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (flag == false)
		free_arrays(NULL, visited_block, 0);
	return (flag);
}

int	check_valid_path(char *map, int rows, char *item, int amount)
{
	int		fd;
	char	**map_lines;
	int		i;
	int		answer;

	i = 0;
	answer = 0;
	map_lines = (char **)malloc((rows + 2) * sizeof(char *));
	map_lines[rows + 1] = 0;
	fd = open(map, O_RDONLY);
	while (i++ < (rows + 1))
		map_lines[i] = get_next_line_multiple(fd);
	map_lines[0] = join_and_free_item_and_amount(item, amount, NULL);
	if (check_path_recursion(map_lines, rows, ft_strlen(map_lines[1]),
			amount) == false)
		answer = -1;
	free_arrays(map_lines, NULL, rows);
	free(map_lines);
	return (answer);
}
