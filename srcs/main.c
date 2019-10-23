/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:43:19 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/21 02:59:44 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		cnt_zoom;
	t_env	env;

	cnt_zoom = 0;
	if (argc != 2)
	{
		write(1, "not enough arguments\n", 21);
		return (-1);
	}
	parser(&env, argv[1]);
	env.zoom = 0;
	cnt_zoom = 13;
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "mlx 42");
	new_image(&env);
	while (env.zoom != cnt_zoom)
	{
		zoom_in(&env);
	}
	draw_map(&env);
	refresh_image(&env);
	print_strings_to_window(env);
	mlx_hook(env.win_ptr, 2, 0, key_hook, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
