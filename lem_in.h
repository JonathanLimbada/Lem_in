#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <get_next_line.h>

typedef struct          s_room
{
    char *              name;
    char *              ant_num;
    struct s_room *     next;
}                       t_room;

typedef struct          s_paths
{
    struct s_room *     path;
    int                 plen;
    struct s_paths *    next;
}

#endif



/*
15 ants
-------
*l1-1 *l2-2 *l3-5
*l1-3 *l3-4 l4-1 *l5-5
*l1-4 *l2-3 *l5-4 l4-2 l6-1 l7-5
*l2-4 *l4-3
*l4-4

*/