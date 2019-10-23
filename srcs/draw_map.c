/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:11:58 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/20 23:24:08 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_map(t_env *env)
{
	int pnt_x;
	int linenumber;

	linenumber = 0;
	while (linenumber < (env->map.map_max_y))
	{
		pnt_x = 0;
		while (pnt_x < (env->map.map_max_x))
		{
			if (linenumber < (env->map.map_max_y - 1))
			{
				draw_line(env, env->map.ptr_tab[linenumber][pnt_x],
				env->map.ptr_tab[linenumber + 1][pnt_x]);
			}
			if (pnt_x < (env->map.map_max_x - 1))
			{
				draw_line(env, env->map.ptr_tab[linenumber][pnt_x],
				env->map.ptr_tab[linenumber][pnt_x + 1]);
			}
			pnt_x++;
		}
		linenumber++;
	}
	return (0);
}
