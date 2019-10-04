/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:43:19 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/04 02:29:37 by argonthi         ###   ########.fr       */
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
  int cnt_z;
  char	*line;
  int linenumber;

  int x0 = 0; //10
  int y0 = 0; //500
  int x1 = 990; //950
  int y1 = 0 ; //950
  
  int loop = 900;
  temp_z = 0;
  cnt_z = 0;
  i = 0;
  linenumber = 0;

  t_point **ptr_tab;
  
  if (argc != 2)
  {
    write(1, "not enough arguments\n", 21);
    return -1;
  }
  
  fd = open((argv[1]), O_RDONLY); // protege ca
  map_max_x = get_max_x(fd);
  map_max_y = get_max_y(fd);

  if (!(ptr_tab = (t_point **)malloc(sizeof(t_point *) * (map_max_y))))
      return (-1);
//printf("taille map: \n x: %i \n y: %i \n", get_max_x(fd), get_max_y(fd));
  line = (char *)malloc(sizeof(char) * map_max_x); // CA NE READ QUE 3 CARACTERES
	while (i < map_max_y + 1)
	{
      if (!(*ptr_tab = (t_point *)malloc(sizeof(t_point) * (map_max_x))))
        return (-1);
		get_next_line(fd, &line);
    printf("line = %s \n", line);
	  ptr_tab[linenumber] = parser(line, map_max_x);
    while (ptr_tab[linenumber][cnt_z++].z)
    {
      ptr_tab[linenumber][cnt_z].z = temp_z;
      //printf("x : %d\n", ptr_tab[linenumber][cnt_z].x);
      cnt_z++;
    }
    
  	i++;
    linenumber++;
  }

int cnt;
cnt = 1;
linenumber = 0;
while (linenumber < map_max_y)
{
 // printf("\n%d\n", linenumber);
 // printf("x : %d y : %d z : %d  ||", ptr_tab[linenumber][cnt].x, ptr_tab[linenumber][cnt].y, ptr_tab[linenumber][cnt].z);
 // cnt++;
  //printf("  x : %i y : %i z : %i  ||", ptr_tab[0][cnt].x, ptr_tab[0][cnt].y, ptr_tab[0][cnt].z);
  //cnt++;
  //printf("  x : %i y : %i z : %i\n", ptr_tab[0][cnt].x, ptr_tab[0][cnt].y, ptr_tab[linenumber][cnt].z);
linenumber++;
//cnt = 0;
}



  int nbr = 0;
// printf("x: %i \n y: %i \n z: %i \n", ptr_tab[nbr].x, ptr_tab[nbr].y, ptr_tab[nbr].z);

 // printf("ptr_tab[i].z = %c \n", ptr_tab[18].z);

   /* if(argc != 3)
    {
        printf("not enough arguments!");
        return 0;
    }*/

   /* x = atoi(argv[1]);
    y = atoi(argv[2]);*/
    /*
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
    while(loop != 0){
    draw_line(mlx_ptr, win_ptr, x0, y0, x1, y1);

    int x3 = 990;
    int y3 = 990;
    int x4 = 1000;
    int y4 = 50;

    draw_line(mlx_ptr, win_ptr, x3, y3, x4, y4);
    y4++;
    x4--;*/

   // x1++;
   /*
   if(y < 1000)
   {
    y1++;
   }
   else
   {
        x1--;
   }
    loop--;
    }
    mlx_loop(mlx_ptr); 
    */
  return 0;
}