/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 00:11:58 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/21 05:56:39 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		isvalid(char **tab, char **line)
{
	int x;

	x = 0;
	while (line[0][x])
	{
		if (ft_isdigit(line[0][x]) || line[0][x] == '\0' ||
		!(line[0][x] == ' ' && line[0][x + 1] == ' ' && line[0][x + 2] == ' '))
		{
			x++;
		}
		else
		{
			tab = free_all(tab, line);
			ft_putstr("invalid file! Exiting... \n");
			exit(-1);
		}
	}
	return (1);
}

char	**free_all(char **tab, char **line)
{
	ft_tabdel(tab);
	tab = NULL;
	ft_strdel(line);
	return (tab);
}

int		do_loop(t_env *env, int fd, int ptr_x, int linenumber)
{
	char	*line;
	char	**tab;

	while (get_next_line(fd, &line) == 1)
	{
		ptr_x = -1;
		tab = ft_strsplit(line, ' ');
		isvalid(tab, &line);
		if (!(env->map.ptr_tab[linenumber] =
		(t_point *)malloc(sizeof(t_point) * (env->map.map_max_x))))
			return (-1);
		while (++ptr_x < env->map.map_max_x)
		{
			env->map.ptr_tab[linenumber][ptr_x].y = linenumber;
			env->map.ptr_tab[linenumber][ptr_x].z = ft_atoi(tab[ptr_x]);
			env->map.ptr_tab[linenumber][ptr_x].x = ptr_x;
		}
		tab = free_all(tab, &line);
		linenumber++;
	}
	tab = free_all(tab, &line);
	return (0);
}

t_map	*parser(t_env *env, char *av)
{
	int		ptr_x;
	int		linenumber;
	int		fd;

	linenumber = 0;
	ptr_x = -1;
	if (!(fd = open(av, O_RDONLY)))
	{
		ft_putstr("Not a valid map. \n");
		return (NULL);
	}
	env->map.map_max_x = get_max_x(av);
	env->map.map_max_y = get_max_y(av);
	if (!(env->map.ptr_tab =
	(t_point **)malloc(sizeof(t_point *) * (env->map.map_max_y))))
		return (NULL);
	do_loop(env, fd, ptr_x, linenumber);
	return (&env->map);
}
