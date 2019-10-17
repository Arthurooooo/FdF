#include "fdf.h"

t_point **		zoom_in(t_env *env, t_point ** map)
{
	int pnt_x;
    int linenumber;
int i;
	pnt_x = 0;
    linenumber = 0;
	while (linenumber < env->map_max_y)
	{
        while (pnt_x < env->map_max_x)
        {    
            i = map[linenumber][pnt_x].x;
            map[linenumber][pnt_x].x *= 1.5;
            map[linenumber][pnt_x].y *= 1.5;
            map[linenumber][pnt_x].z *= 1.5;
            pnt_x++;
        }
        linenumber++;
        pnt_x = 0;
	}
    env->zoom++;
    return map;
}

void		zoom_out(t_env *env, t_point ** map)
{
	size_t pnt_x;
    size_t linenumber;

	pnt_x = 0;
    linenumber = 0;
	while (linenumber <= env->map_max_y)
	{
        while (pnt_x <= env->map_max_x)
        {    
            map[linenumber][pnt_x].x *= 0.5;
            map[linenumber][pnt_x].y *= 0.5;
            map[linenumber][pnt_x].z *= 0.5;
            
            pnt_x++;
        }
        linenumber++;
        pnt_x = 0;
	}
    env->zoom--;
}

void			handle_zoom(t_env *env, int keycode, t_point ** map)
{
	if (keycode == 69)
		zoom_in(env, map);
	if (keycode == 78)
		zoom_out(env, map);
}