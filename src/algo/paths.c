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
        if (find){
        if (ft_strcmp(ptr->name, find) == 0){
            ptr->dist = dist;
            // ft_putstr(ptr->name);
            // ft_putstr(" dist set ");
            // ft_putnbr(dist);
            return (1);
        }
        }
        ptr = ptr->next;
    }
    return (0);
}

int   setDist(t_room *links, t_paths **paths, t_room **rooms, int dist, t_staend **staend){
    int ret = 0;
    //t_room *ptr;
    t_room *Rptr;
    printf("in - ");
    if (!links){
        printf("no links");
    }
    while (links){
        ft_putstr("link: ");
        ft_putstr(links->name);
        ft_putstr("\n");
        if (checkIfStart(staend,links->name,1)){
            return (3);
        }
        Rptr = *rooms;
        while (Rptr){
           if (ft_strcmp(Rptr->name,links->name) == 0)
               break ;
           Rptr = Rptr->next;
        }
        printf("rptr: %s ",Rptr->name);
        ft_putnbr(Rptr->dist);
        if (Rptr->dist == -1 || Rptr->dist == 0){
            Rptr->dist = dist;
            printf("\nset: %s - dist: %d\n",Rptr->name, dist);
            ret = setDist(Rptr->links, paths, rooms, dist + 1, staend);
            if (ret == 3)
                return (3);
        }
        links = links->next;
    }
    return (0);
}

int   getPath(t_room *links, t_staend **staend, t_room **rooms, t_paths **paths, int next, char *start){
    
    t_room *rptr;
    while (links){
        printf("link: %s\n",links->name);
        if (ft_strcmp(links->name,start) != 0){
        // if (ft_strcmp((*staend)->end->name,links->name)){
        //     addRoomToPath(paths, links->name);
        //     addRoomToPath(paths,(*staend)->end->name);
        //     return (1);
        // }
        rptr = *rooms;
        while (rptr){
            if (ft_strcmp(rptr->name,links->name) == 0)
                break;
            rptr = rptr->next;
        }
        printf("rptr: %s\n",rptr->name);
        if (rptr->dist == next && next != 1){
            addRoomToPath(paths, links->name);
            printf("added: %s\n",links->name);
            getPath(rptr->links,staend,rooms,paths, next - 1, start);
        }
        }
        links = links->next;
    }
    printf("sdist: %d",rptr->dist);
    return (1);

    // if (start){}
    // while(links){
    //     printf("link: %s\n",links->name);
    //     printf("next: %d",next);
    //     if (ft_strcmp(links->name,start) != 0){
    //         if (ft_strcmp(links->name,(*staend)->end->name) == 0){
    //             return (1);
    //         }
    //         rptr = *rooms;
    //         while (rptr){
    //             if (ft_strcmp(rptr->name,links->name) == 0)
    //                 break ;
    //             rptr = rptr->next;
    //         }
    //         printf("rptr: %s - dist: %d\n",rptr->name, rptr->dist);
    //         if (rptr->dist == next){
    //             addRoomToPath(paths, links->name);
    //             next--;
    //             links = rptr->links;
    //             printf("set new links\n");
    //         }
    //     }
    //     links = links->next;
    // }

    return (0);
}
////////////////////NEW////////////////
// void  queue_add(t_room **queue, t_room **rooms, char *find, int set){
//     t_room *ptr;
//     ptr = *rooms;

//     while(ptr){
//         if (ft_strcmp(ptr->name,find) == 0)
//             break ;
//         ptr = ptr->next;
//     }
//     t_room *qptr;
//     qptr = *queue;
//     while (qptr){
//         qptr = qptr->next;
//     }
//     qptr->next = ptr->links;
// }


    // (*staend)->end->dist = 0;
    // sptr = (*staend)->end;
    // links = sptr->links;
    // while (links){
    //     queue_add(queue,links->name,dist)
    //     links = links->next;
    // }
    // while (queue){
    //     if (checkIfStart(staend,queue->name,dist)){
    //         break ;
    //     }
    //     queue_add(queue, rooms, links->name, dist)
    //     queue_clean(queue,dist);
    //     queue = queue->next;
    // }
    //////////////////NEW////////////////

