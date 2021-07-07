#include "./../minitalk.h"

static void handler(int signum)
{
	static char byte = 0;
	static int shift = 7;

	if (signum == SIGUSR1)
	{
		byte |= (1 << shift);
		--shift;
	}
	if (signum == SIGUSR2)
		--shift;
	if (shift < 0)
	{
		ft_putchar(byte);
		if (byte == '\0')
			ft_putchar('\n');
		shift = 7;
		byte = 0;
	}
}

int main()
{
	struct sigaction sa;
	pid_t pid;
	
	pid = getpid();
	ft_putstr("PID - ");
	ft_putstr(ft_itoa(pid));
	ft_putchar('\n');
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1);
	return (0);
}
