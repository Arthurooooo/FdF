/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:12:01 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/20 23:57:26 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, void *env_temp)
{
	t_env *env;

	env = (t_env *)env_temp;
	print_strings_to_window(*env);
	if (keycode == 53)
		close_win(env);
	if (keycode == 0 || keycode == 1 || keycode == 2
			|| keycode == 13 || keycode == 125 || keycode == 126)
		handle_moves(env, keycode);
	if (keycode == 86 || keycode == 91 || keycode == 88)
		handle_rots(env, keycode);
	if (keycode == 69 || keycode == 78)
		handle_zoom(env, keycode);
	refresh_image(env);
	return (0);
}

int		close_win(void *param)
{
	(void)param;
	exit(0);
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
			"S : PULL_CLOSER");
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 80, LBLU,
			"+ : ZOOM_IN");
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 95, LBLU,
			"- : ZOOM_OUT");
}
