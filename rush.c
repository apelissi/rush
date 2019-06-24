#include "unistd.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (i);
}

void	unit(char c)
{
	if (c == '1')
		write(1, "one", 3);
	if (c == '2')
		write(1, "two", 3);
	if (c == '3')
		write(1, "three", 5);
	if (c == '4')
		write(1, "four", 4);
	if (c == '5')
		write(1, "five", 4);
	if (c == '6')
		write(1, "six", 3);
	if (c == '7')
		write(1, "seven", 5);
	if (c == '8')
		write(1, "eight", 5);
	if (c == '9')
		write(1, "nine", 4);
}

void	dizaine(char c)
{
	if (c == '2')
		write(1, "twenty", 6);
	if (c == '3')
		write(1, "thirty", 6);
	if (c == '4')
		write(1, "fourty", 6);
	if (c == '5')
		write(1, "fifty", 5);
	if (c == '6')
		write(1, "sixty", 5);
	if (c == '7')
		write(1, "seventy", 7);
	if (c == '8')
		write(1, "eighty", 6);
	if (c == '9')
		write(1, "ninety", 6);
}

void	dix(char c)
{
	if (c == '0')
		write(1, "ten", 3);
	if (c == '1')
		write(1, "eleven", 6);
	if (c == '2')
		write(1, "twelve", 6);
	if (c == '3')
		write(1, "thirteen", 8);
	if (c == '4')
		write(1, "fourteen", 8);
	if (c == '5')
		write(1, "fifteen", 7);
	if (c == '6')
		write(1, "sixteen", 7);
	if (c == '7')
		write(1, "seventeen", 9);
	if (c == '8')
		write(1, "eighteen", 8);
	if (c == '9')
		write(1, "nineteen", 8);
}


void	how_big(int big)
{
	if (big == 1)
		write (1, "thousand", 8);
	if (big == 2)
		write (1, "million", 7);
	if (big == 3)
		write (1, "billion", 7);
}
int	main(int ac, char **av)
{
	int	size;
	int	big;
	int 	i;
	int	nf;

	if (ac != 2)
		return (write(1, "mv nb d'arguments\n", 18));
	if (!(size = is_int(av[1])))
		return (write(1, "pas un int\n", 11));
	big = (size - 1) / 3;
	i = 0;
	nf = 0;
	while (i < size)
	{
		if ((size - i) % 3 == 0 && av[1][i] != '0')
		{
			if (nf)
				write(1, " ", 1);
			unit(av[1][i]);
			write(1, " ", 1);
			write (1, "hundred", 7);
			nf++;;
		}	
		else if ((size - i) % 3 == 2 && av[1][i] != '0' && av[1][i] != '1')
		{
			if (nf)
				write(1, " ", 1);
			dizaine(av[1][i]);
			nf++;
		}
		else if ((size - i) % 3 == 1 && av[1][i - 1] && av[1][i - 1]== '1')
		{
			if (nf)
				write(1, " ", 1);
			dix(av[1][i]);
			nf++;
		}
		else if ((size - i) % 3 == 1 && av[1][i - 1] != '1')
		{
			if (nf)
				write(1, " ", 1);
			unit(av[1][i]);
			nf++;
		}
		if ((size - i) % 3 == 1)
		{
			if (big)
				write(1, " ", 1);
			how_big(big);
			big--;
		}
		i++;
	}
}
