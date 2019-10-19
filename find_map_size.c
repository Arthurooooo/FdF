#include "fdf.h"

int get_max_x(char *filename)
{
    int x;
    int fd;
    char *line;
    char **tab;
    x = 0;

    if (!(fd = open(filename, O_RDONLY)))
        return (-1);

    get_next_line(fd, &line);
    tab = ft_strsplit(line, ' ');
    while(tab[x] && ft_isnumber(tab[x]))
    {
        x++;
    }

    close(fd);
    return x;
}


int get_max_y(char *filename)
{
    int y;
    int fd;
    char fullstring[1];

    y = 1;
    if (!(fd = open(filename, O_RDONLY)))
        return (-1);
    while ((read(fd, fullstring, 1)) != 0)
    {
        if (*fullstring == '\n')
            y++;

    }
    close(fd);
    return (y - 1);
}