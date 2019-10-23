/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:58:47 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/20 23:58:49 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_horizontally(t_env *env, int keycode)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < (size_t)env->map.map_max_y)
	{
		x = 0;
		while (x < (size_t)env->map.map_max_x)
		{
			((keycode == 0) ? (env->map.ptr_tab[y][x].x -= 50)
			: (env->map.ptr_tab[y][x].x += 50));
			x++;
		}
		y++;
	}
}

void	move_vertically(t_env *env, int keycode)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < (size_t)env->map.map_max_y)
	{
		x = 0;
		while (x < (size_t)env->map.map_max_x)
		{
			((keycode == 1) ? (env->map.ptr_tab[y][x].y += 50)
			: (env->map.ptr_tab[y][x].y -= 50));
			x++;
		}
		y++;
	}
}

void	handle_moves(t_env *env, int keycode)
{
	if (keycode == 0 || keycode == 2)
		move_horizontally(env, keycode);
	if (keycode == 1 || keycode == 13)
		move_vertically(env, keycode);
}
