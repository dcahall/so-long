/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcahall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:33:17 by dcahall           #+#    #+#             */
/*   Updated: 2022/02/22 16:33:28 by dcahall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_bonus_img2(t_main *main, int widht, int lenght)
{
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
}

static void	open_bonus_img(t_main *main, int widht, int lenght)
{
	main->img->player[0] = mlx_xpm_file_to_image(main->mlx,
			"./img/player1.xpm", &widht, &lenght);
	main->img->player[1] = mlx_xpm_file_to_image(main->mlx,
			"./img/player2.xpm", &widht, &lenght);
	main->img->reverse_player[0] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_player1.xpm", &widht, &lenght);
	main->img->reverse_player[1] = mlx_xpm_file_to_image(main->mlx,
			"./img/reverse_player2.xpm", &widht, &lenght);
	main->img->banner[0] = mlx_xpm_file_to_image(main->mlx,
			"./img/banner1.xpm", &widht, &lenght);
	main->img->banner[1] = mlx_xpm_file_to_image(main->mlx,
			"./img/banner2.xpm", &widht, &lenght);
	main->img->banner[2] = mlx_xpm_file_to_image(main->mlx,
			"./img/banner3.xpm", &widht, &lenght);
	open_bonus_img2(main, 0, 0);
}

void	open_img(t_main *main, int widht, int lenght)
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
		open_bonus_img(main, widht, lenght);
		main->img->current_enemy = main->img->enemy[0];
	}
}
