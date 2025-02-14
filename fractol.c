/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:58:47 by huahmad           #+#    #+#             */
/*   Updated: 2025/02/14 12:51:37 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void for_mandelbrot(t_fractol *fractol, char *name)
{
	fractol->name = name;
	fractol->color =  0x3aff00;
	fractol->width = 1000;
	fractol->height = 1000;
	fractol->iterations = 150;
	fractol->x = 0;
	fractol->y = 0;
	fractol->xarrow = 0;
	fractol->yarrow = 270;
	fractol->zoom = 1;
}

void for_julia(t_fractol *fractol, char *name)
{
	fractol->width = 1280;
	fractol->height = 720;
	fractol->c.x = -0.7;
	fractol->c.y = 0.27015;
	fractol->radius = 3;
	fractol->iterations = 150;
	fractol->zoom = 1;
	fractol->x = 0;
	fractol->y = 0;
	fractol->xarrow = 0;
	fractol->yarrow = 0;
	fractol->color = 0xccf1ff;
	fractol->name = name;
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
		if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10)
			for_mandelbrot(&fractol, argv[1]);
		else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
			for_julia(&fractol, argv[1]);
		fractol.mlx = mlx_init();
		fractol.win = mlx_new_window(fractol.mlx, fractol.width,
				fractol.height, fractol.name);
		fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
		fractolsetup(&fractol);
		mlx_key_hook(fractol.win, key_hook, &fractol);
		mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
		mlx_hook(fractol.win, 18, 1L << 18, close_game, &fractol);
		mlx_hook(fractol.win, DestroyNotify, StructureNotifyMask, close_game, &fractol);
		mlx_loop(fractol.mlx);
	}
	else 
		ft_printf("wrong parameters"); 	
	return 0;
}
