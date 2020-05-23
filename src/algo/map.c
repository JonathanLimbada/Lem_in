#include "../../lem_in.h"

int addLink(t_room **rooms, char *find, char *add){
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

    if (!ptr->links){
        ptrAdd = malloc(sizeof(t_room));
        ptrAdd->name = add;
        ptrAdd->next = NULL;
        ptr->links = ptrAdd;
        ptr->len++;
    }
    else{
        ptrAdd = malloc(sizeof(t_room));
        ptrAdd->name = add;
        ptrAdd->next = ptr->links;
        ptr->links = ptrAdd;
        ptr->len++;
    }
    //add free links func
    return (1);
}

int addStartLink(t_staend **staend, char *find, char *add){
    t_room *ptr;
    if (find){}
    ptr = (*staend)->start;
        t_room *ptrAdd;

        if (!ptr->links){
            ptrAdd = malloc(sizeof(t_room));
            ptrAdd->name = add;
            ptrAdd->next = NULL;
            ptr->links = ptrAdd;
        }
        else{
            ptrAdd = malloc(sizeof(t_room));
            ptrAdd->name = add;
            ptrAdd->next = ptr->links;
            ptr->links = ptrAdd;
        }
    return (1);

}

int addEndLink(t_staend **staend, char *add){
    t_room *ptr;

    if (staend && add){
        ptr = (*staend)->end;
        t_room *ptrAdd;

        if (!ptr->links){
            ptrAdd = malloc(sizeof(t_room));
            ptrAdd->name = add;
            ptrAdd->next = NULL;
            ptr->links = ptrAdd;
        }
        else{
            ptrAdd = malloc(sizeof(t_room));
            ptrAdd->name = add;
            ptrAdd->next = ptr->links;
            ptr->links = ptrAdd;
        }
    }
    return (1);
}

void    addEndLinks(t_staend **staend,t_links **links,t_room **rooms){
    t_links *lptr;
    lptr = *links;
    while (lptr){
        if (ft_strcmp((*staend)->end->name, lptr->first) == 0 || ft_strcmp((*staend)->end->name, lptr->second) == 0){
            if (ft_strcmp((*staend)->end->name, lptr->first) == 0){
                addLink(rooms,lptr->second,lptr->first);
            }
            else if (ft_strcmp((*staend)->end->name,lptr->second) == 0){
                addLink(rooms,lptr->first,lptr->second);
            }
        }
        lptr = lptr->next;
    }
}

// ORGANISE LINKS FROM START TO END AND SPECIFY IF IT IS A ALT PATH
int mapLinks(t_staend **staend, t_room **rooms, t_links **links)
{
    t_links *lptr;
    t_room *sptr;

    lptr = *links;
    while(lptr){
        int isStart = 0;
        sptr = (*staend)->start;
        if (ft_strcmp(sptr->name, lptr->first) == 0){
            addStartLink(staend, lptr->first, lptr->second);
            addLink(rooms,lptr->second,lptr->first);
            isStart++;
        }else if (ft_strcmp(sptr->name, lptr->second) == 0){
            addStartLink(staend, lptr->second, lptr->first);
            addLink(rooms,lptr->first,lptr->second);
            isStart++;
        }
        if (!isStart){
            if (ft_strcmp((*staend)->end->name, lptr->first) == 0 || ft_strcmp((*staend)->end->name, lptr->second) == 0){
                if (ft_strcmp((*staend)->end->name, lptr->first) == 0){
                    addEndLink(staend,lptr->second);
                }
                else if (ft_strcmp((*staend)->end->name,lptr->second) == 0){
                    addEndLink(staend,lptr->first);
                }
            }
            else{
                addLink(rooms,lptr->first,lptr->second);
                addLink(rooms,lptr->second,lptr->first);
            }}
        lptr = lptr->next;
    }
    return (0);
}