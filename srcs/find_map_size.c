/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:40:40 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/27 10:58:29 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_max_x(char *filename)
{
	int		x;
	int		fd;
	char	*line;
	char	**tab;

	x = 0;
	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	if ((get_next_line(fd, &line)) == -1)
	{
		ft_putstr("Invalid file. Exiting now..\n");
		exit(-1);
	}
	tab = ft_strsplit(line, ' ');
	//isvalid(tab, &line);
	while (tab[x] && ft_isnumber(tab[x]))
	{
		x++;
	}
	close(fd);
	ft_tabdel(tab);
	ft_strdel(&line);
	return (x);
}

int		get_max_y(char *filename)
{
	int		y;
	int		fd;
	char	fullstring[1];

	y = 1;
	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	while ((read(fd, fullstring, 1)) != 0)
	{
		if (*fullstring == '\n')
			y++;
	}
	close(fd);
	return (y - 1);
}
