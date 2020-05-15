#include "../lem_in.h"

void    print(t_staend *staend, t_room *rooms, t_links *links)
{
    t_room      *ptr;
    //t_links     *ptr2;
    t_room      *sptr;

    printf("Ants: %d\n",staend->sAnts);
    sptr = staend->start;
    while(sptr->next)
    {
        printf("Start name: %s  x: %d y: %d\n",sptr->name,sptr->x,sptr->y);
        sptr = sptr->next;
    }
    printf("End name: %s\tx: %d y: %d\n",staend->end->name,staend->end->x,staend->end->y);
    ptr = rooms;
    while(ptr)
    {
        printf("Room Name: %s\tx: %d y:%d\n", ptr->name, ptr->x, ptr->y);
        ptr = ptr->next;
    }
    if (links){}
    // ptr2 = links;
    // while(ptr2)
    // {
    //    printf("first: %s \t second: %s\n", ptr2->first, ptr2->second);
    //     ptr2 = ptr2->next; 
    // }
}