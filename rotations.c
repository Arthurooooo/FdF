#include "fdf.h"


void    x_rot(t_point **ptr_map, int max_x, int max_y)
{
    unsigned int x;
    unsigned int y;

    y = 0;
    x = 0;
    while (y <= max_y)
    {
        while (x <= max_x)
        {
            ptr_map[y][x].y = ptr_map[y][x].x * cos(0.17) + ptr_map[y][x].y * sin(0.17);
            ptr_map[y][x].z = -ptr_map[y][x].y * sin(0.17) + ptr_map[y][x].z * cos(0.17);
            x++;
        }
        x = 0;
        y++;
    }
}


void    y_rot(t_point ***ptr_map, int max_x, int max_y)
{
    unsigned int ptr_x;
    unsigned int y;
int test = 0;
    y = 0;
    ptr_x = 0;
    while (y <= max_y)
    {
        while (ptr_x < max_x)
        {
           // test = ptr_map[y][ptr_x]->x;
            ptr_map[y][ptr_x]->x = (int)(ptr_map[y][ptr_x]->x * cos(0.17) - ptr_map[y][ptr_x]->y * sin(0.17));
            //ptr_map[y][ptr_x].y = (ptr_map[y][ptr_x].x * sin(0.17) + ptr_map[y][ptr_x].y * cos(0.17));
            test = ptr_map[y][ptr_x]->x;
            ptr_x++;
        }
        ptr_x = 0;
        y++;
    }
}

void    z_rot(t_point **ptr_map, int max_x, int max_y)
{
    static  int rotcount;
    unsigned int x;
    unsigned int y;

    y = 0;
    x = 0;
    while (y <= max_y)
    {
        while (x <= max_x)
        {
            ptr_map[y][x].x = ptr_map[y][x].x * cos(0.17) + ptr_map[y][x].z * sin(0.17);
            ptr_map[y][x].z = -ptr_map[y][x].x * sin(0.17) + ptr_map[y][x].z * cos(0.17);
            x++;
        }
    }
    rotcount++;
}

void	handle_rots(t_env *env, t_point **ptr_tab, int keycode)
{
	if (keycode == 86)
		x_rot(ptr_tab, env->map_max_x, env->map_max_y);
	if (keycode == 91)
		y_rot(&ptr_tab, env->map_max_x, env->map_max_y);
	if (keycode == 88)
		z_rot(ptr_tab, env->map_max_x, env->map_max_y);
}