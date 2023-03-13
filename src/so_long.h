/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:35:36 by druina            #+#    #+#             */
/*   Updated: 2023/03/13 11:43:51 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/src/libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct map_check
{
	int		empty_space;
	int		collectible;
	int		exit;
	int		player;

}			t_map_check;

int			main(int argc, char **argv);
int			check_map_content(char *map);
int			first_and_last_row(char *line);
int			map_rows(char *map);
int			check_surrounding_wall(char *line);
int			check_rows_lenght(char *map);
void		check_P_E_X(int *player, int *exit, int *collectible, char *line);
t_map_check	map_check_init(void);
int			free_close_exit(int fd, char *line, int flag);

#endif
