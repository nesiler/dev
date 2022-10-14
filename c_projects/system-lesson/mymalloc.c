#include <stdio.h>
#include <unistd.h>
#include "mymalloc.h"
#include <stdlib.h>

void *mymalloc(size_t size);
void *myfree(void *p);
void printHeap();
Block *first_block();
void append_free_list(Block *free_block);
Block *split(Block *block, size_t size);
Block *first_fit(size_t size);
Block *worst_fit(size_t size);
Block *best_fit(size_t size);

void *mymalloc(size_t size)
{
    size = ALIGN(size);

    if (heap_start == NULL)
    {
        printf("\nalloc heap");
        alloc_heap(SIZE);
        append_free_list(first_block());
    }

    Block *block = NULL;

    if (strategy == firstFit)
    {
        block = first_fit(size);
    }

    else if (strategy == worstFit)
    {
        block = worst_fit(size);
    }

    else if (strategy == bestFit)
    {
        block = best_fit(size);
    }

    printf("\nresult: %d", block->info.size);

    return block->data;
}

void *myfree(void *p)
{
    Block *current_block = p;
    Block *prev_block = current_block->prev;
    Block *next_block = current_block->next;

    if (current_block->prev != NULL && prev_block->info.isfree)
    {
        prev_block->info.size = prev_block->info.size + current_block->info.size + sizeof(Block);
        current_block = NULL;
        append_free_list(prev_block);
    }

    if (current_block->next != NULL && next_block->info.isfree)
    {
        current_block->info.size = next_block->info.size + current_block->info.size + sizeof(Block);
        next_block = NULL;
        append_free_list(current_block);
    }
}

Block *first_block()
{
    printf("\nfirst block");
    Block *block = heap_start;
    block->next = NULL;
    block->prev = NULL;
    block->info.size = SIZE - ALIGN(sizeof(Block));
    return block;
}

void append_free_list(Block *free_block)
{

    printf("\nappend");

    free_block->next = NULL;
    free_block->info.isfree = 1;

    if (free_list == NULL)
    {
        printf("\nappend if");
        free_block->prev = NULL;
        free_list = free_block;
        printf("\nfree_list: %p", free_list);
        return;
    }

    printf("\nappend else");

    Block *last = free_list;

    printf("--%p---", free_list->next);

    while (last->next != NULL)
    {
        printf("\nappend while");
        last = last->next;
    }

    printf("\nappend after while");

    last->next = free_block;
    free_block->prev = last;
    printf("--%p---", free_list->next);

    return;
}

Block *split(Block *block, size_t size)
{
    printf("\nsplit start");

    Block *selected_block = block;

    Block *free_block = (Block *)selected_block + sizeof(Block) + size;
    free_block->info.size = block->info.size - size;
    free_block->info.isfree = 1;

    selected_block->info.size = size;
    selected_block->info.isfree = 0;

    printf("\nsplit, selected_block size : %d", selected_block->info.size);
    printf("\nsplit, selected_block adress : %p", selected_block);

    printf("\nsplit, free_block size : %d", free_block->info.size);
    printf("\nsplit, block size : %ld", sizeof(Block));
    printf("\nsplit, free_block adress : %p", free_block);
    append_free_list(free_block);

    return selected_block;
}

Block *first_fit(size_t size)
{

    printf("\nfirst fit");

    Block *last = free_list;

    while (last != NULL)
    {
        printf("\nfirst fit while");
        if (last->info.isfree == 1 && last->info.size >= size)
        {
            printf("\nfirst fit if");

            if (size == last->info.size)
            {
                printf("\nfirst fit if if");
                return last;
            }
            else
            {
                printf("\nfirst fit else");
                return split(last, size);
            }
        }
        else
        {
            printf("\nfirst fit else");
            if (last->next != NULL)
            {
                printf("\nfirst fit else if");
                last = last->next;
            }
        }
    }

    printf("\nfirst fit end");

    return (Block *)-1;
}

Block *worst_fit(size_t size)
{

    printf("\nworst_fit");

    Block *last = free_list;

    Block *biggest;

    while (last != NULL)
    {
        printf("\nworst_fit while");

        if (last->info.size >= size && last->info.isfree)
        {
            printf("\nworst_fit if");

            if (last->info.size >= biggest->info.size)
            {
                printf("\nworst_fit biggest before: %d", biggest->info.size);
                biggest = last;
                printf("\nworst_fit biggest after: %d", biggest->info.size);
            }
            else
                continue;
        }
        if (last->next != NULL)
        {
            last = last->next;
        }
        else
            break;
    }

    if (biggest != NULL)
        return split(biggest, size);

    printf("\nworst_fit end");

    return (Block *)-1;
}

Block *best_fit(size_t size)
{

    printf("\nbest_fit");

    Block *last = free_list;

    Block *smallest;

    while (last != NULL)
    {
        printf("\nbest_fit while");

        if (last->info.size >= size && last->info.isfree)
        {
            printf("\nbest_fit if");

            if (last->info.size <= smallest->info.size)
            {
                printf("\nbest_fit smallest before: %d", smallest->info.size);
                smallest = last;
                printf("\nbest_fit smallest after: %d", smallest->info.size);
            }
        }
        if (last->next != NULL)
        {
            last = last->next;
        }
        else
            break;
    }

    if (smallest != NULL)
        return split(smallest, size);

    printf("\nbest_fit end");

    return (Block *)-1;
}

void printHeap()
{

    Block *last = free_list;
    while (last != NULL)
    {
        printf("\n**********\nAdress: %p", last);
        printf("\nis free: %d", last->info.isfree);
        printf("\nSize: %d", last->info.size);
        printf("\nNext Adress: %p", last->next);

        if (last->next != NULL)
        {
            last = last->next;
        }
        else
            return;
    }
    return;
}

int main()
{

    mymalloc(60);

    strategy = worstFit;
    mymalloc(30);
    myfree(heap_start);

    strategy = bestFit;
    mymalloc(47);

    strategy = firstFit;
    mymalloc(150);
    myfree(heap_start);

    printHeap();

    return 1;
}
