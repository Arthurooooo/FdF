/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:07:08 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/21 05:46:28 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include <unistd.h>
# include <math.h>
# include <stdint.h>
# define WIN_HEIGHT 750
# define WIN_WIDTH 750
# define BLUE 0x3399FF
# define PINK 0xf20c64
# define PRPL 0x671c9d
# define YELW 0xe5f928
# define KAKI 0x98af69
# define LBLU 0x5DADE2

typedef	struct			s_point
{
	double		x;
	double		y;
	double		z;
}						t_point;

typedef struct			s_image
{
	void		*img_ptr;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}						t_image;

typedef	struct			s_map
{
	t_point		**ptr_tab;
	int			map_max_x;
	int			map_max_y;
}						t_map;

typedef	struct			s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			zoom;
	t_map		map;
	t_image		img;
}						t_env;

typedef	struct			s_delta
{
	int			x;
	int			y;
}						t_delta;

typedef	struct			s_var
{
	int			ax;
	int			bx;
	int			ay;
	int			by;
	int			err_2;
	int			err;
	size_t		i;
	t_delta		d;
}						t_var;

void					x_rot(t_env *env);
void					y_rot(t_env *env);
void					z_rot(t_env *env);

void					zoom_in(t_env *env);
void					zoom_out(t_env *env);

void					move_vertically(t_env *env, int keycode);
void					move_horizontally(t_env *env, int keycode);

void					handle_zoom(t_env *env, int keycode);
void					handle_rots(t_env *env, int keycode);
void					handle_moves(t_env *env, int keycode);

void					execute_loop(t_var draw_var, t_env *env);
void					draw_line(t_env *env, t_point src, t_point dest);
int						draw_map(t_env *env);

char					*random_hex(void);
t_map					*parser(t_env *env, char *av);
int						do_loop(t_env *env, int fd, int ptr_x, int linenumber);
int						get_max_x(char *filename);
int						get_max_y(char *filename);
void					show_struct(t_point **ptr_tab);
t_point					*tab_to_line(t_point **tab, int max_y, int max_x);
char					**free_all(char **tab, char **line);
int						isvalid(char **tab, char **line);

void					pixel_to_image(t_image *img, int x, int y, int color);
void					new_image(t_env *env);
int						clear_image(t_image *img);
int						refresh_image(t_env *env);

void					print_strings_to_window(t_env env);
int						key_hook(int keycode, void *env_temp);
int						close_win(void *param);
#endif
