#include "mem_manag.h"

void init(mem_dispatcher *md){
	md->first = (mem_chunk*)malloc(sizeof(mem_chunk));
	md->first->id=0;
	md->first->size=HEAP_SIZE;
	md->first->status=FREE;
	md->first->next=NULL;
	md->last_id_used=0;
};

int allocate(mem_dispatcher *md, int size){
mem_chunk *minimal = md->first;
int min_size = HEAP_SIZE;
mem_chunk *buff = NULL;
mem_chunk *current;

	for(current = md->first; NULL != current; current=current->next)
	{
		if(current->status==FREE && current->size <= min_size && current->size >= size)
		{
			minimal = current;
			min_size = current->size;
		}
	}

if ((minimal == md->first && minimal->size < size) || NULL == (buff = (mem_chunk*)malloc(sizeof(mem_chunk))))
	return -1;

if(minimal->size == size && minimal->status == FREE){
	minimal->status = ALLOCATED;
	return minimal->id;
}

buff->size = size;
minimal->size -=size;
md->last_id_used += 1;
buff->id = md->last_id_used;
buff->next=minimal->next;
minimal->next=buff;
buff->status=ALLOCATED;

return buff->id;
};

int deallocate(mem_dispatcher *md, int block_id){
mem_chunk *current = NULL;
mem_chunk *buff = NULL;
	for (current = md->first; current != NULL; current = current->next)
	{
		if(current->id == block_id)
			break;
	}

	if (current == NULL)
	 	return -1;

current->status = FREE;
current = md->first;
	while (current->next != NULL){
		if (current->status == FREE && current->next->status == FREE){
			current->size += current->next->size;
			buff = current->next->next;
			free(current->next);
			current->next = buff;
		}
		else current = current->next;
	}
return 1;
};

void defragment(mem_dispatcher *md)
{
	mem_chunk *current = md->first->next;
	mem_chunk *end = md->first;
	mem_chunk *buff = NULL;
	
	while (NULL != current)
	{
		if (end->status != current->status)
		{
			if (FREE == current->status)
			{
				if (FREE == md->first->status)
				{
					md->first->size += current->size;
					end->next = current->next;
					free(current);
					current = end;
				}
				else
				{
					end->next = current->next;
					current->next = md->first;
					md->first = current;
					current = end;
				}
			}
			else
			{
				end = current;
			}

			current = current->next;

			continue;
		}

		if (current->status == FREE)
		{
			md->first->size += current->size;
			end->next = current->next;
			buff = current;
			current = current->next;
			free(buff);
		}
		else
		{
			end = current;
			current = current->next;
		}
	}
};

void show_memory_map(mem_dispatcher *md)
{
	mem_chunk *current = md->first;

	while (NULL != current)
	{
		printf("block id: %d\n", current->id);
		printf("                size: %d   status: %s\n", current->size, current->status == FREE ? "free" : "allocated");
		current = current->next;
	}
};
