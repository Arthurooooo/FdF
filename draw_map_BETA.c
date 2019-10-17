#include "fdf.h"

int     draw_map(t_env *env, t_image *img, t_point ** map)
{
    int pnt_x;
    int linenumber;

    pnt_x = 0;
    linenumber = 0;
    while((pnt_x <= env->map_max_x) && (linenumber < env->map_max_y))
    {
        while((pnt_x <= env->map_max_x))
        {
            if (linenumber < env->map_max_y - 1)
            {
                draw_line(env, img, map[linenumber][pnt_x], map[linenumber + 1][pnt_x]); // verticaux
            }
            if (pnt_x < env->map_max_x)
            {     
                draw_line(env, img, map[linenumber][pnt_x], map[linenumber][pnt_x + 1]); //horizontaux
            }         
            printf("1 ligne tracee \n");
            pnt_x++;
        }
            linenumber++;
            pnt_x = 0;
    }
    printf("ca finit");
    return 0;
}
/*
pour mettre au centre, ajouter la moitie en x et y de la map et soustraire la moitie x et y de la surface totale du quadrillage
*/