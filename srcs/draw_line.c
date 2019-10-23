/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:12:06 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/21 02:26:52 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	execute_loop(t_var draw_var, t_env *env)
{
	while (1)
	{
		pixel_to_image(&env->img, draw_var.ax, draw_var.ay, PINK);
		draw_var.err_2 = draw_var.err;
		if (draw_var.ax == draw_var.bx && draw_var.ay == draw_var.by)
			break ;
		if (draw_var.err_2 > -draw_var.d.x)
		{
			draw_var.err -= draw_var.d.y;
			if (draw_var.ax < draw_var.bx)
				draw_var.ax++;
			else if (draw_var.ax > draw_var.bx)
				draw_var.ax--;
		}
		if (draw_var.err_2 < draw_var.d.y)
		{
			draw_var.err += draw_var.d.x;
			if (draw_var.ay < draw_var.by)
				draw_var.ay++;
			else if (draw_var.ay > draw_var.by)
				draw_var.ay--;
		}
	}
}

void	draw_line(t_env *env, t_point src, t_point dest)
{
	t_var dw_vr;

	src.z = src.z / 1000 + 10;
	dest.z = dest.z / 1000 + 10;
	if (src.z < 1 || dest.z < 1)
		return ;
	dw_vr.ax = (int)roundf(src.x / src.z) + WIN_WIDTH / 4;
	dw_vr.bx = (int)roundf(dest.x / dest.z) + WIN_WIDTH / 4;
	dw_vr.ay = (int)roundf(src.y / src.z) + WIN_HEIGHT / 4;
	dw_vr.by = (int)roundf(dest.y / dest.z) + WIN_HEIGHT / 4;
	if ((dw_vr.ax < 0 || dw_vr.ax > WIN_WIDTH || dw_vr.ay < 0 ||
		dw_vr.ay > WIN_WIDTH) && (dw_vr.bx < 0 || dw_vr.bx > WIN_WIDTH ||
									dw_vr.by < 0 || dw_vr.by > 500))
		return ;
	dw_vr.i = 0;
	dw_vr.d.x = abs(dw_vr.bx - dw_vr.ax);
	dw_vr.d.y = abs(dw_vr.by - dw_vr.ay);
	dw_vr.err = ((dw_vr.d.x > dw_vr.d.y ? dw_vr.d.x : -dw_vr.d.y)) >> 1;
	execute_loop(dw_vr, env);
}
