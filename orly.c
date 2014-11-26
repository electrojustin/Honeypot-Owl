#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void __libc_start_main (int (*main)(int, char **, char **), int argc, char **argv,
	int (*init)(int, char **, char **), void (*fini)(void),
	void (*ldso_fini)(void))
{
	char preapproved [][20] = {"ls", "bash", "wget", "vim", "nano", "w", "ifconfig", "curl", "touch", "cat"};
	int i = 0;
	char result = 1; //Can really be anything but 0
	for (i; i < sizeof(preapproved); i ++)
	{
		result = strcmp (argv [0], preapproved [i]);
		if (!result)
			break;
	}

	if (result)
	{
		char input [10];
		while (1)
		{
			printf ("{o,o}\n|)__)\n_\"_\"_\n O RLY?\n");
			fgets (input, 10, stdin);
			if (!strcmp (input, "yes\n") || !strcmp (input, "ya\n"))
				break;
		}
		printf ("{o,o}\n(__(|\n_\"_\"_\n NO WAI\n");
		exit (0);
	}
	else
	{
		void (*actual_start_main)(int (*)(int, char **, char **), int, char **, int (*)(int, char **, char **), void (*)(void), void (*)(void)) = dlsym (RTLD_NEXT, "__libc_start_main");
		actual_start_main (main, argc, argv, init, fini, ldso_fini);
	}
}
