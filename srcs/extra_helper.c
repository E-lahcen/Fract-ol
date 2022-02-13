/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:13:02 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/13 11:54:46 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	pixels_image(t_display *mlx, int x, int y, int color)
{
	*(unsigned int *)&mlx->img.addr[((y * mlx->img.line_len) + \
		x * (mlx->img.bpp / 8))] = color;
}

void	init_values(t_display *mlx)
{
	mlx->xscale = 4.0 / WIDTH;
	mlx->yscale = 4.0 / HEIGHT;
	mlx->zoom_x = 2.0;
	mlx->zoom_y = 2.0;
	mlx->xcord = 0.0;
	mlx->ycord = 0.0;
	mlx->max_it = 50;
	mlx->fix_julia_pos = 0;
	mlx->help = 0;
	mlx->color_shift = 0;
}

int	hundle_no_event(t_display *mlx)
{
	if (mlx->fract == 1)
		lighting_pixels_man(mlx);
	else if (mlx->fract == 2)
		lighting_pixels_julia(mlx);
	else if (mlx->fract == 4)
		lighting_pixels_tricorn(mlx);
	return (1);
}

void	color_shift(t_display *mlx)
{
	mlx->color_shift = (mlx->color_shift + 1) % 6;
	set_color_array(mlx);
}

void	ft_help(t_display *mlx)
{
	mlx_clear_window(mlx->img.init, mlx->img.win);
	mlx_string_put(mlx->img.init, mlx->img.win, 300, 300, \
		0x8F00FF, "|      ---------- Fract'ol !! ---------     |");
	mlx_string_put(mlx->img.init, mlx->img.win, 300, 350, \
		0xffffff, "|    Use the mouse wheel to zoom in & out   |");
	mlx_string_put(mlx->img.init, mlx->img.win, 300, 400, \
		0xffffff, "|    Right Click to change the Color	        |");
	mlx_string_put(mlx->img.init, mlx->img.win, 300, 450, \
		0xffffff, "|    Use the arrows to move the image       |");
	mlx_string_put(mlx->img.init, mlx->img.win, 300, 500, \
		0xffffff, "|    Close help by pressing the space bar   |");
	mlx_string_put(mlx->img.init, mlx->img.win, 300, 550, \
		0x8F00FF, "|      ----------- Fract'ol !! ---------    |");
}
