/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:09:19 by huahmad           #+#    #+#             */
/*   Updated: 2025/02/14 17:05:03 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

void	juliaset(t_fractol *julia)
{
	int			i;
	t_complex	z0;
	t_complex	z1;

	julia->x = 0;
	while (++julia->x <= julia->width)
	{
		julia->y = 0;
		while (++julia->y <= julia->height)
		{
			z0 = mappoint(julia, julia->x, julia->y);
			i = 1;
			while (i++ <= julia->iterations)
			{
				z1 = add(sqr(z0), julia->c);
				if (z1.x * z1.x + z1.y * z1.y > julia->radius * julia->radius)
				{
					imgbyimg(julia, julia->x, julia->y, julia->color * i);
					break ;
				}
				z0 = z1;
			}
		}
	}
}
