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

int isAnt(char* str, t_staend *staend)
{
    if (isNum(str))
    {   
        staend->sAnts = ft_atoi(str);
        return (1);
    }
    return (0);
}

