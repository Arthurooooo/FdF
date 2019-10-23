/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:33:23 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/21 00:04:30 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_image(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(img->ptr + ((x + y * WIN_WIDTH) * img->bpp)) = color;
}

void	new_image(t_env *env)
{
	env->img.bpp = 0;
	env->img.endian = 0;
	env->img.stride = 0;
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img.ptr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp,
	&env->img.stride, &env->img.endian);
	env->img.bpp /= 8;
}

int		clear_image(t_image *img)
{
	ft_bzero(img->ptr, (4 * WIN_WIDTH * WIN_HEIGHT));
	return (0);
}

int		refresh_image(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	new_image(env);
	draw_map(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	print_strings_to_window(*env);
	return (0);
}
