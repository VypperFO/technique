/// \file main.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MD5.h"

int main(int argc, char* argv[]) {
  char messageSecret[] = "ac";
  char messageUser[3] = {0, 0};
  int isCracked = 0;

  int hex = 16;
  int dec = 10;
  char hashdaon[255] = "7f138a09169b250e9dcb378140907378";
  char hash[255] = "123abc";
  char* end;
  int hashDecInt;
  char hashDecChar[255];
 
  // Convert input hash hex to dec
  hashDecInt = strtol(hash, &end, hex); // Copy hex to dec into a int
  sprintf(hashDecChar, "%ld", hashDecInt); // Copy said int into a char array

  //printf("%s", hashDecChar);

  MD5_CTX context;
  MD5Init(&context);

  printf("Message: ");
  char message[255];
  scanf("%s", message);
  MD5Update(&context, (unsigned char*)message, (unsigned int)strlen(message));

  printf("MD5: ");
  unsigned char digest[16];
  MD5Final(&context, digest);
  for (unsigned char i = 0; i < 16; i++)
    printf("%c", digest[i]);

  MD5_CTX context2;
  MD5Init(&context2);

  MD5Update(&context2, (unsigned char *)hash, (unsigned int)strlen(hash));
  unsigned char digest2[16];
  MD5Final(&context2, digest2);
  //for (unsigned char i = 0; i < 16; i++)
    //printf("%02x", digest2[i]);

  if(1==2){
    printf("%s","salut");
  } else {
    printf("%s","non");
  }
  
  return 0;
}