#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1;
#define false 0;

void histogram(int numbers[], int length, int n)
{

	bool finished = true;
	for (int i = 0; i < length; i++)
		if (numbers[i] - n > 0)
			finished = false;

	if (finished)
		return;
	else
	{

		histogram(numbers, length, n + 1);

		for (int i = 0; i < length; i++)
		{

			int number = numbers[i] - n;
			if (number > 0)
				printf("+ ");
			else
				printf("  ");
		}

		printf("\n");
	}
}

int main(void)
{

	int number, i = 0;
	int numbers[10];
	printf("Enter positive array values (-1 to finish) :\n");
	
	while (number != -1)
	{
		scanf("%d", &number);
		numbers[i] = number;
		i++;
		
	}

	

	int length = sizeof(numbers) / sizeof(int);

	printf("HISTOGRAM:\n");
	histogram(numbers, length, 0);
	
	for (int i = 0; numbers[i] != -1; i++)
	{
		printf("%d ", numbers[i]);
	}

	return 0;
}
