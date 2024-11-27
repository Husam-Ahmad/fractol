/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:31:02 by huahmad           #+#    #+#             */
/*   Updated: 2024/11/27 13:13:09 by huahmad          ###   ########.fr       */
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
