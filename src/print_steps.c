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

#if ITS_BONUS_PROGRAMM

void	write_steps(t_main *main)
{
	char	*num;

	num = ft_itoa(++main->steps);
	put_img_to_win(main, main->img->banner[0], 0, 0);
	put_img_to_win(main, main->img->banner[1], 0, 1);
	put_img_to_win(main, main->img->banner[2], 0, 2);
	mlx_string_put(main->mlx, main->win, STEPS_ON_WIN_X * 1.35, STEPS_ON_WIN_Y,
		0x0, "Steps:");
	mlx_string_put(main->mlx, main->win, STEPS_ON_WIN_X * 2.3, STEPS_ON_WIN_Y,
		0x0, num);
	free (num);
}

#else 

void	write_steps(t_main *main)
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

#endif
