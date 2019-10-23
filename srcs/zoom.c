/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 00:14:20 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/21 00:15:11 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_env *env)
{
	size_t pnt_x;
	size_t linenumber;

	pnt_x = 0;
	linenumber = 0;
	while (linenumber < (size_t)env->map.map_max_y)
	{
		pnt_x = 0;
		while (pnt_x < (size_t)env->map.map_max_x)
		{
			env->map.ptr_tab[linenumber][pnt_x].x *= 1.5;
			env->map.ptr_tab[linenumber][pnt_x].y *= 1.5;
			env->map.ptr_tab[linenumber][pnt_x].z *= 1.5;
			pnt_x++;
		}
		linenumber++;
	}
	env->zoom++;
}

void	zoom_out(t_env *env)
{
	size_t pnt_x;
	size_t linenumber;

	linenumber = 0;
	while (linenumber < (size_t)env->map.map_max_y)
	{
		pnt_x = 0;
		while (pnt_x < (size_t)env->map.map_max_x)
		{
			env->map.ptr_tab[linenumber][pnt_x].x *= 0.5;
			env->map.ptr_tab[linenumber][pnt_x].y *= 0.5;
			env->map.ptr_tab[linenumber][pnt_x].z *= 0.5;
			pnt_x++;
		}
		linenumber++;
	}
	env->zoom--;
}

void	handle_zoom(t_env *env, int keycode)
{
	if (keycode == 69)
		zoom_in(env);
	if (keycode == 78)
		zoom_out(env);
}
