#include <iostream>

static void print_ft_upper(char **av)
{
	int i = 1;
	while (av[i])
	{
		int j = 0;
		while (av[i][j])
		{
			std::cout << (char)toupper(av[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}


int main(int ac, char **av)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_ft_upper((char **)av);
	return (0);
}
