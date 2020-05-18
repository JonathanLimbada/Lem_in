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

// void	free_links(t_links **link)
// {
// 	t_links *next;

// 	next = *link;
// 	while (*link)
// 	{
// 		next = (*link)->next;
// 		free((*link)->first);
// 		free(*link);
// 		(*link) = next;
// 	}
// 	*link = NULL;
// }

int		popcomments(t_comments **head)
{
	t_comments		*next_node;

	next_node = NULL;
	if (head == NULL)
		return (-1);
	next_node = (*head)->next;
    free((*head)->command);
	free(head);
	*head = next_node;
    return (0);
}

void     freecommands(t_comments **comments){
    while(*comments){
        popcomments(comments);
    }
}

int		poplinks(t_links **head)
{
	t_links		*next_node;

	next_node = NULL;
	if (*head == NULL)
		return (-1);
	next_node = (*head)->next;
    free((*head)->first);
    free((*head)->second);
	free(*head);
	*head = next_node;
    return (0);
}


void     freelinks(t_links **links){
    while(*links){
        poplinks(links);
    }
}

int		poplink(t_room *head)
{
	t_room		*next_node;

	next_node = NULL;
	if (head == NULL)
		return (-1);
	next_node = head->next;
	free(head);
	head = next_node;
    return (0);
}

int		pop(t_room **head)
{
	t_room		*next_node;

	next_node = NULL;
	if (*head == NULL)
		return (-1);
    // while ((*head)->links){
    //     poplink((*head)->links);
    // }
	next_node = (*head)->next;
    free((*head)->name);
	free(*head);
	*head = next_node;
    return (0);
}

void    freerooms(t_room **rooms)
{
    //t_room *next;

	//next = *rooms;
    while(*rooms)
    {
        pop(rooms);
        // free_links(&((*rooms)->links));
        // free((*rooms)->filled);
        // //free((*rooms)->x);
        // //free((*rooms)->y);
        // //free((*rooms)->len);
        // //free((*rooms)->dist);
        // //free((*rooms)->visited);
        // next = (*rooms)->next;
		// (*rooms) = next;
    }
    *rooms = NULL;
}