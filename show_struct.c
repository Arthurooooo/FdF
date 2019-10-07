#include "fdf.h"

void    show_struct(t_point ** ptr_tab)
{
    int xx = 0;
    int y = 0;
    while((xx < 19) && (y < 1))
    {
        printf(" x: %d |", ptr_tab[y][xx].x);
    xx++;
    }
    printf("\n");
xx = 0;
        while((xx < 19) && (y < 1))
    {
        printf(" y: %d |", ptr_tab[y][xx].y);
    xx++;
    }
xx = 0;
    printf("\n");
        while((xx < 19) && (y < 1))
    {
        printf(" z: %d |", ptr_tab[y][xx].z);
    xx++;
    }
}