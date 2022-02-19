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

static void	open_door(t_main *main, char **map, int y, int x)
{
	if (main->collectible)
		return ;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				mlx_put_image_to_window(main->mlx, main->win, main->img->floor,
					PIXEL * x, PIXEL * y);
				mlx_put_image_to_window(main->mlx, main->win,
					main->img->exits_open, PIXEL * x, PIXEL * y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	close_window(t_main *main)
{
	mlx_destroy_window(main->mlx, main->win);
	exit (0);
}

static void	move_player(t_main *main, int x, int y)
{
	if (main->map[main->y + y][main->x + x] == '1'
		|| (main->map[main->y + y][main->x + x] == 'E' && main->collectible))
		return ;
	printf("steps №: %d\n", ++main->steps);
	if (main->map[main->y + y][main->x + x] == 'C')
	{
		main->collectible -= 1;
		main->map[main->y + y][main->x + x] = '0';
		open_door(main, main->map, 0, 0);
		mlx_put_image_to_window(main->mlx, main->win, main->img->floor,
			PIXEL * (main->x + x), PIXEL * (main->y + y));
	}
	else if (!main->collectible && main->map[main->y + y][main->x + x] == 'E')
	{
		printf("YOU WON\n");
		close_window(main);
	}
	mlx_put_image_to_window(main->mlx, main->win, main->img->floor,
		PIXEL * main->x, PIXEL * main->y);
	mlx_put_image_to_window(main->mlx, main->win, main->img->player,
		PIXEL * (main->x + x), PIXEL * (main->y + y));
	main->x += x;
	main->y += y;
}

int	press_key(int keycode, t_main *main)
{
	if (keycode == ESC)
		close_window(main);
	else if (keycode == W)
		move_player(main, 0, -1);
	else if (keycode == S)
		move_player(main, 0, 1);
	else if (keycode == A)
		move_player(main, -1, 0);
	else if (keycode == D)
		move_player(main, 1, 0);
	return (0);
}
