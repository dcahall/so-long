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

static void	check_symbol(char symbol, t_main *main)
{
	if (symbol == 'C')
		main->collectible += 1;
	else if (symbol == 'P')
		main->players += 1;
	else if (symbol == 'E')
		main->exits += 1;
}

static void	parse_map(char **map, t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		if (map[j][i] != '1' || map[j][main->lenght - 1] != '1')
			error_message("Holes in the wall", main);
		while (map[j][i])
		{
			check_symbol(map[j][i], main);
			i++;
		}
		i = 0;
		j++;
	}
}

static int	open_file(char *path_to_map, t_main *main)
{
	int	fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		error_message("Error opening the file", main);
	return (fd);
}

void	cart_validation(char *map_file, t_main *main)
{
	char	*path_to_map;

	if (!ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
		exit (2);
	path_to_map = ft_strjoin("./maps/", map_file);
	count_size_of_map(open_file(path_to_map, main), main);
	if (main->widht < 3)
		error_message("The map cannot have less than 3 lines", main);
	memory_allocate(main, open_file(path_to_map, main));
	parse_map(main->map, main);
	if (main->players <= 0 || main->players > 1)
		error_message("Incorrect number of starting positions", main);
	else if (main->exits <= 0)
		error_message("There is no exit for the player on the map", main);
	else if (main->collectible <= 0)
		error_message("There is no collectible item on the map", main);
	free (path_to_map);
}
