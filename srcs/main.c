/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:13:34 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/13 10:56:24 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_display	mlx;
	int			nb;

	if (ac == 2)
	{
		if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
			mandelbrot(&mlx);
		else if (ft_strncmp(av[1], "Julia", 6) == 0)
			julia(&mlx, 6);
		else if (ft_strncmp(av[1], "Tricorn", 8) == 0)
			tricorn(&mlx);
		else
			return (help_message());
	}
	else if (ac == 3)
	{
		nb = ft_atoi(av[2]);
		if (ft_strncmp(av[1], "Julia", 6) == 0 && nb >= 0 && nb < 6)
			julia(&mlx, nb);
	}
	help_message();
	return (0);
}

int	help_message(void)
{
	ft_putstr_fd("Unvalid fractal !!\n*****************\
			You can choose one of those:\
			*****************\n\
			\nMandelbrot\n	\nJulia[fixed:0-5]\n\nTricorn\n\n", 0);
	return (0);
}
