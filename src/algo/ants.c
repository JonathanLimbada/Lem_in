#include "../../lem_in.h"

void    printMove(char *name, int ant){
    ft_putchar('L');
    ft_putnbr(ant);
    ft_putchar('-');
    ft_putstr(name);
    ft_putchar(' ');
}

int moveAnt(t_paths **paths, t_staend **staend, int ant){
    if (staend){}
    t_room *prev;
    t_room *prev1 = NULL;
    t_room *ptr;
    t_room *ptr1;

    t_room *done = (*paths)->path;
    while (done){
        if (ft_strcmp((*staend)->end->name,done->next->name) == 0){
            break ;
        }
        done = done->next;
    }
    prev = (*paths)->path;
        while (prev->next){
            prev = prev->next;
        }
    prev1 = prev;
    ptr = (*paths)->path;
    while (ptr){
        ptr1 = (*paths)->path;
        while (ptr1){
            if (ft_strcmp(ptr1->name,prev->name) == 0){
                break;
            }
            if (ft_strcmp(ptr1->next->name,prev->name) == 0){
                break;
            }
            ptr1 = ptr1->next;
        }
        if (ft_strcmp(ptr1->next->name,(*staend)->end->name) == 0){
            if (ptr1->filled != 0){
                printMove(ptr1->next->name,ptr1->filled);
                if (ptr1->filled == (*staend)->sAnts){
                    return (0);
                }
                ptr1->filled = 0;
            }
        }
        else if (ft_strcmp(ptr1->next->name,prev->name) == 0){
            if (ptr1->filled != 0){
                printMove(ptr1->next->name,ptr1->filled);
                ptr1->next->filled = ptr1->filled;
                ptr1->filled = 0;
            }
            prev = ptr1;
        }
        else if (ft_strcmp(prev->name,(*paths)->path->name) == 0 && (*paths)->path->filled == 0 && (*paths)->done != 1){
            (*paths)->path->filled = ant++;
            printMove((*paths)->path->name,(*paths)->path->filled);
            prev = prev1;
            if (ant == (*staend)->sAnts + 1){
                (*paths)->done = 1;
            }
        }
        else if (ft_strcmp(prev->name,(*paths)->path->name) == 0){
            if (prev->filled != 0){
            prev->next->filled = prev->filled;
            printMove(prev->next->name,prev->next->filled);
            prev->filled = 0;
            }
            prev = prev1;
        }
        prev = ptr1;
        ptr = ptr->next;
    }
    return (ant);
}

void    antMovements(t_paths **path, t_staend **staend){
    int ret = 1;
    int ant = 1;
    while (ret != 0){
        ret = moveAnt(path, staend, ant);
        if (ant != (*staend)->sAnts)
            ant++;
        ft_putstr("\n");
    }
}

void    spAntMovements(t_paths **path, t_staend **staend){
    int ant = 1;
    while (ant != (*staend)->sAnts + 1){
        printMove((*path)->path->name,ant);
        ft_putchar('\n');
        ant++;
    }
}