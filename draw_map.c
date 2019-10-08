#include "fdf.h"

int     draw_map(void* mlx_ptr, void* win_ptr, t_point ** map, int map_max_x, int map_max_y)
{
    int pnt_x;
    int linenumber;
    int coeff;

    coeff = 100;
    pnt_x = 0;
    linenumber = 0;
    while((pnt_x < map_max_x) && (linenumber <= map_max_y))
    {
        printf("ici\n");

        pnt_x = 0;
        while(pnt_x < map_max_x)
        {
            if (pnt_x != 0)
            {            
                draw_line(mlx_ptr, win_ptr, map[linenumber][pnt_x].x, map[linenumber][pnt_x].y, (map[linenumber][pnt_x + 1].x * coeff), map[linenumber][pnt_x + 1].y);
            }
            else
            {
                draw_line(mlx_ptr, win_ptr, map[linenumber][pnt_x].x, map[linenumber][pnt_x].y, (map[linenumber][pnt_x + 1].x + coeff), map[linenumber][pnt_x + 1].y);

            }
            
            //dessine les points horizontaux
            if ((linenumber != map_max_x) && (linenumber != 0)) //tant qu'on est pas a la derniere ligne
            {
                draw_line(mlx_ptr, win_ptr, map[linenumber][pnt_x].x, map[linenumber][pnt_x].y, map[linenumber + 1][pnt_x].x, (map[linenumber + 1][pnt_x].y * coeff));
            }
            else if((linenumber != map_max_x) && (linenumber == 0))
            {
                draw_line(mlx_ptr, win_ptr, map[linenumber][pnt_x].x, map[linenumber][pnt_x].y, map[linenumber + 1][pnt_x].x, (map[linenumber + 1][pnt_x].y + coeff));
            }
            
            printf("1 ligne tracee \n");
            pnt_x++;
        }
        linenumber++;
    }
    return 0;
}