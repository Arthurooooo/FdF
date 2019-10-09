#include "fdf.h"

int     draw_map(void* mlx_ptr, void* win_ptr, t_point ** map, int map_max_x, int map_max_y)
{
    int pnt_x;
    int real_x;
    int real_y;
    int linenumber;
    int coeff;

    real_y = 250 - (map_max_y / 2);
    real_x = 250 - (map_max_x / 2);
    coeff = 1;
    pnt_x = 0;
    linenumber = 0;
    while((pnt_x < map_max_x) && (linenumber <= map_max_y))
    {
        printf("ici\n");

        pnt_x = 0;
        while(pnt_x < map_max_x)
        {

            if (linenumber != 0) //tant qu'on est pas a la derniere ligne
            {
                draw_line(mlx_ptr, win_ptr, real_x, real_y, real_x, (real_y * coeff));
            }
            else if(linenumber == 0)
            {
                draw_line(mlx_ptr, win_ptr, real_x, real_y, real_x, (real_y + coeff));
            }


            if (pnt_x != 0) //dessine les points horizontaux
            {          
                draw_line(mlx_ptr, win_ptr, real_x, real_y, (real_x * coeff), real_y);
            }
            else
            {

                draw_line(mlx_ptr, win_ptr, real_x, real_y, (real_x + coeff), real_y);
            }
            
            printf("1 ligne tracee \n");
            pnt_x++;
            if (real_x == 0)
            {
                real_x = real_x + coeff;
            }
            else
            {
                real_x = real_x * coeff;
            }
        }
        if (linenumber == 0)
        {
            real_y = real_y + coeff;
        }
        else
        {
            real_y = real_y * coeff;
        }
        
        
        linenumber++;
    }
    return 0;
}
/*
pour mettre au centre, ajouter la moitie en x et y de la map et soustraire la moitie x et y de la surface totale du quadrillage
*/