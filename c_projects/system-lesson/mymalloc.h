#include <stdio.h>
/*BU DOSYAYI DEGISTIRMEYINIZ
*/

#define ALIGN(size) (((size) + (16 - 1)) & ~(16 - 1))
#define HEADER_SIZE (ALIGN(sizeof(Block))) // header size

typedef enum
{
    bestFit,
    worstFit,
    firstFit
} Strategy;

Strategy strategy = firstFit;

typedef struct
{
    unsigned int size;
    unsigned int isfree;
} Info;

typedef struct Block Block;

struct Block
{
    Info info;          /* number of  16 byte blocks            */
    struct Block *next; /* next free                            */
    struct Block *prev; /* prev free                            */
    char data[0];       /* start of the allocated memory        */
};
/*memory layout of Block: 
|4byte(size)|4byte(isfree)|8-byte next|8-byte prev|0-byte(data)|
*/

static Block *free_list = NULL;  /* start of the free list               */
static Block *heap_start = NULL; /* head of allocated memory from sbrk   */
static Block *heap_end = NULL;   /* head of allocated memory from sbrk   */

static size_t SIZE = 10240;

void *mymalloc(size_t size);
void *myfree(void *p);
Block *split(Block *b, size_t size);
void printHeap();

Block *alloc_heap(size_t size)
{
    heap_start = (Block *)sbrk(1024);

    if (sbrk(SIZE) == (void *)-1)
    {
        return (void *)-1;
    }

    heap_end = sbrk(0);

    return heap_start;
}