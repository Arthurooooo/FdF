#include "fdf.h"

int		key_hook(int keycode, t_point **ptr_tab, void *env)
{
	int		scale;
	t_env	*cast_env;

	cast_env = (t_env *)env;
	scale = 20;
	mlx_clear_window(cast_env->mlx_ptr, cast_env->win_ptr);
	print_strings_to_window(*cast_env);
	//if (keycode == 53)
	//	close_win(cast_env);
	/* if (keycode == 0 || keycode == 1 || keycode == 2
			|| keycode == 13 || keycode == 125 || keycode == 126)
		handle_moves(cast_env, keycode);
	*/
	if (keycode == 86 || keycode == 91 || keycode == 88)
		handle_rots(cast_env, ptr_tab, keycode);
	if (keycode == 69 || keycode == 78)
		handle_zoom(cast_env, keycode, ptr_tab);
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