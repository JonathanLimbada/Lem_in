#include "../../lem_in.h"

void    addRoomToPath(t_paths **paths, char *room){
    t_room *ptr;
    t_room *ptr2;

    ptr2 = (*paths)->path;
    if (!(*paths)->path){
        ptr = malloc(sizeof(t_room));
        ptr->name = room;
        ptr->filled = 0;
        ptr->next = NULL;
        (*paths)->path = ptr;
    }
    else{
        ptr = malloc(sizeof(t_room));
        ptr->name = room;
        ptr->filled = 0;
        ptr->next = NULL;
        while(ptr2->next != NULL){
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr;
    }
}

int checkIfStart(t_staend **staend, char *find, int dist){
    t_room *ptr;
    ptr = (*staend)->start;
    while(ptr){
        if (find){
        if (ft_strcmp(ptr->name, find) == 0){
            ptr->dist = dist;
            return (1);
        }
        }
        ptr = ptr->next;
    }
    return (0);
}

int   getPath(t_room *links,t_staend **staend, t_room **rooms, t_paths **paths, int dist){
    t_room *ptr;
    links = (*staend)->start->links;
    while (links){
        if (ft_strcmp(links->name,(*staend)->start->name) != 0){
            if (dist == 0){
                if (ft_strcmp((*staend)->end->name,links->name) == 0){
                    addRoomToPath(paths, (*staend)->end->name);
                    return (1);
                }else{
                    links = links->next;
                }
            }else{
                if (ft_strcmp((*staend)->end->name,links->name) != 0){
                    ptr = *rooms;
                    while (ptr){
                        if (ft_strcmp(ptr->name,links->name) == 0){
                            break;
                        }
                        ptr = ptr->next;
                    }
                    if (ptr != NULL && ptr->dist == dist){
                        addRoomToPath(paths, ptr->name);
                        dist--;
                        links = ptr->links;
                    }
                }
            }  
        }
        if (dist != 0)
            links = links->next;
    }
    return (1);
}

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
    ptr = *rooms;
    while(ptr){
        if (ft_strcmp(isSet,ptr->name) == 0)
            break ;
        ptr = ptr->next;
    }
    if (ptr){
    if (ptr->dist < 0){
        return (0);
    }}
    return (1);
}

void    setRoomDist(char *set, t_room **rooms, int dist){
    t_room *ptr;

    ptr = *rooms;
    while(ptr){
        if (ft_strcmp(set,ptr->name) == 0)
            break ;
        ptr = ptr->next;
    }
    if (ptr != NULL)
        ptr->dist = dist;
}

t_room*    getRoomLinks(t_room *getlinks, char *find, t_room **rooms){
    t_room *ptr;
    t_room *ptr2;
    ptr2 = malloc(sizeof(getlinks));

    ptr = *rooms;
    while(ptr != NULL){
        if (ft_strcmp(find,ptr->name) == 0)
            break ;
        ptr = ptr->next;
    }
    if (!getlinks && ptr != NULL){
        ptr2 = ptr->links;
        return (ptr2);
    }
    ptr2 = getlinks;
    if (ptr2){
    while (ptr2->next){
        ptr2 = ptr2->next;
    }
    if (ptr2 != NULL && ptr != NULL)
        ptr2->next = ptr->links;
    }
    return (getlinks);
}

int   pathing(t_staend **staend, t_room **rooms, t_paths **paths){
    t_room *sptr;
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
    if (setDist || links || getLinks){}
     while (links || setDist){
         if (setDist){
         if (ft_strcmp(setDist->name,(*staend)->start->name) == 0){
             (*staend)->start->dist = dist;
             break;
         }
            setRoomDist(setDist->name,rooms,dist);
            getLinks = getRoomLinks(getLinks,setDist->name,rooms);
            if (!setDist->next){
                dist++;
                links = getLinks;
                getLinks = NULL;
             }
            setDist = setDist->next;
        }else if (links){
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
    if ((*staend)->start->dist == -1){
        ft_putendl("Error: no path to end");
        exit(1);
    }
    sptr = (*staend)->start;
    while (sptr){
        if (sptr->dist > 0)
            break ;
        sptr = sptr->next;
    }
    return (0);
}