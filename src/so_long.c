/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/03/17 13:59:40 by druina           ###   ########.fr       */
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

int render(t_program *program)
{
	t_img image;
	int width;
	int height;

	width = 96;
	height = 96;
	if (program->win == NULL)
		return (1);
	// p2->mlx = program->mlx;
	// p2->win = program->win;
	program->img = create_image(program, program->lenght, program->height);
	render_background(&program->img, 0x3B18EC, program->lenght, program->height);
	mlx_put_image_to_window(program->mlx, program->win, program->img.mlx_img, 0, 0);
	// image = create_image(program, i, j);
	// render_background(&image, 0xE8F70E, i, j);
	image.mlx_img = mlx_xpm_file_to_image(program->mlx, "./img/basic96.xpm", &width, &height);
	mlx_put_image_to_window(program->mlx, program->win, image.mlx_img, 0, 0);


	return (0);
}

int	so_long(int x, int y)
{

	t_program program;

	program.lenght = x;
	program.height = y;
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
