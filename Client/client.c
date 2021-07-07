#include "./../minitalk.h"

void ft_bytes(char *str, char *argv)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (str[i] == '1')
			kill(ft_atoi(argv), SIGUSR1);
		else
			kill(ft_atoi(argv), SIGUSR2);
		++i;
		usleep(100);
	}
}

char *char_bin(char c)
{
	char *res;
	int j;

	j = 0;
	if (!(res = malloc(9 * sizeof(char *))))
		ft_error("Allocation error!!!\n");
	for (int i = 7; i >= 0; --i)
	{
		res[j] = ( (c & (1 << i)) ? '1' : '0');
		++j;
	}
	res[j] = '\0';
	return (res);
}

int main(int argc, char **argv)
{
	char *temp;
	int j;

	j = 0;
	if (argc == 3)
	{
		while (argv[2][j])
		{
			temp = char_bin(argv[2][j]);
			ft_bytes(temp, argv[1]);
			++j;
		}
		ft_bytes("\n", argv[1]);
	}
	else
		ft_error("You must have only two arguments!!!\n./client [pid] [text]\n");
	return (0);
}
