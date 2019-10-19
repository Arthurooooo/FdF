/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:43:19 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/19 17:27:43 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
  int i;
  int temp_z;
  int cnt_x;
  int linenumber;

  int x0 = 0; //10
  int y0 = 0; //500
  int x1 = 990; //950
  int y1 = 0 ; //950
  
  temp_z = 0;
  cnt_x = 0;
  i = 0;
  linenumber = 0;

  t_point ** ptr_tab;
  t_point *ptr_line;
  t_env env;
  t_image img;
  t_map map;
  
  if (argc != 2)
  {
    write(1, "not enough arguments\n", 21);
    return -1;
  }
/*
  	if ((fd = open((argv[1]), O_RDONLY)) == -1)
		    return -1;
*/
//map = malloc(sizeof(t_map));
parser(&env, &map, argv[1]);
printf("ta grand mere\n");

/*
int cnt;
cnt = 1;
linenumber = 0;
*/
/*while (linenumber < map_max_y)
{
 // printf("\n%d\n", linenumber);
 // printf("x : %d y : %d z : %d  ||", ptr_tab[linenumber][cnt].x, ptr_tab[linenumber][cnt].y, ptr_tab[linenumber][cnt].z);
 // cnt++;
  //printf("  x : %i y : %i z : %i  ||", ptr_tab[0][cnt].x, ptr_tab[0][cnt].y, ptr_tab[0][cnt].z);
  //cnt++;
  //printf("  x : %i y : %i z : %i\n", ptr_tab[0][cnt].x, ptr_tab[0][cnt].y, ptr_tab[linenumber][cnt].z);
linenumber++;
//cnt = 0;
}*/

  env.zoom = 0;
  int nbr = 0;
    env.mlx_ptr = mlx_init();
    env.win_ptr = mlx_new_window(env.mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "mlx 42");
int cnt = 0;
while (cnt < 6)
{
  //mlx_clear_window(env.mlx_ptr, env.win_ptr);
 // mlx_destroy_image(env.mlx_ptr, img.img_ptr);
 
  zoom_in(&env, &map);
  //printf("ca entre");
  //printf("ca sort");
  //y_rot(&ptr_tab, map_max_x, map_max_y);
  cnt++;
}
  img = new_image(env);  //on crée l'image

  draw_map(&env, &img, &map);
  printf("ca devrait etre en : %i\n", ((map.map_max_x * env.zoom) / 2));
  mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, img.img_ptr, (WIN_WIDTH / 2 - ((map.map_max_x * env.zoom) / 2)), (WIN_HEIGHT / 2 - ((map.map_max_y * env.zoom) / 2)));
	mlx_hook(env.win_ptr, 2, 0, key_hook, (void *)&env);

  while (cnt < 10)
  {
    sleep(1);
    refresh_image(&env, &img, &map);
    zoom_in(&env, &map);
    printf("refresh\n");
    cnt++;
  }
  

    

    mlx_loop(env.mlx_ptr); 
    

  return 0;
}