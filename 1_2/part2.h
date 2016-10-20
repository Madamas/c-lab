#if defined PART2
#endinput
#endif
#define PART2

#include <stddef.h> // for  size_t
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#undef ENOMEM

typedef enum  {OK, ENOMEM} error_t;

error_t argz_create_sep (const char *string, int sep, char **argz, size_t *argz_len);
size_t argz_count (const char *argz, size_t argz_len);
error_t argz_add (char **argz, size_t *argz_len, const char *str);