#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{

    int row, col, min, max, i = 0, *p;
    int maxR = 0, maxRI = 0, sumR = 0, maxC = 0, maxCI = 0, sumC = 0;
    int temp;
    time_t tt;
    srand(time(&tt));
    /*take array size*/
    do
    {
        printf("array boyutu\nGive rows: ");
        scanf("%d", &row);
        printf("Give columns: ");
        scanf("%d", &col);
    } while (row < 0 || col < 0);
    printf("\n");

    int matrix[row][col];

    /*min max values*/
    do
    {
        printf("PROCESS OF GIVING THE RANGE OF THE ARRAY\nGive minimum value: ");
        scanf("%d", &min);
        printf("Give maximum value: ");
        scanf("%d", &max);
    } while (min < 0 || max < 0);
    printf("\nPROCESS OF PRINTING THE ARRAY\n");

    /*create matrix*/

    for (int *p = &matrix[0][0]; p <= &matrix[row - 1][col - 1]; p++)
    {
        temp = rand() % (max - min + 1) + min;
        *p = temp;
        printf("%d, ", temp);
    }
    printf("\n");

    /*
    print matrix
    */
    for (int *p = &matrix[0][0]; p <= &matrix[row - 1][col - 1]; p++)
    {
        printf("%4d ", *p);
        if (i >= row - 1)
        {
            printf("\n");
            i = 0;
        }
        else
        {
            i++;
        }
    }

    /*find max row*/

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d,", matrix[i][j]);
            sumR += matrix[i][j];
        }
        printf("sumR : %d", sumR);
        if (sumR > maxR)
        {
            printf("\nif sum > maxR\n");
            maxRI = i;
            sumR = 0;
        }
    }
    printf("max row: %d", maxRI);

    /* for (int i = 0; i < row; i++)
     {
         for (p = &matrix[i][0]; p < &matrix[i][0] + col; p++)
         {
             sumR += *p;
             if (sumR > maxR)
             {
                 maxR = sumR;
                 maxRI = i;
                 printf("Max Row: %d -- p: %d\n", maxR, *p);
             }
         }
         sumR = 0;
     }*/
    return 0;
}