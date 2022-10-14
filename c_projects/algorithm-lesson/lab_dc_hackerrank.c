#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char *ltrim(char *);
char *rtrim(char *);
char **split_string(char *);

int parse_int(char *);

/*
 * Complete the 'onesGroups' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY grid
 *  2. INTEGER_ARRAY queries
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int cell_counter(int **matrix, int i, int j, int row, int col) //etraftaki 1 leri sayar
{
    if (i < 0 || j < 0 || i >= row || j >= col)
        return 0;
    if (matrix[i][j] == 0)
        return 0;
    int size = 1;
    matrix[i][j] = 0;
    for (int r = i - 1; r <= i + 1; r++)
    {
        for (int c = j - 1; c <= j + 1; c++)
        {
            if (r == i || c == j)
            {
                size += cell_counter(matrix, r, c, row, col);
            }
        }
    }

    return size;
}

int *onesGroups(int grid_rows, int grid_columns, int **grid, int queries_count, int *queries, int *result_count)
{

    /*
    SECOND FUNCTION //grupları tutan array oluşturulur
    */
    int *groups;
    groups = malloc(1 * sizeof(int));
    int q_counter = 0;
    int max = 0;
    for (int i = 0; i < grid_rows; i++)
    {
        for (int j = 0; j < grid_columns; j++)
        {
            if (grid[i][j] == 1)
            {
                int size = cell_counter(grid, i, j, grid_rows, grid_columns);
                groups = realloc(groups, (q_counter + 1) * sizeof(int)); //grup sayısı kadar indekse sahip olmak için realloc
                groups[q_counter] = size;
                q_counter++;
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    THIRTH FUNCTION //queries te verilen gruplardan kaç adet olduğunu bulup sonucu yazdırır
    */

    *result_count = queries_count;

    int *result;
    result = malloc(queries_count * sizeof(int));
    int search_item, counter = 0;

    for (int i = 0; i < queries_count; i++)
    {
        counter = 0;
        search_item = queries[i];
        for (int j = 0; j < q_counter; j++)
        {
            if (queries[i] == groups[j])
            {
                counter++;
            }
        }
        result[i] = counter;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    return result;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int grid_rows = parse_int(ltrim(rtrim(readline())));

    int grid_columns = parse_int(ltrim(rtrim(readline())));

    int **grid = malloc(grid_rows * sizeof(int *));

    for (int i = 0; i < grid_rows; i++)
    {
        *(grid + i) = malloc(grid_columns * (sizeof(int)));

        char **grid_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < grid_columns; j++)
        {
            int grid_item = parse_int(*(grid_item_temp + j));

            *(*(grid + i) + j) = grid_item;
        }
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));

    int *queries = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++)
    {
        int queries_item = parse_int(ltrim(rtrim(readline())));

        *(queries + i) = queries_item;
    }

    int result_count;
    int *result = onesGroups(grid_rows, grid_columns, grid, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1)
        {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }

    return data;
}

char *ltrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    while (*str != '\0' && isspace(*str))
    {
        str++;
    }

    return str;
}

char *rtrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    char *end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char **split_string(char *str)
{
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char *) * ++spaces);

        if (!splits)
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char *str)
{
    char *endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    return value;
}
