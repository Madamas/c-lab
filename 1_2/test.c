#include "part2.h"

int main()
{
	//char *const string = "SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8";
	char *argz;
	size_t argz_len;
	if (argz_create_sep ("SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8", 58/*ASCII for : */, &argz, &argz_len) == OK)
	{
	for (size_t i = 0; i < argz_len; i++)
		printf("%c", *(argz+i));
	size_t argz_c = argz_count (argz, argz_len);
	argz_add(&argz,&argz_len,"kekbung");
	printf("\n%d\n", argz_c);
	for (size_t i = 0; i <= argz_len; i++)
		printf("%c", *(argz+i));
	} else printf("Error");
	return 0;
}