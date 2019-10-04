#include "fdf.h"

t_point * parser(char *str, int map_width)
{
    int i;
    int largeur;
    int longueur;
    char ** tab;
    t_point *ptr_struct_tab;

    largeur = 0;
    longueur = 0;
    i = 0;

    if (!(ptr_struct_tab = (t_point *)malloc(sizeof(t_point) * map_width)))
        return NULL ;
    tab = ft_strsplit(str, ' ');
    //printf("%s \n", str);
    int y;
    y = 0;
    while (tab[0][y])
    {
        printf("%c\n", tab[0][y]);
        y++;
    }
    while(i < map_width)
    {

        if (ft_isnumber(tab[i]))
        {
            ptr_struct_tab[i].z = *tab[i];
            ptr_struct_tab[i].x = i;
            printf("x = %d\n", ptr_struct_tab[i].x);
        }
       /* else
        {
            return tab;
        }
        */
       i++;
    }
    return ptr_struct_tab;
}

