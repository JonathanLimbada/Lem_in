#include "../../lem_in.h"

void    addRoomToPath(t_paths **paths, char *room){
    t_room *ptr;

    if (!(*paths)->path){
        ptr = malloc(sizeof(t_room));
        ptr->name = room;
        (*paths)->path = ptr;
    }
    else{
        ptr = malloc(sizeof(t_room));
        ptr->name = room;
        ptr->next = (*paths)->path;
        (*paths)->path = ptr;
    }
}

int checkIfStart(t_staend **staend, char *find, int dist){
    t_room *ptr;
    ptr = (*staend)->start;

    while(ptr){
        if (ft_strcmp(ptr->name, find) == 0){
            ptr->dist = dist;
            ft_putstr(ptr->name);
            ft_putstr(" dist set ");
            ft_putnbr(dist);
            return (1);
        }
        ptr = ptr->next;
    }
    return (0);
}

int   checkPath(t_room *links, t_paths **paths, t_room **rooms, int dist, t_staend **staend){
    int ret = 0;
    //t_room *ptr;
    t_room *Rptr;
    ft_putstr("in - ");
    if (!links){
        ft_putstr("no links");
    }
    while (links){

        ft_putstr("link: ");
        ft_putstr(links->name);
        ft_putstr("\n");
        if (checkIfStart(staend,links->name, dist)){
            return (3);
        }
        Rptr = *rooms;
        while (Rptr){
           if (ft_strcmp(Rptr->name,links->name) == 0)
               break ;
           Rptr = Rptr->next;
        }
        ft_putstr("rptr: ");
        ft_putstr(Rptr->name);
        ft_putnbr(Rptr->dist);
        if (Rptr->dist == -1 || Rptr->dist == 0){
            Rptr->dist = dist;
            ft_putstr("\nset: ");
            ft_putstr(Rptr->name);
            ft_putstr(" - dist: ");
            ft_putnbr(dist);
            ft_putchar('\n');
            ret = checkPath(Rptr->links, paths, rooms, dist + 1, staend);
            if (ret == 3)
                return (3);
        }
        links = links->next;
    }
    return (0);
}

int   pathing(t_staend **staend, t_room **rooms, t_paths **paths){
    t_room *sptr;
   // t_room *rptr;
    //t_room *print;

    (*staend)->end->dist = 0;
    sptr = (*staend)->end;
        
    if (checkPath(sptr->links, paths, rooms, 1, staend) == 3){
        ft_putendl("Found path");
    }else{
        ft_putendl("No End Found");
        return (1);
    }
    // print = (*paths)->path;
    // printf("\nPath: ");
    // while (print){
    //     printf("%s ", print->name);
    //     print = print->next;
    // }
    // printf("\n");
    return (0);
}