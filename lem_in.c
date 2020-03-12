#include "lem_in.h"

int main (void)
{
    char	*file;
	while (get_next_line(0, &file) != 0)
    {
        ft_putstr(file);
        ft_putchar('\n');
    }
    
    return (0);
}