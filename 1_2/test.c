#include "part2.h"

int main()
{
	//char *const string = "SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8";
	char *argz;
	size_t argz_len;
	if (argz_create_sep ("SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8", 58/*ASCII for : */, &argz, &argz_len) == OK)
	{
	argz_print(argz,argz_len);
	size_t argz_c = argz_count (argz, argz_len);
	argz_add(&argz,&argz_len,"kekbung");
	printf("\n%d\n", argz_c);
	argz_print(argz,argz_len);
	printf("\n");
	argz_delete(&argz,&argz_len,argz);
	argz_print(argz,argz_len);
	printf("\n");
	argz_insert(&argz,&argz_len,argz,"kek");
	argz_print(argz,argz_len);
	printf("\n");
	argz_replace(&argz,&argz_len,"kek","buntag");
	argz_print(argz,argz_len);
	} else printf("Error");
	return 0;
};