#include <stdio.h>

int	ft_isflag(int c)
{
	if (c == '#' || c == '-' || c == ' ' || c == '+' || c == '*' || c == '.'
		|| c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	return_test(void)
{
	int	i = 42;
	return (++i);
}

int	main(void)
{
	// char	c = ')';
	int		i;

	// printf("%c\n", c);
	// i = ft_isflag(c);
	i = return_test();
	printf("%d\n", i);
	return (0);
}

