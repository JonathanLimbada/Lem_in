#include "../../lem_in.h"

int strchrnum(const char *s, char c)
{
	int i;
    int r;

    r = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
            r++;
		i++;
	}
    return (r);
}

int isLink(char* str)
{
    char    **link;

    if (strchrnum(str, '-') != 1)
        return (0);
    link = ft_strsplit(str, '-');
    if (!link[0] || link[0][0] == 'L')
    {
        ft_putendl("Error: bad link format");
        freelink(link);
        exit(0);
    }
    if (!link[1] || link[1][0] == 'L' || link[1][0] == '#')
    {
        ft_putendl("Error: bad link format");
        freelink(link);
        exit(0);
    }
    freelink(link);
    return (1);
}

void		add_link(t_links **links, char *line)
{
	char	**split;

	split = ft_strsplit(line, '-');
	(*links)->first = split[0];
	(*links)->second = split[1];
    (*links)->next = NULL;
	free(split);
}

void    malAdd_link(t_links **links, char *file)
{
    t_links    *ptr;
    char        **tmp;

    ptr = malloc(sizeof(t_links));
    tmp = ft_strsplit(file, '-');

    ptr->first = tmp[0];
    ptr->second = tmp[1];
    free(tmp);

    ptr->next = *links;
    *links = ptr;
}

void		add_comment(t_comments **comment, char *line)
{
    char    *str;
    str = ft_strdup(line);

	(*comment)->command = str;
    (*comment)->next = NULL;
}

void    malAdd_comment(t_comments **comment, char *file)
{
    t_comments  *ptr;
    char*       str;   

    ptr = malloc(sizeof(t_comments));
    str = ft_strdup(file);

    ptr->command = str;

    ptr->next = *comment;
    *comment = ptr;
}