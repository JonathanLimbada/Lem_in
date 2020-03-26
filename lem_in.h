#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> //remove

# define NO_ANTS    {ft_putendl("Error: No ants found."); free(vals); return(1);}
# define NUMROOMS   {ft_putendl("Error: Not enough rooms."); free(vals); return(1);}
# define NO_START   {ft_putendl("Error: No start command."); free(vals); return(1);}
# define NUMLINKS   {ft_putendl("Error: Too few links."); free(vals); return(1);}
# define NO_END     {ft_putendl("Error: No end command."); free(vals); return(1);}


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

typedef struct          s_val
{
    int     room;
    int     link;
    int     start;
    int     end;
    int     ants;
    int     e;
    int     a;
}                       t_valid;


//validation functions

int     isLink(char* str);
int     strchrnum(const char *s, char c);
int     isStart(char* str);
int     isRoom(char* str);
int     isEnd(char* str);
int     isComment(char *str);
int     isCommand(char *str);
int     isAnt(char* str);
int     isNum(char* str);
int     isValidType(char *str);
void    init_vals(t_valid *vals);
void    freeroom(char **str);
void    freelink(char **str);
void    freemain(char *file, t_valid *vals);


#endif