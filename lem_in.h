#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> //remove

typedef struct          s_room
{
    char *              name;
    char *              ant_num;
    struct s_room *     next;
}                      t_room;

typedef struct          s_paths
{
    struct s_room *     path;
    int                 plen;
    struct s_paths *    next;
}                       t_paths;


//validation functions

int     isLink(char* str);
char	*ft_strchrnum(const char *s, int c);
int     isStart(char* str);
int     isRoom(char* str);
int     isEnd(char* str);
int     isComment(char *str);
int     isCommand(char *str);
int     isAnt(char* str);


#endif