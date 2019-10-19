#include "fdf.h"

int     draw_map(t_env *env, t_image *img, t_map *map)
{
    int pnt_x;
    int linenumber;

    linenumber = 0;
    while(linenumber < (map->map_max_y))
    {
        pnt_x = 0;
        while(pnt_x < (map->map_max_x))
        {
            if (linenumber < (map->map_max_y - 1))
            {
                printf("(%f, %f) -> (%f, %f)\n", map->ptr_tab[linenumber][pnt_x].x, map->ptr_tab[linenumber][pnt_x].y, map->ptr_tab[linenumber + 1][pnt_x].x, map->ptr_tab[linenumber + 1][pnt_x].y);
                draw_line(env, img, map->ptr_tab[linenumber][pnt_x], map->ptr_tab[linenumber + 1][pnt_x]); // verticaux
            }
            if (pnt_x < (map->map_max_x - 1))
            {    
                printf("(%f, %f) -> (%f, %f)\n", map->ptr_tab[linenumber][pnt_x].x, map->ptr_tab[linenumber][pnt_x].y, map->ptr_tab[linenumber][pnt_x + 1].x, map->ptr_tab[linenumber][pnt_x + 1].y);
                draw_line(env, img, map->ptr_tab[linenumber][pnt_x], map->ptr_tab[linenumber][pnt_x + 1]); //horizontaux
            }         
            //printf("1 ligne tracee \n");
            pnt_x++;
        }
        printf("retour a la ligne\n");
            linenumber++;
    }
	printf("draw_map réussi\n");
        return 0;
}
/*
pour mettre au centre, ajouter la moitie en x et y de la map et soustraire la moitie x et y de la surface totale du quadrillage
*/