/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:11:54 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/20 23:15:17 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rot(t_env *env)
{
	unsigned int x;
	unsigned int y;

	y = 0;
	while (y < (unsigned int)env->map.map_max_y)
	{
		x = 0;
		while (x < (unsigned int)env->map.map_max_x)
		{
			env->map.ptr_tab[y][x].y = env->map.ptr_tab[y][x].y
			* cos(0.17) + env->map.ptr_tab[y][x].z * sin(0.17);
			env->map.ptr_tab[y][x].z = -(env->map.ptr_tab[y][x].y)
			* sin(0.17) + env->map.ptr_tab[y][x].z * cos(0.17);
			x++;
		}
		y++;
	}
}

void	y_rot(t_env *env)
{
	unsigned int ptr_x;
	unsigned int y;

	y = 0;
	while (y < (unsigned int)env->map.map_max_y)
	{
		ptr_x = 0;
		while (ptr_x < (unsigned int)env->map.map_max_x)
		{
			env->map.ptr_tab[y][ptr_x].x = (env->map.ptr_tab[y][ptr_x].x
			* cos(0.17) - env->map.ptr_tab[y][ptr_x].y * sin(0.17));
			env->map.ptr_tab[y][ptr_x].y = (env->map.ptr_tab[y][ptr_x].x
			* sin(0.17) + env->map.ptr_tab[y][ptr_x].y * cos(0.17));
			ptr_x++;
		}
		y++;
	}
}

void	z_rot(t_env *env)
{
	static		int	rotcount = 0;
	unsigned	int	x;
	unsigned	int	y;

	y = 0;
	while (y < (unsigned int)env->map.map_max_y)
	{
		x = 0;
		while (x < (unsigned int)env->map.map_max_x)
		{
			env->map.ptr_tab[y][x].x = (env->map.ptr_tab[y][x].x
			* cos(0.17) + env->map.ptr_tab[y][x].z * sin(0.17));
			env->map.ptr_tab[y][x].z = (-env->map.ptr_tab[y][x].x
			* sin(0.17) + env->map.ptr_tab[y][x].z * cos(0.17));
			x++;
		}
		y++;
	}
	rotcount++;
}

void	handle_rots(t_env *env, int keycode)
{
	if (keycode == 86)
		x_rot(env);
	if (keycode == 91)
		y_rot(env);
	if (keycode == 88)
		z_rot(env);
}
