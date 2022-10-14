#include <stdio.h>
#include <unistd.h>
#include "mymalloc.h"
#include <stdlib.h>

void delete_from_free_list(Block **free_list_ref, Block *del)
{

	printf("State: delete, START");
	/* base case */
	if (*free_list_ref == NULL || del == NULL)
	{
		printf("Error: NULL POINTER");
		return;
	}

	/* If node to be deleted is head node */
	if (*free_list_ref == del)
	{
		printf("State: delete, first element");
		*free_list_ref = del->next;
	}

	/* Change next only if node to be deleted is NOT the last node */
	if (del->next != NULL)
	{
		printf("State: delete, not last element");
		del->next->prev = del->prev;
	}

	/* Change prev only if node to be deleted is NOT the first node */
	if (del->prev != NULL)
	{
		printf("State: delete, not first element");

		del->prev->next = del->next;
	}

	return;
}

void append_free_list(Block **free_list_ref, Block *free_block)
{
	printf("\n**************************\n");

	printf("\nState: append_free_list, start");

	Block *last = *free_list_ref; /* used in step 5*/
	free_block->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		Block as heap_start
 */
	if (*free_list_ref == NULL)
	{
		printf("\nState: append_free_list, first if");
		free_block->prev = NULL;
		*free_list_ref = free_block;

		/*printf("------------------------------------------free_list->NEXT: %p", free_list->next);
		//printf("------------------------------------------free_block->NEXT: %p", free_block->next);
		//free_list->next = NULL;

		/*printf("\n---------------------------------------------------------");
		printf("\nState: append_free_list, heap_start: %p", heap_start);
		printf("\nState: append_free_list, free_list: %p", free_list);
		printf("\nState: append_free_list, free_block: %p", free_block);
		printf("\nfree_list first element : isfree: --%d--", free_list->info.isfree);
		printf("\n---------------------------------------------------------");*/
		return;
	}

	/* 5. Else traverse till the last Block */
	while (last->next != NULL)
	{
		printf("\nState: append_free_list, **WHILE**");
		last = last->next;
	}
	/*printf("\n---------------------------------------------------------");
	printf("\nState: append_free_list, heap_start: %p", heap_start);
	printf("\nState: append_free_list, free_list: %p", free_list);
	printf("\nState: append_free_list, last: %p", last);
	printf("\nState: append_free_list, free_block: %p", free_block);
	printf("\n---------------------------------------------------------");*/
	/* 6. Change the next of last Block */
	last->next = free_block;

	/* 7. Make last Block as previous of new Block */
	free_block->prev = last;
	/*printf("\n---------------------------------------------------------");
	printf("\nState: append_free_list, heap_start: %p", heap_start);
	printf("\nState: append_free_list, free_list: %p", free_list);
	printf("\nState: append_free_list, last: %p", last);
	printf("\nState: append_free_list, free_block: %p", free_block);
	printf("\nState: append_free_list, end");
	printf("\n---------------------------------------------------------");*/

	printf("\n**************************\n");

	return;
}

void first_call(Block **heap_start_ref)
{
	printf("\n**************************\n");
	printf("\nState: first_call, start");
	alloc_heap(SIZE);

	Block *first_block = *heap_start_ref;
	first_block->info.isfree = 1;
	first_block->info.size = SIZE - sizeof(Block);
	append_free_list(&free_list, first_block);

	/*printf("\n---------------------------------------------------------");
	printf("\nState: first_call, heap_start: %p", heap_start);
	printf("\nState: first_call, free_list: %p", free_list);
	printf("\nState: first_call, first_block: %p", first_block);
	printf("\nState: first_call, end");
	printf("\n---------------------------------------------------------");*/
	printf("\n**************************\n");
}

