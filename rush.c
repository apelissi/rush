#include "unistd.h"

int	is_int(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] && str[j] == '0')
		j++;
	if (!str[j])
		return (-1);
	while (str[i + j])
	{
		if (str[i + j] < '0' || str[i + j] > '9')
			return (0);
		i++;
	}
	return (i);
}

void	unit(char c)
{
	if (c == '1')
		write(1, "Lester", 6);
	if (c == '2')
		write(1, "Clement", 7);
	if (c == '3')
		write(1, "Alex", 4);
	if (c == '4')
		write(1, "Nathan", 6);
	if (c == '5')
		write(1, "Helios", 6);
	if (c == '6')
		write(1, "une pierre", 10);
	if (c == '7')
		write(1, "ta soeur", 8);
	if (c == '8')
		write(1, "le pere noel", 12);
	if (c == '9')
		write(1, "nany mc fee", 11);
}

void	dizaine(char c)
{
	if (c == '2')
		write(1, "taper", 5);
	if (c == '3')
		write(1, "manger", 6);
	if (c == '4')
		write(1, "enclancher", 10);
	if (c == '5')
		write(1, "courtiser", 9);
	if (c == '6')
		write(1, "offrir des fleurs a", 19);
	if (c == '7')
		write(1, "fumer avec", 10);
	if (c == '8')
		write(1, "travailler pour", 15);
	if (c == '9')
		write(1, "embrasser", 9);
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
	if (big == 4)
		write (1, "trillion", 8);
}


int	main(int ac, char **av)
{
	int	size;
	int	big;
	int 	i;
	int	nf;
	int	val;

	if (ac != 2)
		return (write(1, "mv nb d'arguments\n", 18));
	if (!(size = is_int(av[1])))
		return (write(1, "pas un int\n", 11));
	if (size == -1)
		return (write(1, "zero", 4));
	i = 0;
	while (av[1][i] && av[1][i] == '0')
		i++;
	av[1]= &av[1][i];
	big = (size - 1) / 3;
	i = 0;
	nf = 0;
	val = 0;
	while (i < size)
	{
		if ((size - i) % 3 == 0 && av[1][i] != '0')
		{
			if (nf)
				write(1, " ", 1);
			unit(av[1][i]);
			write(1, " ", 1);
			write (1, "va", 2);
			val++;
			nf++;;
		}	
		else if ((size - i) % 3 == 2 && av[1][i] != '0' && av[1][i] != '1')
		{
			if (nf)
				write(1, " ", 1);
			dizaine(av[1][i]);
			val++;
			nf++;
		}
		else if ((size - i) % 3 == 1 && av[1][i - 1] && av[1][i - 1] == '1')
		{
			if (nf)
				write(1, " ", 1);
			dix(av[1][i]);
			val++;
			nf++;
		}
		else if ((size - i) % 3 == 1 && av[1][i - 1] != '1' && av[1][i] != '0') 
		{
			if (nf)
				write(1, " ", 1);
			unit(av[1][i]);
			val++;
			nf++;
		}
		if ((size - i) % 3 == 1 && val)
		{
			if (big)
				write(1, " ", 1);
			how_big(big);
			big--;
			val = 0;
		}
		i++;
	}
	return (0);
}
