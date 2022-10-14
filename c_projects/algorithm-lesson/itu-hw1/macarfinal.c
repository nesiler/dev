#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS (50)
#define MAX_COLUMNS (100)
#define FILE_NAME "aaa.txt"

void sortArray(int nameCount);
void printArray(int nameCount);

static char names[MAX_ROWS][MAX_COLUMNS] = {{'\0', '\0'}};

int main(void)
{
    FILE *fp = NULL;

    if (NULL == (fp = fopen(FILE_NAME, "r")))
    {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(names[i], MAX_COLUMNS, fp))
    {

        names[i][strlen(names[i]) - 1] = '\0';
        i++;
    }

    sortArray(i);

    printArray(i);

    return (0);
}

void sortArray(int nameCount)
{
    int c;
    int d;
    char swap[MAX_COLUMNS] = {'\0'};

    for (c = 0; c < (nameCount - 1); c++)
    {
        for (d = 0; d < (nameCount - c - 1); d++)
        {
            if (0 > strcmp(names[d], names[d + 1]))
            { // then words need to be swapped
                strcpy(swap, names[d]);
                strcpy(names[d], names[d + 1]);
                strcpy(names[d + 1], swap);
            }
        }
    }
}

void printArray(int nameCount)
{
    printf("SORTED NAMES: \n");
    int i;

    printf("\n");
    for (i = nameCount; i >= 0; i--)
    {
        strupr(names[i]);
        printf("%s\n", names[i]);
    }
}
