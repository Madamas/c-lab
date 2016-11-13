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
}

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
		*(*argz+*argz_len-length+i) = *(str+i);
	}
	return OK;
}
void argz_delete (char **argz, size_t *argz_len,char *entry){
	size_t length = strlen(entry);
	memmove(entry,entry + length + 1,(*argz_len-(entry - *argz)));
	*argz_len = *argz_len - length;
	*argz = realloc(*argz,*argz_len);
}
error_t argz_insert (char **argz, size_t *argz_len, char *before, const char *entry){
	size_t length = strlen(entry)+1;
	*argz_len = *argz_len + length;
	*argz = realloc(*argz,*argz_len);
	if (before < *argz)
		return ENOMEM;
	memmove(before + length,before,*argz_len - (before - *argz));
	memcpy(before,entry,length);
	return OK;
}

char * argz_next (char *argz, size_t argz_len, const char *entry){
	if (entry == NULL)
		return argz;
	for (char* ptr = entry; entry < argz + argz_len; ptr++){
		if (ptr == argz + argz_len - 1)
			return NULL;
		if (*ptr == '\0'){
			return ptr+1;
		}
	}
	return NULL;
}

error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with){
 size_t length1 = strlen(str);
 size_t length2 = strlen(with);
 if (length1 == 0 || length2 == 0)
 	return ENOMEM;
 char *pointer = *argz;
 char *begin = NULL;
 while(pointer < *argz + *argz_len){
 	begin = strstr(pointer,str);
 	if (begin == NULL)
 	{
 		pointer = pointer + strlen(pointer) + 1;
 		continue;
 	}else break;
 }
 if (begin == NULL)
 	return ENOMEM;
 if (length1 > length2){
 	 memmove(begin + length2,begin + length1,*argz_len - (begin - *argz + length1));
 	 *argz = realloc(*argz,*argz_len-length1+length2);
 }else
 if (length1 < length2){
 	*argz = realloc(*argz,*argz_len-length1+length2);
 	memmove(begin + length2,begin + length1,*argz_len - (begin - *argz + length1));
 }
 *argz_len = *argz_len - length1 + length2;
 for(size_t i = 0; i < length2; i++){
 	*(begin + i) = *(with + i);
 }
 return OK;
}

void argz_print(const char *argz, size_t argz_len){
	char *entry = NULL;
	while ((entry = argz_next (argz, argz_len, entry)))
		printf("%s\n",entry);
}
