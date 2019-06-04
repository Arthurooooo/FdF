/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:43:19 by argonthi          #+#    #+#             */
/*   Updated: 2019/05/28 18:39:06 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int main(int argc, char const *argv[])
{
    void    *mlx_ptr;
    void    *win_ptr;
    int x;
    int y;

    int x0 = 50;
    int y0 = 50;
    int x1 = 100;
    int y1 = 300;
    
    int loop = 250;

   /* if(argc != 3)
    {
        printf("not enough arguments!");
        return 0;
    }*/

   /* x = atoi(argv[1]);
    y = atoi(argv[2]);*/
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    //mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLUE);
    while(loop != 0){
    draw_line(mlx_ptr, win_ptr, x0, y0, x1, y1);
    x1++;
    y1--;
    loop--;
    }
    mlx_loop(mlx_ptr);
    return 0;
}