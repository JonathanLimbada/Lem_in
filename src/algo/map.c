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
        ptr->links = ptrAdd;
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

int addStartLink(t_staend **staend, char *find, char *add){
    t_room *ptr;
    int found = 0;

    ptr = (*staend)->start;
    while(ptr){
        if (ft_strcmp(ptr->name, find) == 0){
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (found){
        t_room *ptrAdd;

        if (!ptr->links){
            ptrAdd = malloc(sizeof(t_room));
            ptrAdd->name = add;
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

// ORGANISE LINKS FROM START TO END EN SPECIFY IF IT IS A ALT PATH
int mapLinks(t_staend **staend, t_room **rooms, t_links **links)
{
    t_links *lptr;
    t_room *sptr;

    lptr = *links;
    while(lptr){
        int isStart = 0;
        sptr = (*staend)->start;
        while(sptr->next){
            if (ft_strcmp(sptr->name, lptr->first) == 0){
                addStartLink(staend, lptr->first, lptr->second);
                isStart++;
            }else if (ft_strcmp(sptr->name, lptr->second) == 0){
                addStartLink(staend, lptr->second, lptr->first);
                isStart++;
            }
            sptr = sptr->next;
        }
        if (!isStart){
            if (ft_strcmp((*staend)->end->name, lptr->first) == 0 || ft_strcmp((*staend)->end->name, lptr->second) == 0){
                if (ft_strcmp((*staend)->end->name, lptr->first) == 0){
                    addLink(rooms,lptr->second,lptr->first);
                }
                else{
                    addLink(rooms,lptr->first,lptr->second);
                }
            }
            else{
                addLink(rooms,lptr->first,lptr->second);
                addLink(rooms,lptr->second,lptr->first);
            }}
        lptr = lptr->next;
    }

    //t_room *sptr;
    sptr = (*staend)->start;

    while (sptr->next){
        printf("Start room: %s Links: ", sptr->name);
        if (sptr->links){
            while(sptr->links){
                printf("%s ", sptr->links->name);
                sptr->links = sptr->links->next;
           }
           printf("\n");
        }
        printf("\n");
        sptr = sptr->next;
    }

    t_room *pptr;
    int i = 0;
    pptr = *rooms;
    while (pptr){
        printf("room: %s Links: ", pptr->name);
        if (pptr->links){
            while(pptr->links){
                printf("%s ", pptr->links->name);
                i++;
                pptr->links = pptr->links->next;
           }
           printf("\n");
        }
        pptr = pptr->next;
    }
    return (0);
}