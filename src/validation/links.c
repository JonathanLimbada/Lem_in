#include "../../lem_in.h"

int strchrnum(const char *s, int c)
{
	int i;
    int r;

    r = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
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
    if (!ft_strequ(link[1], "-"))
        return (0);
    if (!link[0] || link[0][0] == 'L' || link[0][0] == '#')
        return (0);
    if (!link[2] || link[2][0] == 'L' || link[2][0] == '#')
        return (0);
    return (1);
}