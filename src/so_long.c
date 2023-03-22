/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/03/22 14:52:13 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC 53
#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123
#define SHOOT 49

typedef struct player
{
	int y;
	int x;
	int exit_y;
	int exit_x;
	int collect;
	int pixel_player_y;
	int pixel_player_x;
	void *player_image;
	void *exit_image;
	void *tile_image;
	void *exit_granted;
	int pixel_exit_y;
	int pixel_exit_x;
}			t_player;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct program
	{
    	void *mlx;
   		void *win;
		t_img img;
		int height;
		int lenght;
		char *map;
		int **map_2d;
		int width;
		int elevation;
		int row_len;
		t_player player;
	}          t_program;

void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int key_handler(int key, t_program *program)
{
	int flag;

	flag = 4;
	if (program->player.collect == 0)
		flag = 1;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == DOWN && program->map_2d[program->player.y + 1 ][program->player.x] != 1)
	{
		ft_printf("%d\n", flag);
		if (program->map_2d[program->player.y + 1 ][program->player.x] != flag)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.y++;
			program->player.pixel_player_y += 96;
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);
		}
		if (program->map_2d[program->player.y][program->player.x] == 3)
		{
			program->player.collect--;
			program->map_2d[program->player.y][program->player.x] = 0;
		}

	}
	if (key == UP && program->map_2d[program->player.y - 1 ][program->player.x] != 1)
	{
		ft_printf("%d\n", flag);
		if (program->map_2d[program->player.y - 1 ][program->player.x] != flag)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.y--;
			program->player.pixel_player_y -= 96;
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);
		}
		if (program->map_2d[program->player.y][program->player.x] == 3)
		{
			program->player.collect--;
			program->map_2d[program->player.y][program->player.x] = 0;
		}




	}
	if (key == RIGHT && program->map_2d[program->player.y][program->player.x + 1] != 1)
	{
		ft_printf("%d\n", flag);
		if (program->map_2d[program->player.y][program->player.x + 1] != flag)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.x++;
			program->player.pixel_player_x += 96;
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);
		}
		if (program->map_2d[program->player.y][program->player.x] == 3)
		{
			program->player.collect--;
			program->map_2d[program->player.y][program->player.x] = 0;
		}
		/


	}
	if (key == LEFT && program->map_2d[program->player.y][program->player.x - 1] != 1)
	{
		ft_printf("%d\n", flag);
		if (program->map_2d[program->player.y][program->player.x - 1] != flag)
		{
			mlx_put_image_to_window(program->mlx, program->win, program->player.tile_image, program->player.pixel_player_x, program->player.pixel_player_y);
			program->player.x--;
			program->player.pixel_player_x -= 96;
			mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);
		}
		if (program->map_2d[program->player.y][program->player.x] == 3)
		{
			program->player.collect--;
			program->map_2d[program->player.y][program->player.x] = 0;
		}


	}
	if (program->player.collect == 0)
			mlx_put_image_to_window(program->mlx, program->win, program->player.exit_granted, program->player.pixel_exit_x, program->player.pixel_exit_y);
	if (program->map_2d[program->player.y][program->player.x] == 4)
		exit(EXIT_SUCCESS);



	return (0);
}

int mouse_handler(int key, void *param)
{


	param = NULL;
	if (key == 1)
	{
		ft_printf("BOOM\n");
		exit(0);
	}
	if (key == 2)
		ft_printf("CHAKALAK\n");
	return(0);
}

int mouse_movement_handler(int x, int y)
{
	ft_printf("location is %d.%d\n", x, y);
	return(0);
}

void	render_background(t_img *img, int color, int x, int y)
	{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
			img_pix_put(img, j++, i, color);
		++i;
	}
	}

t_img create_image(t_program *program, int x, int y)
{
	t_img image;

	image.mlx_img = mlx_new_image(program->mlx, x, y);
	image.addr= mlx_get_data_addr(image.mlx_img, &image.bpp, &image.line_len, &image.endian);
	return (image);
}

