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
    if (!link[0] || link[0][0] == 'L' || link[0][0] == '#')
        return (0);
    if (!link[1] || link[1][0] == 'L' || link[1][0] == '#')
        return (0);
    return (1);
}