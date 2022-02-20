/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:02:57 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 15:46:02 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_win(t_main *main, void *img, int y, int x)
{
	mlx_put_image_to_window(main->mlx, main->win, img, PIXEL * x, PIXEL * y);
	return ;
}

static void	img_to_window(t_main *main, int y, int x)
{
	while (++y < main->widht)
	{
		while (++x < main->lenght)
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
		x = -1;
	}
}

static void	reverse_img(t_main *main, int widht, int lenght)
{
	main->img->reverse_player[0] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_player1.xpm", &widht, &lenght);
	main->img->reverse_player[1] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_player2.xpm", &widht, &lenght);
	main->img->reverse_enemy[0] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_enemy1.xpm", &widht, &lenght);
	main->img->reverse_enemy[1] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_enemy2.xpm", &widht, &lenght);
	main->img->reverse_enemy[2] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_enemy3.xpm", &widht, &lenght);
	main->img->reverse_enemy[3] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_enemy4.xpm", &widht, &lenght);
	main->img->reverse_enemy[4] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_enemy5.xpm", &widht, &lenght);
	main->img->reverse_enemy[5] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_enemy6.xpm", &widht, &lenght);
}

static void	open_players_enemies_img(t_main *main, int widht, int lenght)
{
	main->img->player[0] = mlx_xpm_file_to_image(main->mlx,
			"./img/player1.xpm", &widht, &lenght);
	main->img->player[1] = mlx_xpm_file_to_image(main->mlx,
			"./img/player2.xpm", &widht, &lenght);
	main->img->enemy[0] = mlx_xpm_file_to_image(main->mlx,
			"./img/enemy1.xpm", &widht, &lenght);
	main->img->enemy[1] = mlx_xpm_file_to_image(main->mlx,
			"./img/enemy2.xpm", &widht, &lenght);
	main->img->enemy[2] = mlx_xpm_file_to_image(main->mlx,
			"./img/enemy3.xpm", &widht, &lenght);
	main->img->enemy[3] = mlx_xpm_file_to_image(main->mlx,
			"./img/enemy4.xpm", &widht, &lenght);
	main->img->enemy[4] = mlx_xpm_file_to_image(main->mlx,
			"./img/enemy5.xpm", &widht, &lenght);
	main->img->enemy[5] = mlx_xpm_file_to_image(main->mlx,
			"./img/enemy6.xpm", &widht, &lenght);
	reverse_img(main, widht, lenght);
}

void	draw_map(t_main *main, int widht, int lenght)
{
	main->img->floor = mlx_xpm_file_to_image(main->mlx,
			"./img/floor.xpm", &widht, &lenght);
	main->img->wall = mlx_xpm_file_to_image(main->mlx,
			"./img/wall.xpm", &widht, &lenght);
	main->img->collectible = mlx_xpm_file_to_image(main->mlx,
			"./img/collectible.xpm", &widht, &lenght);
	main->img->exits_open = mlx_xpm_file_to_image(main->mlx,
			"./img/open_door.xpm", &widht, &lenght);
	main->img->exits_close = mlx_xpm_file_to_image(main->mlx,
			"./img/closed_door.xpm", &widht, &lenght);
	main->img->current_player = mlx_xpm_file_to_image(main->mlx,
			"./img/player1.xpm", &widht, &lenght);
	if (ITS_BONUS_PROGRAMM)
	{
		open_players_enemies_img(main, widht, lenght);
		main->img->current_enemy = main->img->enemy[0];
	}
	img_to_window(main, -1, -1);
}