int **read_map_to_nbr(char *map)
{
	char	*map_lines[map_rows(map) + 1];
	int		**map_lines_nbr;
	int		fd;
	int		i;
	int		k;


	k = -1;
	i = -1;
	map_lines_nbr = malloc((map_rows(map) + 1) * sizeof(int *));
	while (++i < (map_rows(map) + 1))
		map_lines_nbr[i] = malloc((check_rows_lenght(map, 1) - 1) * sizeof(int));
	map_lines[map_rows(map)] = 0;
	map_lines_nbr[map_rows(map)] = 0;
	fd = open(map, O_RDONLY);
	i = -1;
	while (i++ < map_rows(map))
		map_lines[i] = get_next_line_multiple(fd);
	i = -1;
	while (map_lines[++i] != 0)
	{
		while (map_lines[i][++k] != '\n')
		{
			if (map_lines[i][k] == 'P')
				map_lines_nbr[i][k] = 2;
			else if (map_lines[i][k] == 'C')
				map_lines_nbr[i][k] = 3;
			else if (map_lines[i][k] == 'E')
				map_lines_nbr[i][k] = 4;
			else
				map_lines_nbr[i][k] = map_lines[i][k] - '0';
		}
		k = -1;
	}
	free_arrays(map_lines, NULL);
	return (map_lines_nbr);
}

void draw_base(t_program *program, int width, int height)
{
	int		j;
	int 	k;
	int		x;
	int 	y;
	void 	*temp;

	j = -1;
	k = -1;
	x = 0;
	y = 0;
	while (program->map_2d[++j] != 0)
	{
		while (++k < program->row_len)
		{
			temp = mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm", &width, &height);
			mlx_put_image_to_window(program->mlx, program->win, temp, x, y);
			free(temp);
			x += 96;
		}
		x = 0;
		y += 96;
		k = -1;
	}

}

void draw_map(t_program *program, int width, int height)
{
	int		i;
	int		j;
	int 	k;
	void	*map_tiles[(map_rows(program->map) * (check_rows_lenght(program->map,1) - 1)) + 1];


	draw_base(program, width, height);
	i = -1;
	j = -1;
	k = -1;
	map_tiles[(map_rows(program->map) * (check_rows_lenght(program->map,1) - 1))] = 0;
	i = 0;
	while (program->map_2d[++j] != 0)
	{
		while (++k < program->row_len)
		{
			if (program->map_2d[j][k] == 1)
				map_tiles[i++] = mlx_xpm_file_to_image(program->mlx, "./img/tree2.xpm", &width, &height);
			else if (program->map_2d[j][k] == 3)
				map_tiles[i++] = mlx_xpm_file_to_image(program->mlx, "./img/water.xpm", &width, &height);
			// else if (program->map_2d[j][k] == 4)
			// 	map_tiles[i++] = mlx_xpm_file_to_image(program->mlx, "./img/burn_door.xpm", &width, &height);
			// else if (program->map_2d[j][k] == 2)
			// 	map_tiles[i++] = mlx_xpm_file_to_image(program->mlx, "./img/basic96.xpm", &width, &height);
			else
				map_tiles[i++] = mlx_xpm_file_to_image(program->mlx, "./img/grass2.xpm", &width, &height);
		}
		k = -1;
	}
	i = 0;
	j = 0;
	k = 0;

	while (map_tiles[i] != NULL)
	{
		while (program->row_len-- != 0)
		{
			mlx_put_image_to_window(program->mlx, program->win, map_tiles[i++], k, j);
			k += 96;
		}
		k = 0;
		j += 96;
		program->row_len = check_rows_lenght(program->map,1) - 1;
	}

}

