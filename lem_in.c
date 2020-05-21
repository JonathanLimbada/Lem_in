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
    //free_time(tmp);
}

void    rooms_set(t_room **rooms, char **tmp, char *file)
{
    t_room    *ptr;

    ptr = malloc(sizeof(t_room));
    tmp = ft_strsplit(file, ' ');

    ptr->name = tmp[0];
    ptr->x = ft_atoi(tmp[1]);
    ptr->y = ft_atoi(tmp[2]);
    //free_time(tmp);
    ptr->len = 0;
    ptr->dist = -1;
    ptr->links = NULL;

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
    t_links     *links;
    t_comments  *comment;

    int new;
    int newcom;
    new = 0;
    newcom = 0;

    vals = (t_valid *)malloc(sizeof(t_valid));
    //start & end info 
    staend = (t_staend *)malloc(sizeof(t_staend));
    //all valid paths
    paths = (t_paths *)malloc(sizeof(t_paths));
    //all rooms to map paths
    rooms = (t_room *)malloc(sizeof(t_room));
    rooms->next = NULL;
    comment = (t_comments *)malloc(sizeof(t_comments));

    links = (t_links *)malloc(sizeof(t_links));

    init_vals(vals);
	while (get_next_line(0, &file) != 0)
    {
        if (!isValidType(file, staend))
        {
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
            staend->start->links = NULL;
            vals->e = 2;
            //freeroom(tmp);
        }
        else if (isRoom(file) && vals->e == 2)
        {
            tmp = ft_strsplit(file, ' ');
            rooms->name = tmp[0];
            rooms->x = ft_atoi(tmp[1]);
            rooms->y = ft_atoi(tmp[2]);
            rooms->dist = -1;
            rooms->next = NULL;
            rooms->links = NULL;
            vals->e = 3;
            //freeroom(tmp);
        } 
        else if (vals->end == 1 && vals->a == 0)
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
            staend->end->next = NULL;
            vals->a = 1;
            //freelink(tmp);
        }
        else if (isRoom(file) && vals->e == 2)
        {
            tmp = ft_strsplit(file, ' ');
            rooms->name = tmp[0];
            rooms->x = ft_atoi(tmp[1]);
            rooms->y = ft_atoi(tmp[2]);
            rooms->dist = -1;
            rooms->next = NULL;
            rooms->links = NULL;
            vals->e = 3;
            //freeroom(tmp);
        }
        else if (isRoom(file) && (vals->e == 3 || vals->e == 0))
        {
            rooms_set(&rooms, tmp, file);
        }
        if (isLink(file))
        {
            if (new == 0){
                add_link(&links, file);
                new = 1;
            }else
                malAdd_link(&links, file);
        }
        if (isCommand(file) || isComment(file))
        {
            if (newcom == 0){
                add_comment(&comment, file);
                newcom = 1;
            }else
                malAdd_comment(&comment, file);
        }
        checkFile(file,vals,staend,paths);
        free(file);
    }
    //check for duplicate links before adding them to the list!!!!!
    if (checkFileData(vals)){
        //freeall(rooms,staend,links,comment,paths,tmp);
        exit(1);
    }
    mapLinks(&staend,&rooms,&links);
    t_room *sptr;
    int x;
    if (!staend->start->links){
        sptr = staend->end->links;
        x = 0;
    }
    else{
        sptr = staend->start->links;
        x = 1;
    }
    while (sptr){
        if (x == 0){
            if (ft_strcmp(sptr->name,staend->start->name) == 0){
                addRoomToPath(&paths, staend->end->name);
                x = 3;
                break;
            }
            sptr = sptr->next;
        }else{
            if (ft_strcmp(sptr->name,staend->end->name) == 0){
                addRoomToPath(&paths, staend->end->name);
                x = 3;
                break;
            }
            sptr = sptr->next;
        }
    }
    if (x != 3){
        pathing(&staend,&rooms,&paths);
    //printf("slink: %s\n", staend->start->links->name);
        addEndLinks(&staend,&links,&rooms);
        getPath(staend->start->links,&staend,&rooms,&paths,staend->start->dist - 1);
    }
    //print(staend,rooms,links, comment);
    t_room *print;
    print = paths->path;
    printf("Path: ");
    while (print){
        printf("%s ", print->name);
        print = print->next;
    }
    printf("\n");
    //freeall(rooms,staend,links,comment,paths,tmp);
    return (0);
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
    free(vals);
    return (0);
}

void    freeall(t_room *rooms,t_staend *staend,t_links *links,t_comments *comment,t_paths *paths, char **tmp){
    
    if (rooms){
        freerooms(&rooms);
    }
    if (staend->start){
        freerooms(&staend->start);
    }
    if (staend->end){
        freerooms(&staend->end);
    }
    if (staend){
        free(staend);
    }
    if (links){
        freelinks(&links);
    }
    if (comment){
        freecommands(&comment);
    }
    if (paths){
        free(paths);
    }
     if (tmp){
         freeroom(tmp);
     }
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