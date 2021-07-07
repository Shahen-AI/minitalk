#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <assert.h>

int		ft_strlen(char *str);
void	ft_error(char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
int		int_len(int n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_bytes(char *str, char *argv);
void	ft_bits(char bite);
char	bin_char(char *str);

#endif
