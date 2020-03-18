#include "lem_in.h"

int main (void)
{
    char	*file;
    int     room;
    int     link;
    int     start;
    int     end;
    int     ants;
    int     e;
    int     a;

    ants = 0;
    start = 0;
    end = 0;
    room = 0;
    link = 0;
    e = 0;
    a = 0;
	while (get_next_line(0, &file) != 0)
    {
        if (!isValidType(file))
        {
            ft_putendl("oof");
            return (0);
        }
        if (start == 1 && e == 0)
        {
            if (!isRoom(file))
            {
                ft_putendl("Error: start bad");
                return (0);
            }
            e = 1;
        }
        if (end == 1 && a == 0)
        {
            if (!isRoom(file))
            {
                ft_putendl("Error: end bad");
                return (0);
            }
            a = 1;
        }
        if (isRoom(file))
            room++;
        if (isLink(file))
            link++;
        if (isAnt(file))
            ants++;
        if (isRoom(file))
            room++;
        if (isStart(file))
            start++;
        if (isEnd(file))
            end++;
    }
    if (ants != 1)
    {
        ft_putendl("Error: wrong ant amount");
        return (0);
    }
    if (room <= 2)
    {
        ft_putendl("Error: wrong room amount");
        return (0);
    }
    if (start != 1)
    {
        ft_putendl("Error: wrong start amount");
        return (0);
    }
    if (end != 1)
    {
        ft_putendl("Error: wrong end ammount");
        return (0);
    }
    if (link < 1)
    {
        ft_putendl("Error: too few links");
        return (0);
    }
    ft_putendl("all good");
    
    return (0);
}