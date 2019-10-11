#include "fdf.h"

int     draw_map(void* mlx_ptr, void* win_ptr, t_point ** map, int map_max_x, int map_max_y)
{
    int pnt_x;
    int real_x;
    int real_y;
    int linenumber;
    int coeff;
    int real_min_x;
    int real_min_y;
    int real_max_x;
    int real_max_y;
    int tab_x;
    int tab_y;
    int window_size_xy;
    int VALEUR;

    window_size_xy = 500;
    coeff = 20;

    real_y = (window_size_xy / 2) - ((map_max_y * coeff) / 2);
    real_x = (window_size_xy / 2) - ((map_max_x * coeff) / 2);
    real_max_y = window_size_xy - real_y;
    real_max_x = window_size_xy - real_x;
    real_min_x = real_x;
    real_min_y = real_y;
    tab_x = real_max_x - real_min_x;
    tab_y = real_max_y - real_min_y;

    pnt_x = 0;
    linenumber = 0;
    while((pnt_x <= map_max_x) && (linenumber <= map_max_y) && (real_y <= real_max_y))
    {
        printf("ici\n");

        while((pnt_x <= map_max_x) && (real_x <= real_max_x))
        {
            if (linenumber < map_max_y)
            {
                if (linenumber == 0)
                {
                    draw_line(mlx_ptr, win_ptr, real_x, real_y, real_x, (real_y + (tab_y / map_max_y))); // verticaux
                    VALEUR = (real_y + ((real_max_y - real_min_y) / map_max_y));
                }
                else
                {
                    draw_line(mlx_ptr, win_ptr, real_x, real_y, real_x, (real_y + (tab_y / map_max_y)));
                    VALEUR = (real_y + ((real_max_y - real_min_y) / map_max_y) * linenumber);
                }
            }
            if (pnt_x < map_max_x)
            {     
                if (pnt_x == 0)
                {
                    draw_line(mlx_ptr, win_ptr, real_x, real_y, (real_x + (tab_x / map_max_x)), real_y); //horizontaux
                    VALEUR = (real_x + ((real_max_x - real_min_x) / map_max_x));
                }
                else
                {
                    draw_line(mlx_ptr, win_ptr, real_x, real_y, (real_x + (tab_x / map_max_x)), real_y);
                    VALEUR = (real_x + ((real_max_x - real_min_x) / map_max_x) * pnt_x);
                }
            }         
            printf("1 ligne tracee \n");
            pnt_x++;
            real_x = real_x + (tab_x / map_max_x);
        }
            linenumber++;
            pnt_x = 0;
            real_x = (window_size_xy / 2) - tab_x / 2;
         //retourne au debut 
        
            real_y = real_y + (tab_y / map_max_y);

    }
    return 0;
}
/*
pour mettre au centre, ajouter la moitie en x et y de la map et soustraire la moitie x et y de la surface totale du quadrillage
*/