#include <stdio.h>
#include <stdlib.h>
  
struct ArrayStack {
    int top;
    int lenght;
    int* array;
};
  
struct ArrayStack* init(int lenght)
{
    struct ArrayStack* stack = (struct ArrayStack*)malloc(sizeof(struct ArrayStack));
    stack->lenght = lenght;
    stack->top = -1;
    stack->array = (int*)malloc(stack->lenght * sizeof(int));
    return stack;
}
  
int isFull(struct ArrayStack* stack)
{
    return stack->top == stack->lenght - 1;
}
  
int isEmpty(struct ArrayStack* stack)
{
    return stack->top == -1;
}
  
void push(struct ArrayStack *stack, int item)
{
    if (!isFull(stack)) {
        stack -> array[++stack -> top] = item;
    }
}
 
int pop(struct ArrayStack* stack)
{
    if (isEmpty(stack)) {
        return -1;
    }
    return stack -> array[stack -> top--];
}
  
int peek(struct ArrayStack* stack)
{
    if (!isEmpty(stack)) {
    	return stack->array[stack->top];
    }
}