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

static void img_to_window(t_main *main, int i, int j)
{
	while (j < main->widht)
	{
		while (i < main->lenght)
		{
			mlx_put_image_to_window(main->mlx, main->win, main->img->floor, PIXEL * i, PIXEL * j);
			if (main->map[j][i] == '1')
				mlx_put_image_to_window(main->mlx, main->win, main->img->wall, PIXEL * i, PIXEL * j);
			else if (main->map[j][i] == 'P')
			{
				main->x = i;
				main->y = j;
				mlx_put_image_to_window(main->mlx, main->win, main->img->player, PIXEL * i, PIXEL * j);
			}
			else if (main->map[j][i] == 'C')
				mlx_put_image_to_window(main->mlx, main->win, main->img->collectible, PIXEL * i + 16, PIXEL * j + 16);
			else if (main->map[j][i] == 'E')
				mlx_put_image_to_window(main->mlx, main->win, main->img->exits_close, PIXEL * i, PIXEL * j);
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_map(t_main *main, int widht, int lenght)
{
	main->img->floor = mlx_xpm_file_to_image(main->mlx, "./img/floor.xpm", &widht, &lenght);
	main->img->wall = mlx_xpm_file_to_image(main->mlx, "./img/wall.xpm", &widht, &lenght);
	main->img->collectible = mlx_xpm_file_to_image(main->mlx, "./img/collectible.xpm", &widht, &lenght);
	main->img->player = mlx_xpm_file_to_image(main->mlx, "./img/knight.xpm", &widht, &lenght);
	main->img->exits_open = mlx_xpm_file_to_image(main->mlx, "./img/open_door.xpm", &widht, &lenght);
	main->img->exits_close = mlx_xpm_file_to_image(main->mlx, "./img/closed_door.xpm", &widht, &lenght);
	img_to_window(main, 0, 0);
}