t_player player_init(t_program *program)
{
	t_player player;
	int i;
	int j;

	i = -1;
	j = -1;
	player.collect = 0;
	player.pixel_exit_x = 0;
	player.pixel_exit_y = 0;
	player.pixel_player_x = 0;
	player.pixel_player_y = 0;
	player.x = -1;
	player.y = -1;
	player.exit_x = -1;
	player.exit_y = -1;
	while (program->map_2d[++i] != 0)
	{
		while (++j < program->row_len)
		{
			if (program->map_2d[i][j] == 2)
			{
				player.y = i;
				player.x = j;
			}
			if (program->map_2d[i][j] == 3)
				player.collect++;
			if (program->map_2d[i][j] == 4)
			{
				player.exit_y = i;
				player.exit_x = j;
			}
			if (player.x == -1)
				player.pixel_player_x += 96;
			if (player.exit_x == -1)
				player.pixel_exit_x += 96;
		}
		if (player.x == -1)
		{
			player.pixel_player_x = 0;
			player.pixel_player_y += 96;
		}
		if (player.exit_x == -1)
		{
			player.pixel_exit_x = 0;
			player.pixel_exit_y += 96;
		}
		j = -1;

	}
	return (player);
}

void draw_P_and_E(t_program **program)
{
	(*program)->player = player_init((*program));
	(*program)->player.player_image = mlx_xpm_file_to_image((*program)->mlx, "./img/basic96.xpm", &(*program)->width, &(*program)->elevation);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.player_image, (*program)->player.pixel_player_x, (*program)->player.pixel_player_y);
	(*program)->player.exit_image = mlx_xpm_file_to_image((*program)->mlx, "./img/burn_door.xpm", &(*program)->width, &(*program)->elevation);
	mlx_put_image_to_window((*program)->mlx, (*program)->win, (*program)->player.exit_image, (*program)->player.pixel_exit_x, (*program)->player.pixel_exit_y);
	(*program)->player.tile_image = mlx_xpm_file_to_image((*program)->mlx, "./img/grass2.xpm", &(*program)->width, &(*program)->elevation);
	(*program)->player.exit_granted = mlx_xpm_file_to_image((*program)->mlx, "./img/door1.xpm", &(*program)->width, &(*program)->elevation);
}

int render(t_program *program)
{

	if (program->win == NULL)
		return (1);

	// program->player = player_init(program);
	// program->player.player_image = mlx_xpm_file_to_image(program->mlx, "./img/basic96.xpm", &program->width, &program->elevation);
	// mlx_put_image_to_window(program->mlx, program->win, program->player.player_image, program->player.pixel_player_x, program->player.pixel_player_y);
	// program->player.exit_image = mlx_xpm_file_to_image(program->mlx, "./img/burn_door.xpm", &program->width, &program->elevation);
	// mlx_put_image_to_window(program->mlx, program->win, program->player.exit_image, program->player.pixel_exit_x, program->player.pixel_exit_y);
	mlx_key_hook(program->win, &key_handler, program);
	mlx_mouse_hook(program->win, &mouse_handler, program);
	mlx_hook(program->win, 6, 1L<<6, mouse_movement_handler, program);
	return (0);
}

t_program *program_init(int x, int y, char *map)
{
	t_program *program;

	program = malloc( sizeof(t_program));
	program->width = 96;
	program->elevation = 96;

	program->lenght = x;
	program->height = y;
	program->map = map;
	program->map_2d = read_map_to_nbr(map);
	program->row_len = check_rows_lenght(program->map,1) - 1;
	program->mlx  = mlx_init();
	program->win = mlx_new_window(program->mlx, program->lenght, program->height, "so long");
	return (program);
}

int	so_long(int x, int y, char *map)
{

	t_program *program;

	program = program_init(x, y, map);


	draw_map(program, (*program).width, (*program).elevation);
	draw_P_and_E(&program);
	key_handler(0, program);
	// mlx_mouse_hook(program.win, &mouse_handler, &program);
	// mlx_hook(program.win, 6, 1L<<6, mouse_movement_handler, &program);
	mlx_loop_hook((*program).mlx, &render, program);
	mlx_loop((*program).mlx);
	return (0);
}
