#include "../../lem_in.h"

int isRoom(char* str)
{
    char    **room;

    if (strchrnum(str, ' ') != 2)
        return (0);
    room = ft_strsplit(str, ' ');
    if (!room[0] || room[0][0] == 'L' || room[0][0] == '#')
    {
        freeroom(room);
        return (0);
    }
    if (!isNum(room[1]))
    {
        freeroom(room);
        return (0);
    }
    if (!isNum(room[2]))
    {
        freeroom(room);
        return (0);
    }
    freeroom(room);
    return (1);
}