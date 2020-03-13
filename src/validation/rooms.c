#include <lem_in.h>

int isRoom(char* str)
{
    char    **room;

    if (strchrnum(str, ' ') != 2)
        return (0);
    room = ft_strsplit(str, " ");
    if (!room[0] || room[0][0] == 'L' || room[0][0] == '#')
        return (0);
    if (!ft_isdigit(room[1]))
        return (0);
    if (!ft_isdigit(room[2]))
        return (0);
    return (1);
}