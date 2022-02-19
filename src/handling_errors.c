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

static void	map_cleaner(t_main	*main)
{
	int		i;
	char	**tmp;

	tmp = main->map;
	i = main->widht;
	while (i > 0)
	{
		free(tmp[i]);
		--i;
	}
	free(tmp);
}

void	error_message(char *str, t_main *main)
{
	ft_putendl_fd(str, 2);
	if (main->map)
		map_cleaner(main);
	if (main)
		free(main);
	if (main->img)
		free(main->img);
	exit (3);
}
