/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:06:18 by huahmad           #+#    #+#             */
/*   Updated: 2025/05/27 17:43:39 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// key codes (two ways to use keys)
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define Z 122
# define PLUS 65451
# define MINUS 65453

typedef struct imaginary
{
	double		x;
	double		y;
}				t_complex;

typedef struct fractol
{
	char		*name;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
}				t_fractol;

void			for_mandelbrot(t_fractol *fractol, char *name);
void			for_julia(t_fractol *fractol, char **arg, int argc);
int				key_hook(int keycode, t_fractol *fractol);
void			fractolsetup(t_fractol *fractol);
int				freeall(t_fractol *fractol);
int				close_game(t_fractol *fractol);
void			mandelbrot_iter(t_fractol *fractol);
int				mouse_hook(int key_code, int x, int y, t_fractol *fractol);
void			ft_zoomin(double x, double y, t_fractol *fractol);
int				imgbyimg(t_fractol *fractol, int x, int y, int color);
void			ft_zoomout(double x, double y, t_fractol *fractol);
t_complex		mappoint(t_fractol *fractol, double x, double y);
t_complex		sqr(t_complex a);
t_complex		add(t_complex a, t_complex b);
void			juliaset(t_fractol *julia);

#endif
