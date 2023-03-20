/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/03/20 11:13:25 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct  s_program
	{
    	void *mlx;
   		void *win;
		t_img img;
		int height;
		int lenght;
		char *map;
	}               t_program;

void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int key_handler(int key, t_program *temp)
{
	int i;



	i = 100;
	if (key == 124)
	{
	 while (i-- != 0)
		img_pix_put(&temp->img, i, 100, 0x2E9E2A);
	}
	if (key == 125)
	{
	while (i++ != 200)
		img_pix_put(&temp->img, 50, i, 0x2E9E2A);
	}
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

void draw_map(t_program *program, int width, int height)
{
	char	*map_lines[map_rows(program->map) + 1];
	int		fd;
	int		i;
	int		j;
	int 	k;
	void	*map_tiles[(map_rows(program->map) * (check_rows_lenght(program->map,1) - 1)) + 1];
	char	arr[2];


	i = -1;
	j = -1;
	k = -1;
	arr[1] = '\0';
	map_lines[map_rows(program->map)] = 0;
	fd = open(program->map, O_RDONLY);
	while (i++ < map_rows(program->map))
		map_lines[i] = get_next_line_multiple(fd);
	map_tiles[(map_rows(program->map) * (check_rows_lenght(program->map,1) - 1))] = 0;
	i = 0;
	while (map_lines[++j] != NULL)
	{
		while (map_lines[j][++k] != '\n')
		{
			arr[0] = map_lines[j][k];
			if (ft_strncmp(arr, "1", 1) == 0)
				map_tiles[i++] = mlx_xpm_file_to_image(program->mlx, "./img/fire1.xpm", &width, &height);
			else
				map_tiles[i++] = mlx_xpm_file_to_image(program->mlx, "./img/tile.xpm", &width, &height);
		}
		k = -1;
	}
	i = -1;
	j = 0;
	k = 0;
	arr[0] = check_rows_lenght(program->map, 1);
	while (map_tiles[++i] != NULL)
	{
		while (arr[0]-- != 0)
		{
			mlx_put_image_to_window(program->mlx, program->win, map_tiles[i], k, j);
			k += 96;
		}
		k = 0;
		j += 96;
	}

}

int render(t_program *program)
{
	t_img image;
	// t_img image2;
	int width;
	int height;

	width = 96;
	height = 96;
	if (program->win == NULL)
		return (1);
	// draw_map(program, width, height);
	// p2->mlx = program->mlx;
	// p2->win = program->win;
	// image2 = create_image(program, program->lenght, program->height);
	// render_background(&image2, 0x76B947, program->lenght, program->height);
	// mlx_put_image_to_window(program->mlx, program->win, image2.mlx_img, 0, 0);
	// program->img.mlx_img = mlx_xpm_file_to_image(program->mlx, "./img/hive1.xpm", &program
	// ->lenght, &program->height);
	// mlx_put_image_to_window(program->mlx, program->win, program->img.mlx_img, 0, 0);
	// image = create_image(program, i, j);
	// render_background(&image, 0xE8F70E, i, j);
	image.mlx_img = mlx_xpm_file_to_image(program->mlx, "./img/basic96.xpm", &width, &height);
	mlx_put_image_to_window(program->mlx, program->win, image.mlx_img, 192, 384);


	return (0);
}

int	so_long(int x, int y, char *map)
{

	t_program program;

	program.lenght = x;
	program.height = y;
	program.map = map;
	program.mlx  = mlx_init();
	program.win = mlx_new_window(program.mlx, program.lenght, program.height, "so long");
	// program.img.mlx_img = mlx_new_image(program.mlx, 1000, 1000);
	// program.img.addr = mlx_get_data_addr(program.img.mlx_img, &program.img.bpp, &program.img.line_len, &program.img.endian);

	// mlx_key_hook(program.win, &key_handler, &program);
	mlx_mouse_hook(program.win, &mouse_handler, &program);
	mlx_hook(program.win, 6, 1L<<6, mouse_movement_handler, &program);
	mlx_loop_hook(program.mlx, &render, &program);
	mlx_loop(program.mlx);
	return (0);
}