Block *split(Block *block, size_t size)
{
	printf("\n**************************\n");
	printf("\nState: split, start");

	Block *selected_block = block;
	selected_block->info.size = size;
	selected_block->info.isfree = 0;

	/*printf("\n---------------------------------------------------------");
	printf("\nState: split, heap_start: %p", heap_start);
	printf("\nState: split, free_list: %p", free_list);
	printf("\nState: split, block: %p", block);
	printf("\nState: split, selected_block: %p", selected_block);
	printf("\n---------------------------------------------------------");*/

	Block *free_block = (Block *)(char *)selected_block + sizeof(Block) + selected_block->info.size;
	printf("\nState: split, free_block: %p", free_block);
	free_block->info.isfree = 1;
	free_block->info.size = selected_block->info.size - size - sizeof(Block);
	append_free_list(&free_list, free_block);
	//delete_from_free_list(&free_list, selected_block);

	/*printf("\n---------------------------------------------------------");
	printf("\nState: split, heap_start: %p", heap_start);
	printf("\nState: split, free_list: %p", free_list);
	printf("\nState: split, free_list->next: %p", free_list->next);
	printf("\nState: split, block: %p", block);
	printf("\nState: split, free_block: %p", free_block);
	printf("\nState: split, selected_block: %p", selected_block);
	printf("\n---------------------------------------------------------");*/
	printf("\nState: split, end");
	printf("\n**************************\n");

	return selected_block;
}

Block *first_fit(Block **free_list_start, size_t size)
{
	printf("\n**************************\n");
	printf("\nState: first_fit, start");

	Block *last = *free_list_start; /* used in step 5*/
	/*printf("\n---------------------------------------------------------");
	printf("\nState: first_fit, heap_start: %p", heap_start);
	printf("\nState: first_fit, free_list: %p", free_list);
	printf("\nState: first_fit, free_list_start: %p", *free_list_start);
	printf("\nState: first_fit, last: %p", last);
	printf("\n---------------------------------------------------------");*/
	if (last == NULL)
	{
		printf("Error: first_fit, Block *last is NULL");
		return NULL;
	}

	/* if list has just one element*/
	if (last->info.isfree == 1 && last->info.size >= size)
	{
		printf("\nState: first_fit, **IF** list has just one element");
		if (size == last->info.size)
		{
			printf("\nState: first_fit,**IF** size==size");
			last->info.isfree = 0;
			return last;
		}
		else
		{
			printf("\nState: first_fit, **ELSE** goes to split");
			return split(last, size);
		}
	}

	/* 5. Else traverse till the last Block */
	while (last->next != NULL)
	{
		printf("\nState: first_fit, **WHILE**");

		if (last->info.isfree == 1 && last->info.size >= size)
		{
			printf("\nState: first_fit, **WHILE** **IF**");
			if (size == last->info.size)
			{
				printf("\nState: first_fit, **WHILE** **IF** **IF** SIZE==SIZE");
				return last;
			}
			else
			{
				printf("\nState: first_fit, **WHILE** **IF** **ELSE** GOES SPLIT");
				return split(last, size);
			}
		}
		else
		{
			printf("\nState: first_fit, **WHILE** **ELSE**");
			last = last->next;
		}
	}
	printf("\nState: first_fit, end");

	printf("\n**************************\n");

	return NULL;
}

void *mymalloc(size_t size)
{
	printf("\n***************MYMALLOC**START*************\n");
	if (heap_start == NULL)
	{
		printf("\nState: mymalloc, heap_start==NULL");
		first_call(&heap_start);
	}

	if (size % 16 != 0)
	{
		size = ((size + 15) / 16) * 16;
		printf("\nState: mymalloc, size settings**size: %ld", size);
	}

	if (size >= SIZE)
	{
		printf("\nError: mymalloc, size can't be bigger than Heap Size"); //////////////////////////////
		perror(NULL);
	}

	Block *new_block;
	/*printf("\n---------------------------------------------------------");
	printf("\nState: mymalloc, heap_start: %p", heap_start);
	printf("\nState: mymalloc, free_list: %p", free_list);
	printf("\nState: mymalloc, new_block: %p", new_block);
	printf("\n---------------------------------------------------------");*/
	//new_block = best_fit;
	new_block = first_fit(&free_list, size);
	//new_block = worst_fit;
	/*printf("\n---------------------------------------------------------");
	printf("\nState: mymalloc, heap_start: %p", heap_start);
	printf("\nState: mymalloc, free_list: %p", free_list);
	printf("\nState: mymalloc, free_list->next: %p", free_list->next);
	printf("\nState: mymalloc, first_block: %p", new_block);
	printf("\n---------------------------------------------------------");*/
	if (new_block == NULL)
	{
		printf("\nError: mymalloc, new_block is NULL "); //////////////////////////////////////////
		return NULL;
	}

	if (new_block->info.size >= size && new_block->info.isfree)
	{
		printf("\nState: mymalloc, **IF** SUCCES RETURN");
		new_block->data = new_block->info.size - 16;
		return new_block;
	}

	printf("\nState: mymalloc, END");

	printf("\n**************************\n");

	return NULL;
}

