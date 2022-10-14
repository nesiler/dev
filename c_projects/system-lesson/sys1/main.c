#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void mycat(char **argv)
{

    char buf[BUFSIZ];
    sprintf(buf, "cat %s", argv[1]);
    system(buf);
}

void mygrep(char **argv)
{

    char buf[BUFSIZ];
    sprintf(buf, "grep %s %s", argv[1], argv[2]);
    system(buf);
}

/*char *count_letters(char *text)
{

    char result[BUFSIZ];
    int count = 0;
    char current = text[0];
    char last = text[0];
    char swap[10];
    char letter[10];

    for (int i = 0; i < sizeof(text) / sizeof(char); i++)
    {
        if (current == last)
        {
            count++;
            last = current;
            current = text[i + 1];
        }
        else
        {
            sprintf(swap, "%d", count);
            sprintf(letter, "%d", last);
            strcat(result, swap);
            strcat(result, letter);
        }
    }
    return *result;
}*/

int main(int argc, char **argv)
{

    char text[] = "aaaaa5bbbb44ccc333dd2222e11111";

    printf("Text: %s\n", text);

    printf("%ld", sizeof(text));

    char result[50];
    int count = 0;
    char swap[10];
    char letter[10];

    char current = text[0];
    char last = text[0];

    for (int i = 0; i <= sizeof(text); i++)
    {
        printf("i : %d\n", i);

        if (current == last)
        {
            last = text[i];
            current = text[i + 1];
            count++;
        }
        else
        {
            sprintf(swap, "%d", count);
            sprintf(letter, "%c", last);
            printf("else 3: %s \n", swap);
            printf("else 4: %s \n", letter);

            strcat(result, swap);
            strcat(result, letter);
            count = 1;
            last = text[i];
            current = text[i + 1];
        }
    }

    printf("%s\n", result);
}
