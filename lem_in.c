#include "lem_in.h"

void    multStart_set(t_staend **staend, char **tmp, char *file)
{
    t_room    *ptr;

    ptr = malloc(sizeof(t_room));
    tmp = ft_strsplit(file, ' ');

    ptr->name = tmp[0];
    ptr->x = ft_atoi(tmp[1]);
    ptr->y = ft_atoi(tmp[2]);

    ptr->next = (*staend)->start;
    (*staend)->start = ptr;
}

void    rooms_set(t_room **rooms, char **tmp, char *file)
{
    t_room    *ptr;

    ptr = malloc(sizeof(t_room));
    tmp = ft_strsplit(file, ' ');

    ptr->name = tmp[0];
    ptr->x = ft_atoi(tmp[1]);
    ptr->y = ft_atoi(tmp[2]);

    ptr->next = *rooms;
    *rooms = ptr;
}

int main (void)
{
    char	    *file;
    t_valid     *vals;
    t_staend    *staend;
    t_paths     *paths;
    t_room      *rooms;
    char        **tmp;
    t_room      *ptr;
    t_room      *sptr;

    vals = (t_valid *)malloc(sizeof(t_valid));
    //start & end info 
    staend = (t_staend *)malloc(sizeof(t_staend));
    //all valid paths
    paths = (t_paths *)malloc(sizeof(t_paths));
    //all rooms to map paths
    rooms = (t_room *)malloc(sizeof(t_room));
    rooms->next = NULL;

    init_vals(vals);
	while (get_next_line(0, &file) != 0)
    {
        if (!isValidType(file, staend))
        {
            ft_putendl("oof");
            freemain(file, vals);
            return (0);
        }
        if (vals->start == 1 && vals->e == 0)
        {
            if (!isRoom(file))
            {
                ft_putendl("Error: start bad");
                freemain(file, vals);
                return (0);
            }
            //get first starting room info
            tmp = ft_strsplit(file, ' ');
            staend->start = (t_room *)malloc(sizeof(t_room));
            staend->start->name = tmp[0];
            staend->start->x = ft_atoi(tmp[1]);
            staend->start->y = ft_atoi(tmp[2]);
            staend->start->next = NULL;
            //staend->start->next = NULL;
            vals->e = 1;
        }
        //multi start
        if (vals->e == 1)
        {
            if (isRoom(file))
               multStart_set(&staend, tmp,file);
            else
                vals->e = 2;
        }
        if (isRoom(file) && vals->e == 2)
        {
            tmp = ft_strsplit(file, ' ');
            rooms->name = tmp[0];
            rooms->x = ft_atoi(tmp[1]);
            rooms->y = ft_atoi(tmp[2]);
            rooms->next = NULL;
            vals->e = 3;
        }
        else if (isRoom(file) && vals->e == 3 && vals->end != 1)
        {
            rooms_set(&rooms, tmp, file);
        }
        if (vals->end == 1 && vals->a == 0)
        {
            if (!isRoom(file))
            {
                ft_putendl("Error: end bad");
                freemain(file, vals);
                return (0);
            }
            tmp = ft_strsplit(file, ' ');
            staend->end = (t_room *)malloc(sizeof(t_room));
            staend->end->name = tmp[0];
            staend->end->x = ft_atoi(tmp[1]);
            staend->end->y = ft_atoi(tmp[2]);
            vals->a = 1;
        }
        checkFile(file,vals,staend,paths);
        free(file);
    }
    printf("Ants: %d\n",staend->sAnts);
    sptr = staend->start;
    while(sptr->next)
    {
        printf("Start name: %s  x: %d y: %d\n",sptr->name,sptr->x,sptr->y);
        sptr = sptr->next;
    }
    // printf("Start name: %s\tx: %d y: %d\n",staend->start->next->name,staend->start->next->x,staend->start->next->y);ft_putchar('\n');
    printf("End name: %s\tx: %d y: %d\n",staend->end->name,staend->end->x,staend->end->y);
    // printf("%s\t%d %d", rooms->name, rooms->x, rooms->y);
    //printf("%s\t%d %d", rooms->next->name, rooms->next->x, rooms->next->y);
    ptr = rooms;
    while(ptr)
    {
        printf("Room Name: %s\tx: %d y:%d\n", ptr->name, ptr->x, ptr->y);
        //ft_putstr(ptr->name);
        ptr = ptr->next;
    }
    return (0);
    //return (checkFileData(vals));
}

void    checkFile(char *file, t_valid *vals, t_staend *staend, t_paths *paths)
{
    paths = (t_paths*)malloc(sizeof(t_paths));
    free(paths);
    if (isRoom(file))
        vals->room++;
    if (isLink(file))
        vals->link++;
    if (isAnt(file, staend))
        vals->ants++;
    if (isRoom(file))
        vals->room++;
    if (isStart(file))
        vals->start++;
    if (isEnd(file))
        vals->end++;
}

int checkFileData(t_valid *vals)
{
    if (vals->ants != 1)
        NO_ANTS;
    if (vals->room <= 2)
        NUMROOMS;
    if (vals->start != 1)
        NO_START;
    if (vals->end != 1)
        NO_END; 
    if (vals->link < 1)
        NUMLINKS;
    ft_putendl("all good");
    free(vals);
    return (0);
}