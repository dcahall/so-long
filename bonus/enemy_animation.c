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

static int	random_num(void)
{
	char	*i;
	int		random;

	i = malloc(1);
	random = ((unsigned int)&(*i) / 123) % 4;
	free(i);
	return (random);
}

// static void	animation_direction(t_main *main, int direction)
// {
// 	int		img_number;
// 	int		i;
// 	int		z;
// 	void	**img;

// 	z = 1;
// 	i = 0;
// 	img_number = 0;
// 	if (direction == UP_ENEMY || direction == DOWN_ENEMY)
// 		return ;
// 	else if (direction == LEFT_ENEMY)
// 		img = main->img->enemy;
// 	else
// 		img = main->img->reverse_enemy;
// 	while (img_number < ENEMY_IMG_NUM)
// 	{
// 		put_img_to_win(main, main->img->floor, main->enemy_y, main->enemy_x);
// 		put_img_to_win(main, img[img_number], main->enemy_y, main->enemy_x);
// 		while (i <= z * 10)
// 			++i;
// 		++z;
// 		++img_number;
// 	}
// }

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
	put_img_to_win(main, main->img->enemy[0], main->enemy_y + y, main->enemy_x + x);
	main->map[main->enemy_y + y][main->enemy_x + x] = 'A';
	main->map[main->enemy_y][main->enemy_x] = '0';
	main->enemy_x = 0;
	main->enemy_y = 0;
}

static void	convert_direction(t_main *main, int direction)
{
	if (direction == UP_ENEMY)
		move_enemy(main, -1, 0);
	else if (direction == DOWN_ENEMY)
		move_enemy(main, 1, 0);
	else if (direction == LEFT_ENEMY)
	{
		// animation_direction(main, direction);
		move_enemy(main, 0, -1);
	}
	else if (direction == RIGHT_ENEMY)
	{
		// animation_direction(main, direction);
		move_enemy(main, 0, 1);
	}
}

int	enemy_handling(t_main *main)
{
	static int	delay;
	int			y;
	int			x;
	int			direction;

	y = 0;
	x = 0;
	mlx_do_sync(main->mlx);
	if (++delay == 60)
		delay = 0;
	else
		return (0);
	while (main->map[y])
	{
		while (main->map[y][x])
		{
			if (main->map[y][x] == 'A')
			{
				main->enemy_x = x;
				main->enemy_y = y;
				direction = random_num();
				convert_direction(main, direction);
				if (main->map[y][x + 1] == 'A' && direction == RIGHT)
				{
					printf("xyi\n");
					x++;
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	enemy_handling(t_main *main)
{
	mlx_do_sync(game->mlx);
	animate_enemy(game);
	move_enemy(game, game->map, -1, -1);
	render_enemy(game, -1, -1);
	return (0);
}
