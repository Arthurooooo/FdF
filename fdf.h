/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:07:08 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/19 19:39:34 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h> 
# include "libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdint.h>
#endif


typedef struct s_point 
{
    double x;
    double y;
    int z;
}   t_point;

typedef	struct			s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	int zoom;
	t_map	map;
}						t_env;

typedef struct		s_image
{
	void		*img_ptr;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct s_map
{
	t_point **ptr_tab;
	int map_max_x;
    int map_max_y;
}	t_map;

typedef struct t_all
{

}	s_all;

void    x_rot(t_map *map, int max_x, int max_y);
void    y_rot(t_map *map, int max_x, int max_y);
void    z_rot(t_map *map, int max_x, int max_y);
t_map *		zoom_in(t_env *env, t_map * map);
void	zoom_out(t_env *env, t_map * map);
void	handle_zoom(t_env *env, t_map * map, int keycode);
void    draw_line(t_env *env, t_image *img, t_point src, t_point dest);
int     draw_map(t_env *env, t_image *img, t_map *map);
char*     random_hex(void);
t_map * parser(t_env *env, t_map *map, char *av);
int get_max_x(char *filename);
int get_max_y(char *filename);
void    show_struct(t_point ** ptr_tab);
t_point * tab_to_line(t_point ** tab, int max_y, int max_x);
void	handle_rots(t_map *map, int keycode);

void	pixel_to_image(t_image *img, int x, int y, int color);
t_image	new_image(t_env env);
int	clear_image(t_map *map, t_image *img);
int	refresh_image(t_env *env, t_image *img, t_map *map);

void	print_strings_to_window(t_env env);
int		key_hook(int keycode, t_map *map, t_env *env);

#define WIN_HEIGHT 500
#define WIN_WIDTH 500
#define BLUE 0x3399FF
#define PINK 0xf20c64
#define PRPL 0x671c9d
#define YELW 0xe5f928
#define KAKI 0x98af69
#define LBLU 0x5DADE2