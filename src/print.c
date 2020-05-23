#include "../lem_in.h"

void    print(t_staend *staend, t_room *rooms, t_links *links, t_comments *comments)
{
    t_room      *ptr;
    t_links     *ptr2;
    t_room      *sptr;
    t_comments  *cptr;

    ft_putstr("Ants: ");
    ft_putnbr(staend->sAnts);
    ft_putchar('\n');
    sptr = staend->start;
    while(sptr)
    {
        ft_putstr("##start\n");
        ft_putstr(sptr->name);
        ft_putchar(' ');
        ft_putnbr(sptr->x);
        ft_putchar(' ');
        ft_putnbr(sptr->y);
        ft_putchar('\n');
        sptr = sptr->next;
    }
    ft_putstr("##end\n");
        ft_putstr(staend->end->name);
        ft_putchar(' ');
        ft_putnbr(staend->end->x);
        ft_putchar(' ');
        ft_putnbr(staend->end->y);
        ft_putchar('\n');
    ptr = rooms;
    while(ptr)
    {
        ft_putstr(ptr->name);
        ft_putchar(' ');
        ft_putnbr(ptr->x);
        ft_putchar(' ');
        ft_putnbr(ptr->y);
        ft_putchar('\n');
        ptr = ptr->next;
    }
    if (links){
        ptr2 = links;
        while(ptr2)
        {
            ft_putstr(ptr2->first);
            ft_putchar('-');
            ft_putstr(ptr2->second);
            ft_putchar('\n');
            ptr2 = ptr2->next;
        }
    }
    if (comments){
        cptr = comments;
        while(cptr)
        {
            if (!ft_strequ(cptr->command, "##start") && !ft_strequ(cptr->command, "##end"))
            ft_putendl(cptr->command);
            cptr = cptr->next;
        }
    }
}