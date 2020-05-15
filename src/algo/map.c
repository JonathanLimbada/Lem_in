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
    int found = 0;
    if (staend && find && add){
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
    }}
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

// ORGANISE LINKS FROM START TO END AND SPECIFY IF IT IS A ALT PATH
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
                addLink(rooms,lptr->first,lptr->second);
                isStart++;
            }else if (ft_strcmp(sptr->name, lptr->second) == 0){
                addStartLink(staend, lptr->second, lptr->first);
                addLink(rooms,lptr->second,lptr->first);
                isStart++;
            }
            sptr = sptr->next;
        }
        if (!isStart){
            if (ft_strcmp((*staend)->end->name, lptr->first) == 0 || ft_strcmp((*staend)->end->name, lptr->second) == 0){
                if (ft_strcmp((*staend)->end->name, lptr->first) == 0){
                    addLink(rooms,lptr->second,lptr->first);
                    addEndLink(staend,lptr->second);
                }
                else{
                    addLink(rooms,lptr->first,lptr->second);
                    addEndLink(staend,lptr->first);
                }
            }
            else{
                addLink(rooms,lptr->first,lptr->second);
                addLink(rooms,lptr->second,lptr->first);
            }}
        lptr = lptr->next;
    }

    // sptr = (*staend)->start;

    // while (sptr->next){
    //     printf("Start room: %s Links: ", sptr->name);
    //     if (sptr->links){
    //         while(sptr->links){
    //             printf("%s ", sptr->links->name);
    //             sptr->links = sptr->links->next;
    //        }
    //        printf("\n");
    //     }
    //     printf("\n");
    //     sptr = sptr->next;
    // }

    t_room *eptr = (*staend)->end;

        printf("end room: %s Links: ", eptr->name);
        if (eptr->links){
            while(eptr->links){
                printf("%s ", eptr->links->name);
                eptr->links = eptr->links->next;
           }
           printf("\n");
        }
        printf("\n");

//    t_room *pptr;
//     int i;
//     pptr = *rooms;
//     if (pptr){
//     while (pptr){
//         if (pptr->links){
//         ft_putstr("len: ");
//         ft_putnbr(pptr->len);
//         ft_putstr("\nroom: ");
//         ft_putstr(pptr->name);
//         ft_putstr(" Links: ");
//         i = 0;
//             while(i < pptr->len){
//                 ft_putstr(pptr->links->name);
//                 ft_putstr(" ");
//                 i++;
//                 pptr->links = pptr->links->next;
//            }
//            printf("\n");
//         }
//         pptr = pptr->next;
//     }
//    }
    return (0);
}