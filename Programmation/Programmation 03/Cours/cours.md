# Programmation 3

## Tableau

```C
int tabEntier[5];
int* tabEntiers = malloc(5 * sizeOf(int));

tabEntiers[2] = 42;

free(tabEntiers);
```

## Chaines de caracteres

Tableau de carateres se terminant par la valeur 0\

```C
char tabChar[5] = {'a', 'l', 'l', 'o', 0};

printf("%s", tabChar);

// -> allo
```

Fonction:

```C
#include <string.h>

size_t strlen(chaine);
void strcpy(destination, source);
int strcmp(chaineA, chaineB);
stringf(resultat, format, données...);
```

-   < 0 chaineA vient avant chaineB en forme ASCII
-   == 0 identique
-   > 0 chaineA vient apres chaineB en forme ASCII

## Librairie

### Addition.c

```c
int add(int a, int b){
  return a + b;
}
```

Pour compiler:\
gcc -c ./Addtion.c\
ar -rcs ./libAddition.a ./Addition.o

### Addition.h

```c
int add(int a, int b);
```

### main.c

```c
int main(int argc, char* argv[]){
  int somme = add(40, 2);

  return 0;
}
```

Pour compiler:\
gcc ./main.c -o programme.exe -L. -lAddition

## La queue

-   Type: F.I.F.O
-   Acces: Devant (front), derierre (back)
-   Fonctionnalites:
-   -   Enfiler (push) (frontIndex + count++) % length ; (frontIndex + 1) % length; count--;
-   -   Depiler (pop)
-   -   Compte (size)
