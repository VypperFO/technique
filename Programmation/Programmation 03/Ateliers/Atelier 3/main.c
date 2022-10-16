/// \file main.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MD5.h"

void convertToString(char* outStr, int length){
  char str[length];
  for(int i=0; i < length; ++i){
    outStr[i] = str[i];
  }
}

int main(int argc, char* argv[]) {
  char nbHasher[255] = "7f138a09169b250e9dcb378140907378";
  char messageSecret[] = "ac";
  char messageUser[] = {'a', 'b', 0};
  int cmpValue;
  int isCracked = 0;
  int lenght = 3;

  //MD5_CTX context;
  //MD5Init(&context);
  printf("Message: ");
  //char message[255];
  //scanf("%s", message);
  //MD5Update(&context, (unsigned char*)message, (unsigned int)strlen(message));
  //printf("MD5: ");
  //unsigned char digest[16];
  //MD5Final(&context, digest);
  //for (unsigned char i = 0; i < 16; i++)
  //printf("%02x", digest[i]);
  while (isCracked != 1)
  {
    cmpValue = strcmp(messageUser, messageSecret);
    if (cmpValue == 0)
    {
      printf("Pareil");
      isCracked = 1;
    } else {
      printf("pas pareil\n");
      for (size_t i = 0; i < 255; i++)
      {
        messageUser[i]++;
      }
      
    }
  }
  
  

  
  return 0;
}