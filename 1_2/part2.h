#if defined PART2
#endinput
#endif
#define PART2

typedef enum  {OK, ENOMEM} error_t

#include <stdio.h>
#include <string.h> // strlen(), strstr(), ..
#include <stdlib.h> // calloc(), malloc(), realloc(), free()



error_t argz_create_sep (const char *string, int sep, char **argz, size_t *argz_len);