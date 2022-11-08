#include <stdlib.h>

struct ArrayStack
{
  int length;
  int sp;
  int *ss;
};

void ArrayStackInit(struct ArrayStack *arrayStack, int length)
{
  arrayStack->sp = 0;
  arrayStack->length = length;
  arrayStack->ss = malloc(sizeof(int) * length);
}

void arrayStackFree(struct ArrayStack *arrayStack)
{
  free(arrayStack->ss);
}

void push(int data, struct ArrayStack *arrayStack)
{
  if (arrayStack->sp < arrayStack->length)
  {
    arrayStack->ss[arrayStack->sp++] = data;
  }
}

void pop(struct ArrayStack *arrayStack)
{
  if (arrayStack->sp < arrayStack->length)
  {
    return -1;
  }
  return arrayStack->ss[arrayStack->sp--];
}