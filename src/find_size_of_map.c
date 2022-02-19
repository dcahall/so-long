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

int	check_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
			return (1);
		++i;
	}
	return (0);
}

static int	check_wall(char *str)
{
	int	i;

	i = 0;
	if (str[i + 1] == '1')
	{
		while (str[i] == '1' && str[i])
			i++;
	}
	if (str[i] == ' ' || str[i] == '\0')
		return (1);
	else
		return (0);
}

static int	count_len_str(char *str, t_main *main)
{
	int	i;
	int lenght;

	lenght = 0;
	i = 0;
	while ((str[i] == '0' || str[i] == '1' || str[i] == 'E' || str[i] == 'P' || 
			str[i] == 'C') && str[i])
	{
		lenght++;
		i++;
	}
	while (str[i])
	{
		if (str[i] != ' ')
			error_message("The wrong symbol on the map", main);

		i++;
	}
	return (lenght);
}

void	count_size_of_map(int fd, t_main *main)
{
	char	*str;
	int		wall;
	int		lenght;
	int		rd;

	rd = 1;
	wall = 0;
	while (rd && wall != 2)
	{
		rd = gnl(&str, fd, main);
		while (check_empty_string(str) == 0 && main->widht == 0)
		{
			free(str);
			rd = gnl(&str, fd, main);
		}
		if (!check_empty_string(str) && main->widht)
			error_message("No 2 wall or gap on map", main);
		if (str)
		{
			lenght = count_len_str(str, main);
			if (check_wall(str))
				wall++;
			if (main->lenght == 0)
				main->lenght = lenght;
			else if (lenght != main->lenght)
				error_message("The map is not rectangular in shape", main);
			main->widht += 1;
		}
		free(str);
	}
	if (wall < 2)
		error_message("The map has less than two horizontal walls", main);
	close (fd);
}
