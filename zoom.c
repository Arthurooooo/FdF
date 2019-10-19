#include "fdf.h"

t_map *		zoom_in(t_env *env, t_map * map)
{
	int pnt_x;
    int linenumber;

	pnt_x = 0;
    linenumber = 0;
    printf("avant %f\n", map->ptr_tab[10][18].x);
	while (linenumber < map->map_max_y)
	{
        pnt_x = 0;
        while (pnt_x < map->map_max_x)
        {    
            //pnt_x = map->ptr_tab[linenumber][pnt_x].x;
            map->ptr_tab[linenumber][pnt_x].x *= 1.5;
            map->ptr_tab[linenumber][pnt_x].y *= 1.5;
            map->ptr_tab[linenumber][pnt_x].z *= 1.5;
            pnt_x++;
        }
        linenumber++;
	}
    printf("apres %f\n", map->ptr_tab[10][18].x);
    env->zoom++;
    return map;
}

void		zoom_out(t_env *env, t_map * map)
{
	size_t pnt_x;
    size_t linenumber;

	pnt_x = 0;
    linenumber = 0;
	while (linenumber <= map->map_max_y)
	{
        while (pnt_x <= map->map_max_x)
        {    
            map->ptr_tab[linenumber][pnt_x].x *= 0.5;
            map->ptr_tab[linenumber][pnt_x].y *= 0.5;
            map->ptr_tab[linenumber][pnt_x].z *= 0.5;
            
            pnt_x++;
        }
        linenumber++;
        pnt_x = 0;
	}
    env->zoom--;
}

void			handle_zoom(t_env *env, t_map * map, int keycode)
{
	if (keycode == 69)
		zoom_in(env, map);
	if (keycode == 78)
		zoom_out(env, map);
}