#include "fdf.h"

int		key_hook(int keycode, t_map *map, t_env *env)
{
	int		scale;

	scale = 20;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	print_strings_to_window(*env);
	//if (keycode == 53)
	//	close_win(cast_env);
	/* if (keycode == 0 || keycode == 1 || keycode == 2
			|| keycode == 13 || keycode == 125 || keycode == 126)
		handle_moves(cast_env, keycode);
	*/
	if (keycode == 86 || keycode == 91 || keycode == 88)
		handle_rots(map, keycode);
	if (keycode == 69 || keycode == 78)
		handle_zoom(env, map, keycode);
	//draw_map(*cast_env, );
	return (0);
}

void	print_strings_to_window(t_env env)
{
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 20, LBLU,
			"A : MOVE_RIGHT");
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 35, LBLU,
			"F : MOVE_LEFT");
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 50, LBLU,
			"W : PUSH_AWAY");
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 65, LBLU,
			"A : PULL_CLOSER");
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 80, LBLU,
			"+ : ZOOM_IN");
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 95, LBLU,
			"- : ZOOM_OUT");
}