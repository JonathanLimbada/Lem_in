#include "lem_in.h"

int main (void)
{
    char	*file;
    t_valid *vals;

    vals = (t_valid *)malloc(sizeof(t_valid));
    init_vals(vals);

	while (get_next_line(0, &file) != 0)
    {
        if (!isValidType(file))
        {
            ft_putendl("oof");
            freemain(file, vals);
            return (0);
        }
        if (vals->start == 1 && vals->e == 0)
        {
            if (!isRoom(file))
            {
                ft_putendl("Error: start bad");
                freemain(file, vals);
                return (0);
            }
            vals->e = 1;
        }
        if (vals->end == 1 && vals->a == 0)
        {
            if (!isRoom(file))
            {
                ft_putendl("Error: end bad");
                freemain(file, vals);
                return (0);
            }
            vals->a = 1;
        }
        if (isRoom(file))
            vals->room++;
        if (isLink(file))
            vals->link++;
        if (isAnt(file))
            vals->ants++;
        if (isRoom(file))
            vals->room++;
        if (isStart(file))
            vals->start++;
        if (isEnd(file))
            vals->end++;
        free(file);
    }
    if (vals->ants != 1)
        NO_ANTS;
    if (vals->room <= 2)
        NUMROOMS;
    if (vals->start != 1)
        NO_START;
    if (vals->end != 1)
        NO_END; 
    if (vals->link < 1)
        NUMLINKS;
    ft_putendl("all good");
    
    free(vals);
    return (0);
}