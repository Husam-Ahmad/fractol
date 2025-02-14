/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:15 by huahmad           #+#    #+#             */
/*   Updated: 2025/02/10 22:48:17 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoomin(double x, double y, t_fractol *fractol)
{
	fractol->x = (x / fractol->zoom) - (x / (fractol->zoom * 1.3));
	fractol->y = (y / fractol->zoom) - (y / (fractol->zoom * 1.3));
	fractol->zoom *= 1.3;
	fractol->iterations++;
}

void	ft_zoomout(double x, double y, t_fractol *fractol)
{
	fractol->x = (x / fractol->zoom) - (x / (fractol->zoom / 1.3));
	fractol->y = (y / fractol->zoom) - (y / (fractol->zoom / 1.3));
	fractol->zoom /= 1.3;
	fractol->iterations--;
}

int	mouse_hook(int key_code, int x, int y, t_fractol *fractol)
{
	if (key_code == 1 && ft_strncmp(fractol->name, "mandelbrot", 5))
	{
		fractol->c.x = ((double) x / fractol->width * 4 - 2);
		fractol->c.y = ((double) y / fractol->height * 3 - 1.5);
		fractol->zoom = 1;
	}
	else if (key_code == 4)
		ft_zoomin(((double) x / fractol->width * 1000 - 500),
			((double) y / fractol->height * 1000 - 500), fractol);
	else if (key_code == 5)
		ft_zoomout(((double) x / fractol->width * 1000 - 500),
			((double) y / fractol->height * 1000 - 500), fractol);
	fractolsetup(fractol);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		close_game(fractol);
	else if (keycode == LEFT)
		fractol->xarrow -= 30;
	else if (keycode == DOWN)
		fractol->yarrow += 30;
	else if (keycode == RIGHT)
		fractol->xarrow += 30;
	else if (keycode == UP)
		fractol->yarrow -= 30;
	else if (keycode == PLUS)
		fractol->color += 100;
	else if (keycode == MINUS)
		fractol->color -= 100;
	else if (keycode == Z)
		fractol->zoom = 1;
	if (keycode != ESC)
		fractolsetup(fractol);
	return (0);
}

// int	mouse_hook(int key_code, int x, int y, t_fractol *fractol)
// {}
