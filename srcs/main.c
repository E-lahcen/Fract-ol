/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:13:34 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/11 09:31:43 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_display	*mlx;

	mlx = NULL;
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
			mandelbrot(mlx);
		else if (ft_strncmp(av[1], "Julia", 6) == 0)
			julia(mlx);
		else if (ft_strncmp(av[1], "Fern", 5) == 0)
			fern(mlx);
		else if (ft_strncmp(av[1], "Tricorn", 8) == 0)
			tricorn(mlx);		
		else
			return (help_message());
	}
	help_message();
	return (0);
}

int	help_message(void)
{
	return (printf("Unvalid fractal !!\n*****************\
			You can choose one of those:\
			*****************\n\
			\n1-Mandelbrot\n	\n2-Julia\n	\n3-Fern\n\n4-Tricorn\n\n"));
}
