/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:35:36 by druina            #+#    #+#             */
/*   Updated: 2023/03/10 18:14:47 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/src/libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct map_check
{
	int	empty_space;
	int	collectible;
	int	exit;
	int	player;

}		t_map_check;

int		main(int argc, char **argv);
int		check_map_content(char *map);
int		first_and_last_row(char *line);
int		map_rows(int fd);
int		check_surrounding_wall(char *line);

#endif
