/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgbyimg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:31:02 by huahmad           #+#    #+#             */
/*   Updated: 2025/02/14 14:41:00 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mappoint(t_fractol *fractol, double x, double y)
{
	t_complex	c;
	double		l;

	if (fractol->width > fractol->height)
		l = fractol->height * fractol->zoom;
	else
		l = fractol->width * fractol->zoom;
	x += fractol->xarrow;
	y += fractol->yarrow;
	c.x = 2 * fractol->radius * (x - fractol->width / 2) / l;
	c.y = 2 * fractol->radius * (y - fractol->height / 2) / l;
	return (c);
}

int	imgbyimg(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_length + x
			* (fractol->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}
