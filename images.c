/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:33:23 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/18 00:20:50 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_image(t_env *env, t_image *img, int x, int y, uint32_t col)
{
	uint32_t *ptr;

	ptr = (uint32_t *)(void *)img->ptr;
	if (x >= 0 && y >= 0
	    && x < WIN_WIDTH
	    && y < WIN_HEIGHT)
	  ptr[(x + y * WIN_HEIGHT) * img->bpp] = col;
}

t_image	new_image(t_env env)
{
	t_image		img;
/*
	if (((void)img = ft_memalloc(sizeof(t_image))) == NULL)
		return img;
		*/
	if ((img.img_ptr = mlx_new_image(env.mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return img;
		
	img.ptr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.stride,
			&img.endian);
	img.bpp /= 8;
	return (img);
}
/*
t_image	del_image(t_env *env, t_image *img)
{
	if (img != NULL)
	{
		if (img->img_ptr != NULL)
			mlx_destroy_image(env->mlx_ptr, img->img_ptr);
		ft_memdel((void **)&img);
	}
	return &img;
}
*/
/*
void	image_set_pixel(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(img->img_ptr + ((x + y * (WIN_WIDTH)) * img->bpp)) = color;
}
*/