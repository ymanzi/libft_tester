#include "ft_libft_test.h"

void segv_test_split1()
{
	signal(SIGSEGV, handler);
	ft_split(0, 'c');
	exit(1);
}

void split_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_split1();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	split_test()
{
	char	**tab;
	int		len[11];
	char	*str;

	printf("" YELLOW "~~~~~~~ SPLIT TEST ~~~~~~~\n" RESET "");
	split_segv_test();
	str = "       aaa bbbb         cc\tc      ddddd        ";
	tab = ft_split(str, ' ');
	if (!strcmp(tab[0], "aaa"))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	if (!strcmp(tab[1], "bbbb"))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	if (!strcmp(tab[2], "cc\tc"))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	if (!strcmp(tab[3], "ddddd")) 
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	if (!tab[4])
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	printf("\n");
}