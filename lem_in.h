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


typedef struct          s_paths
{
    struct s_room *     path;
    int                 len;
    struct s_paths *    next;
    int         done;
}                       t_paths;

typedef struct          s_comments
{
    char*               command;
    struct s_comments*  next;  
}                       t_comments;


typedef struct          s_room
{
    char *              name;
    int                 filled;
    int                 x;
    int                 y;
    int                 len;
    int                 dist;
    int                 visited;
    struct s_room *     links;
    struct s_room *     next;
}                       t_room;


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

typedef struct          s_staend
{
    t_room      *start;
    int         sAnts;
    t_room      *end;
    int         eAnts;
}                       t_staend;

typedef struct          s_links
{
    char            *first;
    char            *second;
    struct s_links  *next;
}                       t_links;


//validation functions

int     isLink(char* str);
int     strchrnum(const char *s, char c);
int     isStart(char* str);
int     isRoom(char* str);
int     isEnd(char* str);
int     isComment(char *str);
int     isCommand(char *str);
int     isAnt(char* str, t_staend *staend);
int     isNum(char* str);
int     isValidType(char *str, t_staend *staend);
void    init_vals(t_valid *vals);
void    freeroom(char **str);
void    freelink(char **str);
void    freemain(char *file, t_valid *vals);
void    checkFile(char *file, t_valid *vals, t_staend *staend, t_paths *paths);
int     checkFileData(t_valid *vals);
void	add_link(t_links **links, char *line);
void    malAdd_link(t_links **links, char *file);
void    print(t_staend *staend, t_room *rooms, t_links *links, t_comments *comments);
int     mapLinks(t_staend **staend, t_room **rooms, t_links **links);
int     pathing(t_staend **staend,t_room **rooms, t_paths **paths);
void    malAdd_comment(t_comments **comment, char *file);
void	add_comment(t_comments **comment, char *line);
void    freerooms(t_room **rooms);
void	free_links(t_links **link);
void    freelinks(t_links **links);
void	free_time(char **argv);
void    freecommands(t_comments **comments);
void    freeall(t_room *rooms,t_staend *staend,t_links *links,t_comments *comment,t_paths *paths, char **tmp);
int     getPath(t_room *links,t_staend **staend, t_room **rooms, t_paths **paths, int dist);
void    addEndLinks(t_staend **staend,t_links **links,t_room **rooms);
int     addLink(t_room **rooms, char *find, char *add);
void    addRoomToPath(t_paths **paths, char *room);
void    antMovements(t_paths **path, t_staend **staend);

#endif