int addLinks(t_room **rooms, char *find, char *add, t_room *links){
    t_room *ptr;
    int found = 0;

    ptr = *rooms;
    while(ptr){
        if (ft_strcmp(ptr->name, find) == 0){
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (!found){
        return (0);
    }
    t_room *ptrAdd;

    if (!links){
        ptrAdd = malloc(sizeof(t_room));
        ptrAdd->name = ptr->links->name;
        links = ptrAdd;
        ptr = ptr->next;
        while (ptr->links){
            
        }
    }
    else{
        ptrAdd = malloc(sizeof(t_room));
        ptrAdd->name = add;
        ptrAdd->next = ptr->links;
        ptr->links = ptrAdd;
    }
    //add free links func
    return (1);
}

int   checkRoomDist(char *isSet, t_room **rooms){
    t_room *ptr;
    ft_putstr("CRD: ");
    ft_putstr(isSet);
    ft_putstr("\n");
    ptr = *rooms;
    while(ptr){
        if (ft_strcmp(isSet,ptr->name) == 0)
        break ;
        ptr = ptr->next;
    }
    ft_putstr(ptr->name);
    if (ptr->dist < 0){
        return (0);
    }
    return (1);
}

void    setRoomDist(char *set, t_room **rooms, int dist){
    t_room *ptr;

    ptr = *rooms;
    while(ptr){
        if (set && ptr->name){
            if (ft_strcmp(set,ptr->name) == 0)
              break ;
        }
        ptr = ptr->next;
    }
    ptr->dist = dist;
    printf("set:%s to %d\n",ptr->name,dist);
}

t_room*    getRoomLinks(t_room *getlinks, char *find, t_room **rooms){
    t_room *ptr;
    t_room *ptr2;
    ptr2 = malloc(sizeof(getlinks));
    //ptr2 = getlinks;

    ptr = *rooms;
    while(ptr->next){
        if (ft_strcmp(find,ptr->name) == 0)
            break ;
        ptr = ptr->next;
    }
        printf("F:%s, R:%s ",find,ptr->name);
    printf("\nadded %s's links to getLinks\n",ptr->name);
    if (!getlinks){
        ptr2 = ptr->links;
        printf("p: %s", ptr->links->name);
        return (ptr2);
    }
    ptr2 = getlinks;
        ft_putstr("printing\n");
    while (ptr2->next){
        ft_putstr(ptr2->name);
        ft_putstr(" ");
        ptr2 = ptr2->next;
    }
        ptr2->next = ptr->links;
    printf("p2: %s", ptr2->name);
    return (ptr2);
    // if (!ptr2){
    //     ptr2 = ptr->links;
    //     printf("\ntest: %s\n",ptr2->name);
    // }else
    // {
    //     while(ptr2)
    //         ptr2 = ptr2->next;
    //     ptr2 = ptr->links;
    // }
    // return(ptr2);
    //printf("getLinks: %s\n",getlinks->name);
}

int   pathing(t_staend **staend, t_room **rooms, t_paths **paths){
    t_room *sptr;
    //t_room *rptr;
   // t_room *rptr;
    //t_room *print;
     if (paths){}
 
    t_room *setDist;
    t_room *links;
    t_room *getLinks = (t_room*)malloc(sizeof(t_room));
    getLinks = NULL;
    int dist = 1;

    (*staend)->start->dist = -1;
    (*staend)->end->dist = 0;
    sptr = (*staend)->end;
    setDist = (*staend)->end->links;
    links = NULL;
    if (setDist || links||getLinks){}
    printf("setDist: %s, %s\n",(*staend)->end->name,(*staend)->end->links->name);
     while (links || setDist){
         if (setDist){
         if (ft_strcmp(setDist->name,(*staend)->start->name) == 0){
             (*staend)->start->dist = dist;
             break;
         }
        //ft_putstr(setDist->name);
            setRoomDist(setDist->name,rooms,dist);
            getLinks = getRoomLinks(getLinks,setDist->name,rooms);
            if (!setDist->next){
                 dist++;                                 ///check if start is connected to end
                links = getLinks;
                getLinks = NULL;
                //printf("links: %s",getLinks->name);
             }
            setDist = setDist->next;
        }else if (links){
            ft_putstr("in\n");
                printf("L:%s, S:%s\n",(*staend)->start->name,links->name);
            if (checkIfStart(staend,links->name,dist)){
                break ;
            }
            if (!checkRoomDist(links->name,rooms)){
                setRoomDist(links->name,rooms,dist);
                getLinks = getRoomLinks(getLinks,links->name,rooms);
                if (!links->next){
                    dist++;
                    links = getLinks;
                    getLinks = NULL;
                }
                else
                    links = links->next;
            }else if (!links->next){
                dist++;
                 links = getLinks;
                getLinks = NULL;
            }
            else
                 links = links->next;
        }
    }
    printf("\nsuccess\n");
    printf("\n%s - dist: %d\n",(*staend)->start->name,(*staend)->start->dist);
///////////////////////
    // if (setDist(sptr->links, paths, rooms, 1, staend) == 3){
    //     printf("Found path\n");
    // }else{
    //     printf("No End Found\n");
    //     return (1);
    // }

    sptr = (*staend)->start;
    while (sptr){
        if (sptr->dist > 0)
            break ;
        sptr = sptr->next;
    }
    ////////////
       t_room *pptr;
    int i;
    pptr = *rooms;
    if (pptr){
    while (pptr){
        if (pptr->links){
        ft_putstr("len: ");
        ft_putnbr(pptr->len);
        ft_putstr(" - room: ");
        ft_putstr(pptr->name);
        ft_putstr(" - dist: ");
        ft_putnbr(pptr->dist);
        ft_putstr(" Links: ");
        i = 0;
            while(i < pptr->len){
                ft_putstr(pptr->links->name);
                ft_putstr(" ");
                i++;
                pptr->links = pptr->links->next;
           }
           printf("\n");
        }
        pptr = pptr->next;
    }
   }
   ///////////////////////
    // if (getPath(sptr->links, staend,rooms,paths, sptr->dist - 1, sptr->name)){
    //     printf("Path added");
    //     addRoomToPath(paths,(*staend)->end->name);
    // }
    // else{
    //     printf("Path not found");
    //     return (0);
    //}
    // print = (*paths)->path;
    // printf("\nPath: ");
    // while (print){
    //     printf("%s ", print->name);
    //     print = print->next;
    // }
    // printf("\n");
    return (0);
}