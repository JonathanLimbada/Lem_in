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

int   checkPath(t_room **room, t_paths **paths, t_room **rooms, char *end){
    int ret;
    ret = 0;
    t_room *ptr;
    t_room *Rptr;

    if ((*room)){
    printf("in room %s\n", (*room)->name);
        ptr = *room;
        while (ptr){
            Rptr = *rooms;
            if (ft_strcmp(end,ptr->name) == 0){
                ptr->val = 3;
                addRoomToPath(paths, (*room)->name);
                printf("found");
                return (3);
            }
            while (Rptr){
                if (ft_strcmp(Rptr->name,ptr->name))
                    break ;
                Rptr = Rptr->next;
            }
            ret = checkPath(&Rptr->links, paths, rooms, end);
            if (ret == 3){
                addRoomToPath(paths, (*room)->name);
                printf("found");
                return (3);
            }
            ptr = ptr->next;
        }
    }
    return (0);
}

int   pathing(t_staend **staend, t_room **rooms, t_paths **paths){
    t_room *septr; //staend pointer
    t_room *rptr;
    t_room *print;

    septr = (*staend)->start;
    //for each starting room
    while (septr){
        rptr = *rooms;
        while (rptr){
            if (ft_strcmp(rptr->name, septr->name) == 0)
                break ;
            rptr = rptr->next;
        }
        printf ("CP: %s\n",rptr->links->name);
        if (checkPath(&rptr->links, paths, rooms, (*staend)->end->name) == 3)
            break ;
        else{
            printf("No End Found\n");
            return (1);
        }
        septr = septr->next;
    }
    print = (*paths)->path;
        printf("Path: ");
    while (print){
        printf("%s ", print->name);
        print = print->next;
    }
    return (0);
}

// char *getNextRoom(t_room **rooms, char *find, char *end){
//     t_room *rptr;

//     while(rptr){
//         while(ft_strcmp(rptr->links->name,end) != 0){
//             rptr->links = rptr->links->next;
//         }
//         rptr = rptr->next;
//     }
// }




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