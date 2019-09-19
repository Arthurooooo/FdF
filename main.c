/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:43:19 by argonthi          #+#    #+#             */
/*   Updated: 2019/09/19 00:38:10 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char const *argv[])
{
    void    *mlx_ptr;
    void    *win_ptr;
    int x;
    int y;

    int x0 = 0; //10
    int y0 = 0; //500
    int x1 = 990; //950
    int y1 = 0 ; //950
    
    int loop = 900;

   /* if(argc != 3)
    {
        printf("not enough arguments!");
        return 0;
    }*/

   /* x = atoi(argv[1]);
    y = atoi(argv[2]);*/
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
    while(loop != 0){
    draw_line(mlx_ptr, win_ptr, x0, y0, x1, y1);
  /*  int x3 = 990;
    int y3 = 990;
    int x4 = 1000;
    int y4 = 50;

    draw_line(mlx_ptr, win_ptr, x3, y3, x4, y4);
    y4++;
    x4--;*/

   // x1++;
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
    return 0;
}