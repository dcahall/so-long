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

static void	move_enemy(t_main *main, int x, int y)
{
	if (main->map[main->enemy_y + y][main->enemy_x + x] == '1'
		|| main->map[main->enemy_y + y][main->enemy_x + x] == 'E'
		|| main->map[main->enemy_y + y][main->enemy_x + x] == 'C'
		|| main->map[main->enemy_y + y][main->enemy_x + x] == 'A')
		return ;
	else if ((main->enemy_x + x) == main->x && (main->enemy_y + y) == main->y)
	{
		write(1, "Game over\n", 10);
		close_window(main);
	}
	put_img_to_win(main, main->img->floor, main->enemy_y, main->enemy_x);
	put_img_to_win(main, main->img->enemy[0], main->enemy_y + y,
		main->enemy_x + x);
	main->map[main->enemy_y + y][main->enemy_x + x] = 'A';
	main->map[main->enemy_y][main->enemy_x] = '0';
	main->enemy_x = 0;
	main->enemy_y = 0;
}

static void	convert_direction(t_main *main, int y, int x)
{
	int	direction;

	if (main->move_enemy_delay != 20)
	{
		main->move_enemy_delay++;
		return ;
	}
	else
		main->move_enemy_delay = 0;
	main->enemy_x = x;
	main->enemy_y = y;
	direction = random_num(main);
	if (direction == UP_ENEMY)
		move_enemy(main, -1, 0);
	else if (direction == DOWN_ENEMY)
		move_enemy(main, 1, 0);
	else if (direction == LEFT_ENEMY)
		move_enemy(main, 0, -1);
	else if (direction == RIGHT_ENEMY)
		move_enemy(main, 0, 1);
}

static void	change_enemy_img(t_main *main)
{
	int	i;

	i = 0;
	if (main->animation_enemy_delay != 1)
	{
		main->animation_enemy_delay++;
		return ;
	}
	else
		main->animation_enemy_delay = 0;
	while (i < ENEMY_IMG_NUM)
	{
		if (main->img->current_enemy == main->img->enemy[i])
		{
			if (i == ENEMY_IMG_NUM - 1)
				main->img->current_enemy = main->img->enemy[0];
			else
				main->img->current_enemy = main->img->enemy[i + 1];
			return ;
		}
		i++;
	}
}

static void	draw_enemy_img_or_move(t_main *main, int action)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (main->map[y])
	{
		while (main->map[y][x])
		{
			if (main->map[y][x] == 'A')
			{
				if (action == DRAW_ENEMY)
				{
					put_img_to_win(main, main->img->floor, y, x);
					put_img_to_win(main, main->img->current_enemy, y, x);
				}
				else if (action == MOVE)
					convert_direction(main, y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	enemy_handling(t_main *main)
{
	mlx_do_sync(main->mlx);
	change_enemy_img(main);
	draw_enemy_img_or_move(main, DRAW_ENEMY);
	draw_enemy_img_or_move(main, MOVE);
	return (0);
}
