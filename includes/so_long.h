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

#ifndef SO_LONG_H
# define SO_LONG_H
# define PIXEL	64
# define W		13
# define A		0
# define S		1
# define D		2
# define ESC	53
# define CANCEL 17

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_image
{
	void	*player;
	void	*collectible;
	void	*exits_close;
	void	*exits_open;
	void	*floor;
	void	*wall;
}	t_image;

typedef struct s_main
{
	char	**map;
	void	*mlx;
	void	*win;
	int		lenght;
	int		widht;
	int		collectible;
	int		players;
	int		exits;
	int		steps;
	int		x;
	int		y;
	t_image	*img;
}	t_main;

void	error_message(char *str, t_main *main);

int		gnl(char **str, int fd, t_main *main);
void	memory_allocate(t_main	*main, int fd);
void	cart_validation(char *map_file, t_main *main);
void	count_size_of_map(int fd, t_main *main);
int		check_empty_string(char *str);

void	draw_map(t_main *main, int widht, int lenght);
int 	press_key(int keycode, t_main *main);
int		close_window(t_main *main);

#endif