#include "../lem_in.h"

int     isValidType(char *str)
{
    if(isAnt(str))
        return (1);
    if(isCommand(str))
        return (1);
    if(isComment(str))
        return (1);
    if(isEnd(str))
        return(1);
    if(isLink(str))
        return(1);
    if(isRoom(str))
        return(1);
    if(isStart(str))
        return(1);
    return(0);
}

//validate file
//validate paths
//validate rooms and links