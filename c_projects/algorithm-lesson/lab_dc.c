/*
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void print_matrix(int **array, int rows, int cols) //TRUE
{

	printf("\n");
	for (int i = 0; i < rows; i++)
	{
		printf("\n");
		for (int j = 0; j < cols; j++)
		{
			printf(" %d ", array[i][j]);
		}
	}
}

void set_matrix(int **array, int rows, int cols) //TRUE
{
	int i, j, k = 0;

	int arr[] = {1, 1, 1, 1, 1, 1,
				 0, 0, 0, 0, 0, 0,
				 1, 0, 0, 1, 0, 1,
				 1, 0, 1, 0, 0, 1,
				 0, 0, 0, 1, 1, 0,
				 1, 1, 1, 1, 1, 1};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = arr[k];
			k++;
		}
	}
}

int cell_counter(int **matrix, int i, int j, int row, int col) //TRUE
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

/*int *cell_groups(int **matrix, int row, int col, int queries_count) //TRUE

{
	int *groups;
	groups = malloc(1 * sizeof(int));
	int q_counter = 0;
	int max = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 1)
			{
				int size = cell_counter(matrix, i, j, row, col);
				printf("\nSize :  %d", size);
				groups = realloc(groups, (q_counter + 1) * sizeof(int));
				groups[q_counter] = size;
				printf("\nGrup index %d sayı  %d", q_counter, groups[q_counter]); //TRUE
				q_counter++;
			}
		}
	}

	for (int i = 0; i < q_counter; i++)
	{
		printf("\n CELL_GROUPS:  %d ", groups[i]);
	}

	return groups;
}*/

/*int *search_querie(int *queries, int *groups, int queries_count)
{
	int *result;
	result = malloc(queries_count * sizeof(int));
	int search_item, counter = 0;

	for (int i = 0; i < queries_count; i++)
	{
		counter = 0;
		search_item = queries[i];
		for (int j = 0; j < queries_count; j++)
		{
			if (queries[i] == groups[j])
			{
				counter++;
			}
		}
		result[i] = counter;
	}

	return result;
}*/

int *onesGroups(int grid_rows, int grid_columns, int **grid, int queries_count, int *queries, int *result_count)
{

	/*
	SECOND FUNCTION
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
				groups = realloc(groups, (q_counter + 1) * sizeof(int));
				groups[q_counter] = size;
				printf("\nGrup index %d sayı  %d", q_counter, groups[q_counter]); //TRUE
				q_counter++;
			}
		}
	}

	for (int i = 0; i < q_counter; i++)
	{
		printf("\n CELL_GROUPS:  %d ", groups[i]);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	THIRTH FUNCTION
	*/

	result_count = malloc(queries_count * sizeof(int));
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
		result_count[i] = counter;
		printf("\nic result : % d", result_count[i]);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return result_count;
}

int main(int argc, char **argv)
{

	int rows = 6;
	int cols = 6;
	int queries[] = {6, 1, 8, 2};

	int **grid;

	grid = malloc(rows * sizeof *grid);
	printf("\n");

	for (int i = 0; i < rows; i++)
	{
		grid[i] = malloc(cols * sizeof *grid[i]);
	}

	set_matrix(grid, 6, 6);

	print_matrix(grid, 6, 6);

	printf("\n");

	/*int *cell_group;
	cell_group = cell_groups(grid, 6, 6, 4);

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", cell_group[i]);
	}

	printf("\n");

	int *result;
	result = search_querie(queries, cell_group, 4);

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", result[i]);
	}*/

	printf("\n");
	printf("\n");

	int *res;
	//res = malloc(sizeof(int) * 4);

	res = onesGroups(rows, cols, grid, 4, queries, res);

	for (int i = 0; i < 4; i++)
	{
		printf("\ndis result %d ", res[i]);
	}

	return 0;
}
