#include "part2.h"

error_t argz_create_sep (const char *string, int sep, char **argz, size_t *argz_len){
	*argz_len = strlen(string) + 1;
	*argz = (char*)malloc((*argz_len)*sizeof(char));
	if (sep > 255 || sep < 0)
		return ENOMEM;
	for(size_t i = 0; i < *argz_len; i++){
		if (*(string+i) == sep)
			*(*argz+i) = '\0';
		else
			*(*argz + i) = *(string + i);
	}
	return OK;
};

size_t argz_count (const char *argz, size_t argz_len){
	size_t argz_count = 0;
	for (size_t i = 0; i < argz_len; i++){
		if (*(argz + i) == '\0')
			argz_count++;
	}
	return argz_count;
}

error_t argz_add (char **argz, size_t *argz_len, const char *str){
	size_t length = strlen(str);
	*argz_len = *argz_len + length;
	*argz = realloc(*argz, (*argz_len)*sizeof(char));
	for (size_t i = 0; i <= length;i++){
		*(*argz+*argz_len-length+i+1) = *(str+i);
	}
	return OK;
}