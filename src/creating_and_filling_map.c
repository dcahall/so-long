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

int	gnl(char **str, int fd, t_main *main)
{
	char	symbol;
	char	*buf;
	int		rd;
	int		i;

	i = 0;
	buf = malloc(100000);
	if (!buf)
		error_message("Error malloc in gnl", main);
	rd = read(fd, &symbol, 1);
	while (rd && symbol != '\0' && symbol != '\n')
	{
		buf[i++] = symbol;
		if (rd == -1)
		{
			free(buf);
			error_message("Error\nMap reading", main);
		}
		rd = read(fd, &symbol, 1);
	}
	buf[i] = '\0';
	*str = buf;
	return (rd);
}

static void	fill_current_string(char *str, int fd, t_main *main)
{
	char	*tmp;
	int		i;
	int		k;

	k = 0;
	i = 0;
	gnl(&tmp, fd, main);
	while (!check_empty_string(tmp))
	{
		free(tmp);
		gnl(&tmp, fd, main);
	}
	while (i < main->lenght)
	{
		str[k] = tmp[i];
		k++;
		i++;
	}
	str[k] = '\0';
	free (tmp);
}

void	memory_allocate(t_main	*main, int fd)
{
	int		i;
	char	**tmp;

	i = 0;
	main->map = malloc((main->widht + 1) * sizeof(char *));
	if (!main->map)
		error_message("Error malloc", main);
	tmp = main->map;
	while (i < main->widht)
	{
		tmp[i] = malloc(sizeof(char) * (main->lenght + 1));
		if (!tmp[i])
			error_message("Error malloc", main);
		fill_current_string(tmp[i], fd, main);
		i++;
	}
	tmp[i] = NULL;
	close (fd);
}
