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
				put_img_to_win(main, main->img->floor, y, x);
				put_img_to_win(main, main->img->exits_open, y, x);
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

static void	write_steps(t_main *main)
{
	char	*num;
	size_t	i;

	i = 0;
	write(1, "Steps: ", 7);
	num = ft_itoa(++main->steps);
	while (num[i])
	{
		write(1, &num[i], 1);
		++i;
	}
	write(1, "\n", 1);
	free (num);
}

static void	move_player(t_main *main, int x, int y)
{
	if (main->map[main->y + y][main->x + x] == '1'
		|| (main->map[main->y + y][main->x + x] == 'E' && main->collectible))
		return ;
	write_steps(main);
	if (main->map[main->y + y][main->x + x] == 'C')
	{
		main->collectible -= 1;
		main->map[main->y + y][main->x + x] = '0';
		open_door(main, main->map, 0, 0);
	}
	else if (!main->collectible && main->map[main->y + y][main->x + x] == 'E')
	{
		write(1, "YOU WON\n", 8);
		close_window(main);
	}
	else if (ITS_BONUS_PROGRAMM && main->map[main->y + y][main->x + x] == 'A')
	{
		write(1, "Game over\n", 10);
		close_window(main);
	}
	put_img_to_win(main, main->img->floor, main->y, main->x);
	put_img_to_win(main, main->img->current_player, main->y + y, main->x + x);
	main->x += x;
	main->y += y;
}

#if ITS_BONUS_PROGRAMM

int	press_key(int keycode, t_main *main)
{
	if (keycode == ESC)
		close_window(main);
	else if (keycode == W)
		move_player(main, 0, -1);
	else if (keycode == S)
		move_player(main, 0, 1);
	else if (keycode == A)
	{
		player_animation(main, LEFT);
		move_player(main, -1, 0);
	}
	else if (keycode == D)
	{
		player_animation(main, RIGHT);
		move_player(main, 1, 0);
	}
	return (0);
}

#else 

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

#endif