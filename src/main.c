/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:55:42 by druina            #+#    #+#             */
/*   Updated: 2023/03/10 17:54:36 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error: arg number\n"));
	if (check_map_content(argv[1]) == -1)
		return (ft_printf("Error: map invalid\n"));
	return (EXIT_SUCCESS);
}
