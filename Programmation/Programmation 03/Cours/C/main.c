#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
  int mdpUser = 0;
  int mdp = 1234;


  while(mdpUser != mdp) {
    printf("Mot de passe: ");
    scanf("%d", &mdpUser);
    printf("Password incorrect");
  }
  printf("Logged in");

  return 0;
}