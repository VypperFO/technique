/// \file main.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MD5.h"

void bruteforce(char *messageSecret, int min, int max)
{
  int len = max - min;
  char messageUser[len];

  for (size_t i = 0; i < strlen(messageUser); i++)
  {
    for (size_t j = 0; j < 255; j++)
    {
      MD5_CTX context;
      MD5Init(&context);

      char message[255];
      MD5Update(&context, (unsigned char *)message, (unsigned int)strlen(message));

      unsigned char digest[16];
      MD5Final(&context, digest);
      if (strcmp(messageSecret, messageUser) != 0)
      {
        messageUser[i]++;
        printf("something");
      }
      else
      {
        printf("trouver\n");
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int charMin = 1;
  int charMax = 10;

  /*

    for (size_t i = 0; i < 5; i++)
    {
      if (strcmp(argv[i], "-l") == 0)
      {
        charMin = (int)argv[i + 1];
        printf("%d\n", charMin);
      }
      else if (strcmp(argv[i], "-h") == 0)
      {
        charMax = (int)argv[i + 1];
        printf("%d\n", charMax);
      }
      else
      {
        // printf("%d", charMin);
        // printf("%d", charMax);
        // printf("wassup");
      }
    }
  */
  if (argc > 2)
  {
    if (strcmp(argv[1], "-c") == 0)
    {
      bruteforce("12345", 1, 10);
    }
    else
    {
      printf("No arguments passed through command line.\n");
    }
  }

  return 0;
}