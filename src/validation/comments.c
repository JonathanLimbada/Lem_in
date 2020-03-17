#include "../../lem_in.h"

int isComment(char *str)
{
    if(str[0] == '#' && str[1] != '#')
        return (1);
    return (0);
}

int isCommand(char *str)
{
    if(str[0] == '#' && str[1] == '#')
        return (1);
    return (0);
}