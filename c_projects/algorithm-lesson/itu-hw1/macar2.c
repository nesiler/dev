#include <stdio.h>

void transpose_print()

{

    int compact_array[14][3] = {{0, 2, 15},

                                {1, 0, 24},

                                {1, 3, 18},

                                {2, 1, 17},

                                {3, 5, 42},

                                {4, 2, 26},

                                {5, 0, 13},

                                {6, 4, 19},

                                {7, 1, 28},

                                {8, 3, 23},

                                {9, 0, 22},

                                {9, 2, 16},

                                {10, 4, 32},

                                {10, 5, 27}};

    int row = 11;

    int col = 6;

    int row_t = col;

    int col_t = row;

    int sparse_matrix[row][col];

    int transposed_matrix[row_t][col_t];

    printf("\n=======\nMatrix:\n=======");

    for (int i = 0; i < 14; ++i)

    {

        printf("\n");

        for (int j = 0; j < 3; ++j)

        {

            printf("%d  ", compact_array[i][j]);
        }
    }

    int k = 0;

    for (int i = 0; i < row; i++)

    {

        for (int j = 0; j < col; j++)

        {

            while (k < 14)

            {

                if (compact_array[k][0] == i && compact_array[k][1] == j)

                {

                    sparse_matrix[i][j] = compact_array[k][2];

                    k++;

                    break;
                }

                else

                {

                    sparse_matrix[i][j] = 0;

                    break;
                }
            }
        }
    }

    /*print sparse matrix*/

    printf("\n\n==============\nSparse Matrix:\n==============");

    for (int i = 0; i < row; i++)

    {

        printf("\n");

        for (int j = 0; j < col; j++)

        {

            if (sparse_matrix[i][j] == 0) //for better output

            {

                printf(" %d ", sparse_matrix[i][j]);
            }

            else

                printf(" %d", sparse_matrix[i][j]);
        }
    }

    /*Transpose*/

    for (int i = 0; i < row; ++i)

    {

        for (int j = 0; j < col; ++j)

        {

            transposed_matrix[j][i] = sparse_matrix[i][j];
        }
    }

    printf("\n\n==================\nTransposed Matrix:\n==================");

    for (int i = 0; i < row_t; i++)

    {

        printf("\n");

        for (int j = 0; j < col_t; j++)

        {

            if (transposed_matrix[i][j] == 0) //for better output

            {

                printf(" %d ", transposed_matrix[i][j]);
            }

            else

                printf(" %d", transposed_matrix[i][j]);
        }
    }
}

int main()

{

    //transpose_print();
    printf("asd");

    return 0;
}
