/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:06:18 by huahmad           #+#    #+#             */
/*   Updated: 2024/11/27 13:16:28 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL

# define FRACT_OL

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>


// key codes
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define R 114
# define Z 122
# define PLUS 65451
# define MINUS 65453

typedef struct imaginary {
	double	x;
	double	y;
}	t_complex;

typedef struct fractol {
	int		iterations;
	int		color;
	int		width;
	int		height;
	int		x;
	int		y;
	char	*name;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	double	zoom;
	double	xoff;
	double	yoff;
	t_complex	c;
}	t_fractol;

void	for_mandelbrot(t_fractol *fractol, char *name);
void	for_julia(t_fractol *fractol, char *name);
int		key_hook(int keycode, t_fractol *fractol);
void	fractolsetup(t_fractol *fractol);
int		freeall(t_fractol *fractol);
int		close_game(t_fractol *fractol);
void	mandelbrot_iter(t_fractol *fractol);
int	mouse_hook(int key_code, int x, int y, t_fractol *fractol);
void	ft_zoomin(double x, double y, t_fractol *fractol);
void	ft_zoomout(double x, double y, t_fractol *fractol);



#endif
