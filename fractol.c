/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:58:47 by huahmad           #+#    #+#             */
/*   Updated: 2024/11/16 15:51:34 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void for_mandelbrot(t_fractol *fractol, char *name)
{
	fractol->name = name;
	fractol->color =  0xccf1ff;
	fractol->width = 640;
	fractol->height = 480;
	fractol->iterations = 500;
	fractol->x = 0;
	fractol->y = 0;
}

void for_julia(t_fractol *fractol, char *name)
{
	fractol->name = name;
	fractol->color =  0xccf1ff;
	fractol->width = 640;
	fractol->height = 480;
	fractol->iterations = 500;
	fractol->x = 0;
	fractol->y = 0;
}

int	freeall(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(0);
}

int main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 2)
	{
		if (strncmp(argv[1], "Mandelbrot", 10))
			for_mandelbrot(&fractol, argv[1]);
		else if (strncmp(argv[1], "Julia", 5))
			for_julia(&fractol, argv[1]);
		fractol.mlx = mlx_init();
		fractol.win = mlx_new_window(fractol.mlx, fractol.width,
				fractol.height, fractol.name);
		fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
		fractolsetup(&fractol);
	}
	return 0;
}
