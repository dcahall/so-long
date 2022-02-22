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

void	put_img_to_win(t_main *main, void *img, int y, int x)
{
	mlx_put_image_to_window(main->mlx, main->win, img, PIXEL * x, PIXEL * y);
	return ;
}

static void	draw_tile(t_main *main, int y, int x)
{
	put_img_to_win(main, main->img->floor, y, x);
	if (main->map[y][x] == '1')
		put_img_to_win(main, main->img->wall, y, x);
	else if (main->map[y][x] == 'P')
	{
		main->x = x;
		main->y = y;
		put_img_to_win(main, main->img->current_player, y, x);
	}
	else if (main->map[y][x] == 'C')
		mlx_put_image_to_window(main->mlx, main->win,
			main->img->collectible, PIXEL * x + 16, PIXEL * y + 16);
	else if (main->map[y][x] == 'E')
		put_img_to_win(main, main->img->exits_close, y, x);
	else if (ITS_BONUS_PROGRAMM)
		if (main->map[y][x] == 'A')
			put_img_to_win(main, main->img->current_enemy, y, x);
}

void	draw_map(t_main *main)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < main->widht)
	{
		while (x < main->lenght)
		{
			draw_tile(main, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	if (ITS_BONUS_PROGRAMM)
	{
		put_img_to_win(main, main->img->banner[0], 0, 0);
		put_img_to_win(main, main->img->banner[1], 0, 1);
		put_img_to_win(main, main->img->banner[2], 0, 2);
		mlx_string_put(main->mlx, main->win, STEPS_ON_WIN_X * 1.35,
			STEPS_ON_WIN_Y, 0x0, "Steps:");
	}
}
