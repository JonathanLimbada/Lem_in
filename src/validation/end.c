#include "../../lem_in.h"

int isEnd(char* str)
{
    if(ft_strequ(str, "##end"))
        return (1);
    return (0);
}