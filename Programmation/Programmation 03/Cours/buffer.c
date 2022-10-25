#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int main(){
  char buffer[15];
  bool isValid = false;

  printf("Passphrase: ");
  scanf("%s", buffer);

  if(strcmp(buffer, "salut")){
    isValid = true;
  }

}