#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 10

typedef  enum{ FREE, ALLOCATED } STATUS;
typedef struct tag_mem_chunk{
	int id;
	int size;
	STATUS status;
	struct tag_mem_chunk* next;//pointer to the next memory block
}mem_chunk;

typedef struct {
	int last_id_used;
	 mem_chunk* first;//pointer to the first memory block
}mem_dispatcher;



void init(mem_dispatcher *md);
//Ініціалізує карту пам'яті одним вільним блоком з id 0 розміру HEAP_SIZE.
int allocate(mem_dispatcher *md, int size);
//Додає в список вузол, відповідний до зайнятого блоку розміру size. У випадку успіху повертає номер блоку й -1 - а якщо ні, то. 
int deallocate(mem_dispatcher *md, int block_id);
//Видаляє зі списку вузол з номером  block_id. У випадку успіху повертає ненегативне значення й -1 в іншому випадку. Якщо є блоки суміжні з block_id, вони поєднуються.
void defragment(mem_dispatcher *md);
//Поєднує всі вільні блоки в один.
void show_memory_map(mem_dispatcher *md);
//Виводить у консоль поточний стан карти пам'яті.