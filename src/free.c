#include "../lem_in.h"

void    freeroom(char **str)
{
    free(str[0]);
    free(str[1]);
    free(str[2]);
    free(str);
}

void    freelink(char **str)
{
    free(str[0]);
    free(str[1]);
    free(str);
}

void    freemain(char *file, t_valid *vals)
{
    free(file);
    free(vals);
}