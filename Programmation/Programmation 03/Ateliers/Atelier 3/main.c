/// \file main.c

#include <stdio.h>
#include <string.h>

#include "MD5.h"

int main(int argc, char* argv[]) {
  char nbHasher[255] = "7f138a09169b250e9dcb378140907378";
  int isCracked = 0;

  MD5_CTX context;
  MD5Init(&context);

  printf("Message: ");
  char message[255];
  //scanf("%s", message);
  MD5Update(&context, (unsigned char*)message, (unsigned int)strlen(message));

  //printf("MD5: ");
  unsigned char digest[16];
  MD5Final(&context, digest);
  //for (unsigned char i = 0; i < 16; i++)
  //printf("%02x", digest[i]);

  //while(isCracked != 1){
    char mdp[3];
    for (int i = 0; i < 3; i++)
    {
      printf("2");
    }
    
  //}
  

  return 0;
}