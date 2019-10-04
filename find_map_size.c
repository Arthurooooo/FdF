#include "fdf.h"

int get_max_x(const int fd)
{
    int x;
    int i;
    char *line;
    char **tab;
    x = 0;
    i = 0;

    get_next_line(fd, &line);
    tab = ft_strsplit(line, ' ');

    while(tab[i])
    {
        if (ft_isnumber(tab[i]))
        {
            x++;

        }
       i++;
    }

    return x;
    close(fd);
}


int get_max_y(const int fd)
{
    int y;
    char fullstring[1];
    y = 1;

    while ((read(fd, fullstring, 1)) != 0)
    {
        if (*fullstring == '\n')
            y++;

    }

    return y;
    close(fd);
}