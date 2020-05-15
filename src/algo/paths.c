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
            return (1);
        }
        ptr = ptr->next;
    }
    return (0);
}

int   checkPath(t_room *links, t_paths **paths, t_room **rooms, int dist, t_staend **staend){
    int ret;
    ret = 0;
    //t_room *ptr;
    t_room *Rptr;
            printf("in ");
        while (links){
             Rptr = *rooms;
            if (checkIfStart(staend,links->name, dist)){
                return (3);
            }
            while (Rptr){
                if (ft_strcmp(Rptr->name,links->name) == 0)
                    break ;
                Rptr = Rptr->next;
            }
            if (Rptr->dist == -1){
                Rptr->dist = dist;
                printf("set: %s - dist: %d\n",Rptr->name, dist);
            }
            //     printf("\nl: %s\n", links->name);
            //     prev = links->name;
            //     if (ft_strcmp(Rptr->links->name,links->name))
            //         Rptr->links = Rptr->links->next;
            ret = checkPath(Rptr->links, paths, rooms, dist++, staend);
            if (ret == 3)
                return (3);
            //     if (ret == 3){
            //         addRoomToPath(paths, links->name);
            //         printf("found");
            //         return (3);
            //     }
            links = links->next;
        }
    return (0);
}

int   pathing(t_staend **staend, t_room **rooms, t_paths **paths){
    t_room *sptr; //staend pointer
   // t_room *rptr;
    //t_room *print;

    (*staend)->end->dist = 0;
    sptr = (*staend)->end;
        
    if (checkPath(sptr->links, paths, rooms, 1, staend) == 3){
        printf("Found path\n");
    }else{
        printf("No End Found\n");
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




//for each starting rooms links
        // links = septr->links;
        // while (links){
        //     lNext = 0;
        //     // if start link = end
        //     if (ft_strcmp(links->name,(*staend)->end->name) == 0){
        //         //end reached, path success
        //         addRoomToPath(paths, links->name);
        //         break ;
        //         // reset all path visited except completed path rooms
        //     }else{
        //         addRoomToPath(paths, links->name);
        //         while(rptr){
        //             if (ft_strcmp(rptr->name,links->name) == 0)
        //                 links = rptr->links;
        //             else
        //                 rptr = rptr->next;
        //         }
        //         links->visited = 1;
        //         //set room to visited
        //     }
        //     if (lNext == 0)
        //         links = links->next;
        // }
        // valPathGetLen(); //count path steps and add to pathlen
        // if (septr->next){
        //     malNewPath(); //malloc for new path
        //     pcount++;
        // }