/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:29:31 by druina            #+#    #+#             */
/*   Updated: 2023/04/05 16:30:37 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arrays(char *array[], int *array_int[], int rows)
{
	int	i;

	i = -1;
	if (array_int == NULL)
	{
		while (i++ < rows)
			free(array[i]);
	}
	if (array == NULL)
	{
		while (array_int[i++] != 0)
			free(array_int[i]);
	}
	free(array_int);
}

char	*join_and_free_item_and_amount(char *item, int amount, char *line)
{
	char	*answer;
	char	*temp;
	char	*arr;

	if (line != NULL)
		free(line);
	temp = ft_itoa(amount);
	arr = (char *)malloc(ft_nbrlen(amount) * sizeof(char));
	ft_strlcpy(arr, temp, (ft_strlen(temp) + 1));
	free(temp);
	answer = ft_strjoin(item, arr);
	free(arr);
	return (answer);
}
