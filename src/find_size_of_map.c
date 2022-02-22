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
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	else
		return (0);
}

static int	count_len_str(char *str, t_main *main)
{
	size_t	i;

	i = 0;
	if (ITS_BONUS_PROGRAMM)
	{
		while ((str[i] == '0' || str[i] == '1' || str[i] == 'E'
				|| str[i] == 'P' || str[i] == 'C' || str[i] == 'A') && str[i])
			i++;
	}
	else
	{
		while ((str[i] == '0' || str[i] == '1' || str[i] == 'E'
				|| str[i] == 'P' || str[i] == 'C') && str[i])
			i++;
	}
	if (str[i] != '\0' && str[i] != '\n')
		error_message("Error\nWrong symbol on the map", main);
	return (i);
}

static int	write_len_str_to_struct(t_main *main, char *str)
{
	int	lenght;
	int	wall;

	wall = 0;
	lenght = 0;
	lenght = count_len_str(str, main);
	if (check_wall(str))
		wall++;
	if (main->lenght == 0)
		main->lenght = lenght;
	else if (lenght != main->lenght)
		error_message("Error\nAn empty line or a non-rectangular map", main);
	main->widht += 1;
	return (wall);
}

void	count_size_of_map(int fd, t_main *main)
{
	char	*str;
	int		rd;
	int		wall;

	wall = 0;
	rd = gnl(&str, fd, main);
	while (rd)
	{
		wall += write_len_str_to_struct(main, str);
		free(str);
		rd = gnl(&str, fd, main);
	}
	if (ft_strlen(str) > 0)
		error_message("Error\nSymblols at the last string or forgot \\n", main);
	if (main->lenght == 0)
		error_message("Error\nUpload the map", main);
	if (wall < 2)
		error_message("Error\nWrong number of walls or forgot \\n at end", main);
	free(str);
	close (fd);
}
