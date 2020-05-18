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

void	free_links(t_links **link)
{
	t_links *next;

	next = *link;
	while (*link)
	{
		next = (*link)->next;
		free((*link)->first);
		free(*link);
		(*link) = next;
	}
	*link = NULL;
}

void    freerooms(t_room **rooms)
{
    t_room *next;

	next = *rooms;
    while(*rooms)
    {
        free_links(&((*rooms)->links));
        free((*rooms)->filled);
        free((*rooms)->x);
        free((*rooms)->y);
        free((*rooms)->len);
        free((*rooms)->dist);
        free((*rooms)->visited);
        next = (*rooms)->next;
		(*rooms) = next;
    }
    *rooms = NULL;
}