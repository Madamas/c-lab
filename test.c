#include "part1.h"

int main()
{
	int a;
	int size = 0;
	printf("1 - %d\n",substr("Hello World!", "orl"));
	printf("2 - %d\n",subseq("mik","tek"));
	printf("3 - %c\n",ispal("ik"));
	printf("4 - %p\n",makepal("mikkk"));
	
	double *arr = txt2double("3.1.4;8.16;10", &size);
	for (int i = 0; i < size; i++)
	{
		printf("5 - arr[%d] = %.4f\n", i, arr[i]);
	}
	scanf("%d", &a);
	// 5  - char * strncpy ( char * destination, const char * source, size_t num );
	return 0;
}