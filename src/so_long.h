/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:35:36 by druina            #+#    #+#             */
/*   Updated: 2023/03/15 09:40:08 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/src/libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef enum bool
{
	false,
	true
}			bool;

typedef struct map_check
{
	int		empty_space;
	int		collectible;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;

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
int			check_valid_path(char *map, int rows);
void		check_P_E_locations(int *location_x, int *location_y,
				char *map_lines[], char *letter);
bool		check_path_recursion(char *map_lines[], int rows);
bool		is_a_path(char *map_lines[], int i, int j, bool *visited_block[]);
bool		check_boundaries(char *map_lines[], int i, int j);

#endif
