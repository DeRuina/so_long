/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:55:42 by druina            #+#    #+#             */
/*   Updated: 2023/03/23 14:02:55 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error: arg number invalid\n"));
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		return (ft_printf("Error: map file type invalid\n"));
	if (check_map_content(argv[1]) == -1)
		return (ft_printf("Error: map invalid\n"));
	so_long((check_rows_lenght(argv[1], 1) - 1)* 96, map_rows(argv[1]) * 96, argv[1]);
	exit(EXIT_SUCCESS);
}
