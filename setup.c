/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:17:33 by huahmad           #+#    #+#             */
/*   Updated: 2024/11/16 16:08:04 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_game(t_fractol *fractol)
{
	freeall(fractol);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	calculate_mand(int x, int y, t_fractol *fractol)
{
	int		i;
	double	z0;
	double	z1;
	double	temp;

	i = 0;
	fractol->c.x = (x + fractol->xoff) / fractol->zoom * 2.47 /
			(fractol->width - 1) - 2.0;
	fractol->c.y = (y + fractol->yoff) / fractol->zoom
		* 2.47 / (fractol->width - 1) - 1.12;
	z0 = fractol->c.x;
	z1 = fractol->c.y;
	while (i++ < fractol->iterations)
	{
		temp = z0 * z0 - z1 * z1 + fractol->c.x;
		z1 = 2.0 * z0 * z1 + fractol->c.y;
		z0 = temp;
		if (z0 * z0 + z1 * z1 > 4)
		{
			mlx_pixel_put(fractol->mlx, fractol->win, (int) x, (int) y, (fractol->color * i));
			break ;
		}
	}
}
void	mandelbrot_iter(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < fractol->width)
	{
		y = 0;
		while (y < fractol->height)
		{
			calculate_mand(x, y, fractol);
		}
	}
}

void	fractolsetup(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->pixel_bits,
			&fractol->line_bytes, &fractol->endian);
	if (ft_strncmp(fractol->name, "mandelbrot", 10))
		mandelbrot_iter(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	mlx_hook(fractol->win, KeyPress, KeyPressMask, key_hook, fractol);
	mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask, close_game, fractol);
	// mlx_mouse_hook(fractal.win, mouse_hook, &fractol);
	mlx_loop(fractol->mlx);
}
