#include "../lem_in.h"

//validate file

int     isValidType(char *str)
{
    if(isAnt(str))
        return (1);
    if(isRoom(str))
        return (1);
    if(isCommand(str))
        return (1);
    if(isComment(str))
        return (1);
    if(isEnd(str))
        return(1);
    if(isLink(str))
        return(1);
    if(isStart(str))
        return(1);
    return(0);
}

//validate rooms and links
//validate paths