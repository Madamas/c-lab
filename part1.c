/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2016 Vadim Maslov <mrvadamas@gmail.com>
 * 
 * lab1-oop is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * lab1-oop is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _CRT_SECURE_NO_WARNINGS
#include "part1.h"
int substr(const char *string1, const char *string2) {
	const char *point = strstr(string1, string2);
	return point != NULL ? point - string1 + 1 : -1;
}

int subseq(const char *string1, const char *string2){
	int length1 = strlen(string1);
	int length2 = strlen(string2);
	int *matrix = (int*)calloc((length1+1)*(length2+1),sizeof(int));
	int max = *(matrix);
	int maxi,maxj = 0;
 	for (int i = 0; i < length1; i++){
 		for (int j = 0; j < length2; j++){
 			if (*(string1+i) == *(string2+j)){
 				if (i == 0 || j == 0)
 					*(matrix+i*length2+j) = 1;
 				else
 					{
 						*(matrix+i*length2+j) = *(matrix+(i-1)*length2+(j-1))+1;
 						if ((*(matrix+(i-1)*length2+j-1))>max)
 							max = (*(matrix+(i-1)*length2+(j-1)));
 							maxi = i;
 							maxj = j;
 					}
 			}
 		}
 	}
 	max = *(matrix + maxi*length2+maxj);
	free(matrix);
	return max;
}

char ispal(const char *string) {
	int length = strlen(string);
	for (int i = 0; i < length / 2; i++)
		if (*(string + i) != *(string + length - i - 1))
			return '0';
	return '1';
}

char* makepal(const char *string) {
	int length = strlen(string);
	char *substr = (char*)calloc(2 * length,sizeof(char));
	int addPoint = 0;
	for (int i = 0; i < length; i++){
		char isPal = ispal(string + i);
		if (isPal == '1') {
			addPoint = i-1;
			break;
		}
		addPoint = i-1;
	}
	strcpy(substr, string);
	if (addPoint == -1)
		return substr;
	else
		for (int i = addPoint; i >= 0; i--) {
			*(substr + length + addPoint - i) = *(string + i);
		}
	return substr;
}

double* txt2double(const char *string , int *size){
	int length = strlen(string);
	double* vect = NULL;
	*size = 0;
	char *head = string;
		do {
			if(isdigit(*head)){
				vect = realloc(vect,++*size * sizeof(double));
				vect[*size-1] = strtod(head,&head);
			} else 
			if (*head == ';')
			{
				head++;
			}else 
			{
				*size = 0;
				free(vect);
				return NULL;
			}

		} while(head < string + length);
	return vect;

}

