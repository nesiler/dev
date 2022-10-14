#include <stdio.h>
#include <stdbool.h>

int countDuplicate(int numbers_count, int *numbers)
{

    int count = 0;
    bool duplicate = false;

    for (int i = 0; i < numbers_count; i++)
    {
        duplicate = false;
        if (numbers[i] == -1)
            continue;
        for (int j = i + 1; j < numbers_count; j++)
        {
            if (numbers[i] == numbers[j])
            {
                duplicate = true;
                numbers[j] = -1;
            }
        }
        if (duplicate)
            count++;
    }

    return count;
}

int main(int argc, char **argv)
{
    int numbers_count = 11;

    int numbers[11] = {1, 3, 1, 3, 2, 1, 7, 5, 2, 8, 9};
    int result = countDuplicate(numbers_count, numbers);
    printf("   %d   ", result);
    return 0;
}
