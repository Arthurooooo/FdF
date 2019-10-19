/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:33:23 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/19 17:38:51 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	pixel_to_image(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(img->ptr + ((x + y * WIN_WIDTH) * img->bpp)) = color;
}

t_image	new_image(t_env env)
{
	t_image		img;
	img.bpp = 0;
	img.endian = 0;
	img.stride = 0;
/*
	if (((void)img = ft_memalloc(sizeof(t_image))) == NULL)
		return img;
		*/
	if ((img.img_ptr = mlx_new_image(env.mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return img;
		
	img.ptr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.stride, &img.endian);
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

int	clear_image(t_map *map, t_image *img)
{
	ft_bzero(img->ptr, (img->bpp * map->map_max_y * map->map_max_x));
	printf("clear_image réussi\n");

	return 0;
}

int	refresh_image(t_env *env, t_image *img, t_map *map)
{
	
	clear_image(map, img);
	draw_map(env, img, map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, img->img_ptr, (WIN_WIDTH / 2 - ((map->map_max_x * env->zoom) / 2)), (WIN_HEIGHT / 2 - ((map->map_max_y * env->zoom) / 2)));
		printf("pas raté\n");
		return 0;
	
}