void append(Block **heap_start_ref, int new_data)
{
	Block *new_Block = (Block *)malloc(sizeof(Block));

	Block *last = *heap_start_ref;

	new_Block->data = new_data;

	new_Block->next = NULL;

	if (*heap_start_ref == NULL)
	{
		new_Block->prev = NULL;
		*heap_start_ref = new_Block;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_Block;
	new_Block->prev = last;

	return;
}

void printList(Block **block, Block **free_block)
{
	Block *last = *block;
	Block *last_free = *free_block;
	printf("\n+++++++++++++++++++++BLOCKS++++++++++++++++++++++\n");
	;
	while (last != NULL)
	{
		printf("\n////////////////////////");
		printf("\nDATA:  %d ", last->data);
		printf("\nISFREE:  %d ", last->info.isfree);
		printf("\nSIZE:  %d ", last->info.size);
		last = last->next;
	}

	printf("\n$$$$$$$$$$$FREE$$$$$$$$$$$$$$$$$$$\n");

	while (last_free != NULL)
	{
		printf("\n////////////////////////");
		printf("\nDATA:  %d ", last_free->data);
		printf("\nISFREE:  %d ", last_free->info.isfree);
		printf("\nSIZE:  %d ", last_free->info.size);
		last_free = last_free->next;
	}
}

#define ALIGNMENT 16 // must be a power of 2
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

int main()
{

	//mymalloc(60);
	//mymalloc(90);
	printf("\n--%d--", ALIGN(7));
	printf("\n--%d--", ALIGN(19));
	printf("\n--%d--", ALIGN(33));

	return 0;
}

// /* Given a Block as prev_Block, insert a new Block after the
// * given Block */
// void insertAfter(Block *prev_Block, int new_data)
// {
// 	/*1. check if the given prev_Block is NULL */
// 	if (prev_Block == NULL)
// 	{
// 		printf("the given previous Block cannot be NULL");
// 		return;
// 	}

// 	/* 2. allocate new Block */
// 	Block *new_Block = (Block *)malloc(sizeof(Block));

// 	/* 3. put in the data */
// 	new_Block->data = new_data;

// 	/* 4. Make next of new Block as next of prev_Block */
// 	new_Block->next = prev_Block->next;

// 	/* 5. Make the next of prev_Block as new_Block */
// 	prev_Block->next = new_Block;

// 	/* 6. Make prev_Block as previous of new_Block */
// 	new_Block->prev = prev_Block;

// 	/* 7. Change previous of new_Block's next Block */
// 	if (new_Block->next != NULL)
// 	{
// 		Block *temp;
// 		temp = new_Block->next;
// 		temp->prev = new_Block;
// 	}
// }

// void push(Block **heap_start_ref, int new_data)
// {
// 	/* 1. allocate Block */
// 	Block *new_Block = (Block *)malloc(sizeof(Block));

// 	/* 2. put in the data */
// 	new_Block->data = new_data;

// 	/* 3. Make next of new Block as heap_start and previous as NULL
// 	*/
// 	new_Block->next = (*heap_start_ref);
// 	new_Block->prev = NULL;

// 	/* 4. change prev of heap_start Block to new Block */
// 	if ((*heap_start_ref) != NULL)
// 		(*heap_start_ref)->prev = new_Block;

// 	/* 5. move the heap_start to point to the new Block */
// 	(*heap_start_ref) = new_Block;
// }
