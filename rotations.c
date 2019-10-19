#include "fdf.h"


void    x_rot(t_map *map, int max_x, int max_y)
{
    unsigned int x;
    unsigned int y;

    y = 0;
    x = 0;
    while (y <= max_y)
    {
        while (x <= max_x)
        {
            map->ptr_tab[y][x].y = map->ptr_tab[y][x].x * cos(0.17) + map->ptr_tab[y][x].y * sin(0.17);
            map->ptr_tab[y][x].z = -map->ptr_tab[y][x].y * sin(0.17) + map->ptr_tab[y][x].z * cos(0.17);
            x++;
        }
        x = 0;
        y++;
    }
}


void    y_rot(t_map *map, int max_x, int max_y)
{
    unsigned int ptr_x;
    unsigned int y;
    int test; 
    test = 0;
    y = 0;
    ptr_x = 0;
    while (y <= max_y)
    {
        while (ptr_x < max_x)
        {
           // test = map->ptr_tab[y][ptr_x]->x;
            map->ptr_tab[y][ptr_x].x = (int)(map->ptr_tab[y][ptr_x].x * cos(0.17) - map->ptr_tab[y][ptr_x].y * sin(0.17));
            //map->ptr_tab[y][ptr_x].y = (map->ptr_tab[y][ptr_x].x * sin(0.17) + map->ptr_tab[y][ptr_x].y * cos(0.17));
            test = map->ptr_tab[y][ptr_x].x;
            ptr_x++;
        }
        ptr_x = 0;
        y++;
    }
}

void    z_rot(t_map *map, int max_x, int max_y)
{
    static  int rotcount;
    unsigned int x;
    unsigned int y;

    y = 0;
    x = 0;
    rotcount = 0;
    while (y <= max_y)
    {
        while (x <= max_x)
        {
            map->ptr_tab[y][x].x = map->ptr_tab[y][x].x * cos(0.17) + map->ptr_tab[y][x].z * sin(0.17);
            map->ptr_tab[y][x].z = -map->ptr_tab[y][x].x * sin(0.17) + map->ptr_tab[y][x].z * cos(0.17);
            x++;
        }
    }
    rotcount++;
}

void	handle_rots(t_map *map, int keycode)
{
	if (keycode == 86)
		x_rot(map, map->map_max_x, map->map_max_y);
	if (keycode == 91)
		y_rot(map, map->map_max_x, map->map_max_y);
	if (keycode == 88)
		z_rot(map, map->map_max_x, map->map_max_y);
}