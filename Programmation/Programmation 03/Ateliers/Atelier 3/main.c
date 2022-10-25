/// \file main.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MD5.h"

void bruteforce()
{
  char messageSecret[] = "bbc";
  char messageUser[] = {'a', 'a', 'a', 0};
  int isCracked = 0;

  int hex = 16;
  int dec = 10;
  char hashdaon[255] = "7f138a09169b250e9dcb378140907378";
  char hash[255] = "123abc";
  char *end;
  int hashDecInt;
  char hashDecChar[255];

  // Convert input hash hex to dec
  hashDecInt = strtol(hash, &end, hex);    // Copy hex to dec into a int
  sprintf(hashDecChar, "%ld", hashDecInt); // Copy said int into a char array

  // printf("%s", hashDecChar);

  MD5_CTX context;
  MD5Init(&context);

  // printf("Message: ");
  char message[255];
  // scanf("%s", message);
  MD5Update(&context, (unsigned char *)message, (unsigned int)strlen(message));

  printf("MD5: ");
  unsigned char digest[16];
  MD5Final(&context, digest);
  // for (unsigned char i = 0; i < 16; i++)
  // printf("%c", digest[i]);

  MD5_CTX context2;
  MD5Init(&context2);

  MD5Update(&context2, (unsigned char *)hash, (unsigned int)strlen(hash));
  unsigned char digest2[16];
  MD5Final(&context2, digest2);
  // for (unsigned char i = 0; i < 16; i++)
  // printf("%02x", digest2[i]);

  for (size_t i = 0; i < strlen(messageUser); i++)
  {
    for (size_t j = 0; j < 255; j++)
    {
      if (strcmp(messageSecret, messageUser) != 0)
      {
        messageUser[i]++;
        printf("%s\n", messageUser);
      }
      else
      {
        printf("trouver\n");
        isCracked = 1;
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int charMin = 1;
  int charMax = 10;

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
  /**

      if (argc > 2)
      {
        if (strcmp(argv[1], "-c") == 0)
        {
          // bruteforce();
        }
        else
        {
          printf("No arguments passed through command line.\n");
        }
      }
  */
  return 0;
}