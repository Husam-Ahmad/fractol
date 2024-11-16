/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:15 by huahmad           #+#    #+#             */
/*   Updated: 2024/11/16 15:53:48 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		close_game(fractol);
	else if (keycode == LEFT)
		fractol->xoff -= 30;
	else if (keycode == DOWN)
		fractol->yoff += 30;
	else if (keycode == RIGHT)
		fractol->xoff += 30;
	else if (keycode == UP)
		fractol->yoff -= 30;
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
