/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:27:44 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/11 10:32:52 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"

# define WIDTH				800	
# define HEIGHT				800	
# define KeyPressMask		1L<<0
# define ButtonPressMask	1L<<2
# define NoEventMask		0L

typedef struct d_color{
	int				r;
	int				startr;
	int				endr;
	int				g;
	int				startg;
	int				endg;
	int				b;
	int				startb;
	int				endb;
}				t_color;

typedef struct d_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct d_zomm {
	int		x;
	int		y;
	double	scale;
	int		it;
	int		max_it;
}			t_zoom;

typedef struct d_complex {
	double	imag;
	double	real;
}				t_complex;

typedef struct d_display{
	void	*init;
	void	*win;
	double	yscale;
	double	xscale;
	int		it;
	int		max_it;
	double	zoom_x;
	double	zoom_y;
	double	xcord;
	double	ycord;
	int		fix_julia_pos;
	int		fract;
	int		help;
	t_img	*img;
	t_color	*color;
}				t_display;

int			ft_strncmp(const char *s1, const char *s2, size_t n);

t_display	*mlx_initialization(void);
void		value_sitting(t_display *mlx);
void		mandelbrot(t_display *mlx);
void		julia(t_display *mlx);
void		fern(t_display *mlx);
void		lighting_pixels_man(t_display *mlx);
void		lighting_pixels_julia(t_display *mlx);
void		lighting_pixels_fern(t_display *mlx);
int			ft_iteration_man(t_complex z, int x, int y, t_display *mlx);
int			ft_iteration_julia(t_complex c, int x, int y, t_display *mlx);
void		ft_iteration_fern(t_complex *z, t_display *mlx);
int			coloring_pixels(t_display *mlx);
void		pixels_image(t_display *mlx, int x, int y, int color);
void		lighting_pixels_tricorn(t_display *mlx);
int			ft_iteration_tricorn(t_complex z, int x, int y, t_display *mlx);
void		tricorn(t_display *mlx);

int			key_event(int keysym, t_display *mlx);
int			mouse_event(int button, int x, int y, t_display *mlx);
int			hundle_no_event(t_display *mlx);
int			mouse_cord(int x, int y, t_display *mlx);
void		hundle_key_event(int keysym, t_display *mlx);
void		hundle_mouse_event(int button, int x, int y, t_display *mlx);
int			destroy(t_display *mlx);
void		ft_help(t_display *mlx);
int			help_message(void);

#endif