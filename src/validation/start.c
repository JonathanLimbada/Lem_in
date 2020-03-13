#include <lem_in.h>

int isStart(char* str)
{
    if(strequ(str, "##start"))
        return (1);
    return (0);
}