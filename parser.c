#include "fdf.h"

t_map * parser(t_env *env, t_map *map, char *av)
{
    int ptr_x;
    char ** tab;
    char *line;
    int linenumber;
    int fd;

    linenumber = 0;
    ptr_x = 0;
    map->map_max_x = get_max_x(av);
    map->map_max_y = get_max_y(av);

        if (!(map->ptr_tab = (t_point **)malloc(sizeof(t_point *) * (map->map_max_y))))
            return NULL;

    if (!(fd = open(av, O_RDONLY)))
        return NULL;

	while (get_next_line(fd, &line) == 1)
	{
        
        tab = ft_strsplit(line, ' ');
        /*
        if(!map->map_max_x)
            map->map_max_x = ft_tablen(tab);
            
        if (!(map->ptr_tab = (t_point **)malloc(sizeof(t_point *) * (map->map_max_y))))
            return NULL;
    */
        if (!(map->ptr_tab[linenumber] = (t_point *)malloc(sizeof(t_point) * (map->map_max_x))))
            return NULL;
        else
        {
            printf("BIEN MALLOC");
        }
            
        while (ptr_x < map->map_max_x)
        {
            map->ptr_tab[linenumber][ptr_x].y = linenumber;
            // printf("%d ", ptr_tab[0][linenumber][cnt_x].y);
            if (ft_isnumber(tab[ptr_x]))
            {
                map->ptr_tab[linenumber][ptr_x].z = ft_atoi(tab[ptr_x]);
                map->ptr_tab[linenumber][ptr_x].x = ptr_x;
            }
            ptr_x++;
        }
        ptr_x = 0;
        //show_struct(ptr_tab[0]);
        //printf("\n");
        linenumber++;
    }
    return map;
}

