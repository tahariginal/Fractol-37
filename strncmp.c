#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	//t a h a
	//t a h a
//          l 
	while (n && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (*s1 - *s2);
}

int	main(int ac, char **av)
{
	if (2 == ac && !ft_strncmp(av[1], "taha", 4))
	{
		printf("%d \n", ft_strncmp(av[1], "taha", 4));
	}
	else
		puts("KO!");
}
