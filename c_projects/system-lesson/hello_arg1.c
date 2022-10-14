/******************************************************************************
* FILE: hello_arg1.c
* DESCRIPTION:
*   A "hello world" Pthreads program which demonstrates one safe way
*   to pass arguments to threads during thread creation.
* AUTHOR: Blaise Barney
* LAST REVISED: 08/04/15
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 8

char *messages[NUM_THREADS];

void *printHello(void *threadid)
{
  int taskid;

  sleep(1);
  taskid = *((int *)threadid);
  printf("Thread %d: %s\n", taskid, messages[taskid]);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int taskids[NUM_THREADS];
  int rc, t;

  messages[0] = "English: Hello World!";
  messages[1] = "French: Bonjour, le monde!";
  messages[2] = "Spanish: Hola al mundo";
  messages[3] = "Klingon: Nuq neH!";
  messages[4] = "German: Guten Tag, Welt!";
  messages[5] = "Russian: Zdravstvuyte, mir!";
  messages[6] = "Japan: Sekai e konnichiwa!";
  messages[7] = "Latin: Orbis, te saluto!";

  for (t = 0; t < NUM_THREADS; t++)
  {
    taskids[t] = t;
    printf("Creating thread %d\n", t);
    rc = pthread_create(&threads[t], NULL, printHello, (void *)&taskids[t]);
    if (rc)
    {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
    pthread_join(threads[t], NULL);
  }

  /*for (t = 0; t < NUM_THREADS; t++)
  {
    pthread_join(threads[t], NULL);
  }*/

  pthread_exit(NULL);
}
