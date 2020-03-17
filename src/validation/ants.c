#include "../../lem_in.h"

int isNum(char* str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int isAnt(char* str)
{
    if (isNum(str))
        return (1);
    return (0);
}

