#include "./minitalk.h"

int	ft_strlen(char *str)
{
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (str[++i] != '\0')
		++len;
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int	int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		++len;
		n *= (-1);
	}
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= (-1);
	}
	else if (nbr == 0)
		res[0] = '0';
	res[len] = '\0';
	while (len > 0 && nbr != 0)
	{
		--len;
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

int		ft_atoi(const char *nptr)
{
	int		i;
	int		positive;
	long	sum;

	i = 0;
	sum = 0;
	positive = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		++i;
	if (nptr[i] == '+')
		++i;
	else if (nptr[i] == '-')
	{
		positive *= -1;
		++i;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		sum = (sum * 10) + (nptr[i] - '0');
		++i;
	}
	return (positive * sum);
}
