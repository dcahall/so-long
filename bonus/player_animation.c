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

int	random_num(t_main *main)
{
	char	*i;
	int		random;

	i = malloc(1);
	if (main->delimiter_rand == 400)
		main->delimiter_rand = 0;
	else
		main->delimiter_rand++;
	random = ((unsigned int)&(*i) / (123 + main->delimiter_rand)) % 4;
	free(i);
	return (random);
}

int	key_release(int keycode, t_main *main)
{
	if (keycode == A || keycode == D || keycode == S || keycode == W)
	{
		put_img_to_win(main, main->img->floor, main->y, main->x);
		if (main->player_direction == RIGHT)
		{
			put_img_to_win(main, main->img->player[0], main->y, main->x);
		}
		else if (main->player_direction == LEFT)
		{
			put_img_to_win(main, main->img->reverse_player[0],
				main->y, main->x);
		}
	}
	return (0);
}

void	player_animation(t_main *main, int direction)
{
	if (direction == RIGHT || direction == 0)
	{
		if (main->img->current_player == main->img->player[0])
			main->img->current_player = main->img->player[1];
		else
			main->img->current_player = main->img->player[0];
		main->player_direction = RIGHT;
	}
	else if (direction == LEFT)
	{
		if (main->img->current_player == main->img->reverse_player[0])
			main->img->current_player = main->img->reverse_player[1];
		else
			main->img->current_player = main->img->reverse_player[0];
		main->player_direction = LEFT;
	}
}
