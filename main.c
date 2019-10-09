/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:43:19 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/09 16:39:26 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char const *argv[])
{
  void    *mlx_ptr;
  void    *win_ptr;
  int map_max_x;
  int map_max_y;
  int fd;
  int i;
  int temp_z;
  int cnt_x;
  char	*line;
  int linenumber;

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
  
  if (argc != 2)
  {
    write(1, "not enough arguments\n", 21);
    return -1;
  }
  
  	if ((fd = open((argv[1]), O_RDONLY)) == -1)
		    return -1;
  map_max_x = get_max_x(fd);
  map_max_y = get_max_y(fd);

  	if ((fd = open((argv[1]), O_RDONLY)) == -1)
		    return -1;

  if (!(ptr_tab = (t_point **)malloc(sizeof(t_point *) * (map_max_y))))
      return (-1);
//printf("taille map: \n x: %i \n y: %i \n", get_max_x(fd), get_max_y(fd));
  line = (char *)malloc(sizeof(char) * map_max_x);

  if (!(*ptr_tab = (t_point *)malloc(sizeof(t_point) * (map_max_x))))
    return (-1);

	while ((i < map_max_y + 1) && (get_next_line(fd, &line)))
	{
    //printf("%s\n", line);

	  ptr_tab[linenumber] = parser(line, map_max_x);
    //printf("%d", ptr_tab[linenumber][3].y);

    cnt_x = 0;
    while (cnt_x < map_max_x)
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

int cnt;
cnt = 1;
linenumber = 0;
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


  int nbr = 0;
// printf("x: %i \n y: %i \n z: %i \n", ptr_tab[nbr].x, ptr_tab[nbr].y, ptr_tab[nbr].z);

 // printf("ptr_tab[i].z = %c \n", ptr_tab[18].z);
    
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 250, 250, "mlx 42");

    draw_map(mlx_ptr, win_ptr, ptr_tab, map_max_x, map_max_y);

    mlx_loop(mlx_ptr); 
    
       close(fd);

  return 0;
}