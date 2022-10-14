#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes

void sortNumbers(int *num, int count);

void swap(int *nums, int i, int j);

//main function

int main(int argc, char *argv[])

{

 //declare the variables

 int *numbers;

 int count = 0, i = 0;

 char input[20] = {'i','n','.','t','x','t'};
 char output[20] = {'o','u','t','.','t','x','t'};

 FILE *fileIn, *fileOut;

 //allocate the default size of array to maximum of 100

 numbers = (int *)malloc(sizeof(int));

 //check the number of arguments at command line

 /*if (argc < 2)

 {

      printf("Please provide the input and output text file names as ./a.out name1 name2 \n");

      return 0;

 }

 //read the file names from command line

 else

 {

      sscanf(argv[1], "%s", input);

      sscanf(argv[2], "%s", output);

 }*/

 //open the files

 fileIn = fopen(input, "r");

 fileOut = fopen(output, "w");

 //condition to check whether the input file and output

 //file are able to open or not. If not print the error message

 if (fileIn == NULL)

 {

      printf("Input file %s cannot be opened.\n", input);

      return 0;

 }

 else if (fileOut == NULL)

 {

      printf("Output file %s cannot be opened. \n", output);

      return 0;

 }

 //read the data from the file

else
{
   while ( fscanf(fileIn, "%d", &numbers[i]) == 1 )
   {
      printf("%d\n", numbers[i]);
      fprintf(fileOut, "%d\n", numbers[i]);
      ++i;
      numbers = (int *)realloc(numbers,(i+1)*sizeof(int));
   }
}

 count = i;

 //close the files

 fclose(fileIn);



 printf("\n");

 //sort the elements in the array

 sortNumbers(numbers, count);

 fprintf(fileOut,"\nElements after sorting are: \n");

 printf("\nElements after sorting are: \n");

 //print the elements to the console and to the

 //output file

 for(i=0;i<count;i++)

 {

      fprintf(fileOut,"%d \n", numbers[i]);

      printf("%d \n", numbers[i]);

 }

 fclose(fileOut);

 return 0;

}

//sort algorithm using selection sort

void sortNumbers(int *num, int count)

{

 for (int i = 0; i < count; ++i)

 {

      int minIndex = i;

      for (int j = i + 1; j < count; ++j)

      {

          if(num[j]<num[minIndex])

               minIndex = j;

      }

      swap(num, minIndex, i);

 }   

}

//swap function

void swap(int *nums, int i, int j)

    {

 int temp = nums[i];

 nums[i] = nums[j];

 nums[j] = temp;

}
