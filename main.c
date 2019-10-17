/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:43:19 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/18 01:11:19 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char const *argv[])
{
  int map_max_x;
  int map_max_y;
  int fd;
  int i;
  int temp_z;
  int cnt_x;
  char	*line;
  int linenumber;
  char * ptr_img;

  int x0 = 0; //10
  int y0 = 0; //500
  int x1 = 990; //950
  int y1 = 0 ; //950
  
  int loop = 900;
  temp_z = 0;
  cnt_x = 0;
  i = 0;
  linenumber = 0;

  t_point **ptr_tab;
  t_point *ptr_line;
  t_env env;
  t_image img;
  
  if (argc != 2)
  {
    write(1, "not enough arguments\n", 21);
    return -1;
  }
  
  	if ((fd = open((argv[1]), O_RDONLY)) == -1)
		    return -1;
  env.map_max_x = get_max_x(fd);
  env.map_max_y = get_max_y(fd);

  	if ((fd = open((argv[1]), O_RDONLY)) == -1)
		    return -1;

  if (!(ptr_tab = (t_point **)malloc(sizeof(t_point *) * (env.map_max_y))))
      return (-1);
  line = (char *)malloc(sizeof(char) * map_max_x);

  if (!(*ptr_tab = (t_point *)malloc(sizeof(t_point) * (env.map_max_x))))
    return (-1);

	while ((i < env.map_max_y + 1) && (get_next_line(fd, &line)))
	{
	  ptr_tab[linenumber] = parser(line, env.map_max_x);

    cnt_x = 0;
    while (cnt_x < env.map_max_x)
    {
      ptr_tab[linenumber][cnt_x].y = linenumber;
     // printf("%d ", ptr_tab[linenumber][cnt_x].y);

      cnt_x++;
    }
    
       //show_struct(ptr_tab);
    //printf("\n");

  	i++;
    linenumber++;
  }
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
 //on crée l'image
while (cnt < 5)
{
  //mlx_clear_window(env.mlx_ptr, env.win_ptr);
 // mlx_destroy_image(env.mlx_ptr, img.img_ptr);
  ptr_tab = zoom_in(&env, ptr_tab);
  //printf("ca entre");
  //printf("ca sort");
  //y_rot(&ptr_tab, map_max_x, map_max_y);
  cnt++;
}
  img = new_image(env);
  draw_map(&env, &img, ptr_tab);
  printf("ca devrait etre en : %i\n", ((env.map_max_x * env.zoom) / 2));
  mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, img.img_ptr, (WIN_WIDTH / 2 - ((env.map_max_x * env.zoom) * env.zoom / 2)), (WIN_HEIGHT / 2 - ((env.map_max_y * env.zoom) / 2)));
   // draw_map(mlx_ptr, win_ptr, ptr_tab, map_max_x, map_max_y);
	mlx_hook(env.win_ptr, 2, 0, key_hook, (void *)&env);
  //ptr_line = tab_to_line(ptr_tab, map_max_y, map_max_x);

    

    mlx_loop(env.mlx_ptr); 
    
    close(fd);

  return 0;
}