/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:07:08 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/18 01:14:00 by argonthi         ###   ########.fr       */
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
    int x;
    int y;
    int z;
}   t_point;

typedef	struct			s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
    int map_max_x;
    int map_max_y;
    int zoom;
}						t_env;

typedef struct		s_image
{
	void		*img_ptr;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

void    x_rot(t_point **ptr_map, int max_x, int max_y);
void    y_rot(t_point ***ptr_map, int max_x, int max_y);
void    z_rot(t_point **ptr_map, int max_x, int max_y);
t_point **		zoom_in(t_env *env, t_point ** map);
void		zoom_out(t_env *env, t_point ** map);
void		handle_zoom(t_env *env, int keycode, t_point ** map);
void    draw_line(t_env *env, t_image *img, t_point src, t_point dest);
int     draw_map(t_env *env, t_image *img, t_point ** map);
char*     random_hex(void);
t_point * parser(char *str, int map_width);
int get_max_x(const int fd);
int get_max_y(const int fd);
void    show_struct(t_point ** ptr_tab);
t_point * tab_to_line(t_point ** tab, int max_y, int max_x);
void	handle_rots(t_env *env, t_point **ptr_tab, int keycode);
void	pixel_to_image(t_env *env, t_image *img, int x, int y, uint32_t col);
t_image	new_image(t_env env);
void	print_strings_to_window(t_env env);
int		key_hook(int keycode, t_point **ptr_tab, void *env);

#define WIN_HEIGHT 500
#define WIN_WIDTH 500
#define BLUE 0x3399FF
#define PINK 0xf20c64
#define PRPL 0x671c9d
#define YELW 0xe5f928
#define KAKI 0x98af69
#define LBLU 0x5DADE2