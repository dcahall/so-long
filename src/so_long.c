/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcahall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:42:20 by dcahall           #+#    #+#             */
/*   Updated: 2022/01/14 11:42:33 by dcahall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize(t_main *main)
{
	main->lenght = 0;
	main->widht = 0;
	main->collectible = 0;
	main->players = 0;
	main->exits = 0;
	main->steps = 0;
	main->mlx = NULL;
	main->win = NULL;
	main->map = NULL;
	main->x = 0;
	main->y = 0;
	main->img->collectible = NULL;
	main->img->exits_close = NULL;
	main->img->exits_open = NULL;
	main->img->floor = NULL;
	main->img->player = NULL;
	main->img->wall = NULL;
}

static t_main	*create_struct(void)
{
	t_main	*main;
	t_image	*img;

	main = malloc(sizeof(t_main));
	if (!main)
		error_message("Error malloc", main);
	img = malloc(sizeof(t_image));
	if (!img)
		error_message("Error malloc", main);
	main->img = img;
	initialize(main);
	return (main);
}

int	main(int argc, char **argv)
{
	t_main	*main;

	if (argc != 2)
		exit (1);
	main = create_struct();
	cart_validation(argv[1], main);
	main->mlx = mlx_init();
	if (!main->mlx)
		error_message("Error when calling the function: mlx_init()", main);
	main->win = mlx_new_window(main->mlx, PIXEL * main->lenght,
			PIXEL * main->widht, "so_long");
	if (!main->win)
		error_message("Error when calling the function: mlx_new_window", main);
	draw_map(main, 0, 0);
	mlx_hook(main->win, 2, 1L << 0, press_key, main);
	mlx_hook(main->win, CANCEL, 1L << 0, close_window, main);
	mlx_loop(main->mlx);
}
