#include <stdio.h>

struct StackArray
{
    int stackSize = 8;
    int stack[stackSize];
    int top = -1;

    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        if (top == stackSize)
            return 1;
        else
            return 0;
    }

    int peek()
    {
        return stack[top];
    }

    int pop()
    {
        int data;

        if (!isEmpty())
        {
            data = stack[top];
            top = top - 1;
            return data;
        }
        else
        {
            printf("Could not retrieve data, Stack is empty.\n");
        }
    }

    int push(int data)
    {

        if (!isFull())
        {
            top = top + 1;
            stack[top] = data;
        }
        else
        {
            printf("Could not insert data, Stack is full.\n");
        }
    }
};

int main()
{
    struct StackArray stackArray;

    // push items on to the stack
    stackArray.push(3);
    stackArray.push(5);
    stackArray.push(7);
    stackArray.push(17);

    printf("Element at top of the stack: %d\n", stackArray.peek());
    printf("Elements: \n");

    // print stack data
    while (!stackArray.isEmpty())
    {
        int data = stackArray.pop();
        printf("%d\n", data);
    }

    printf("Stack full: %s\n", stackArray.isFull() ? "true" : "false");
    printf("Stack empty: %s\n", stackArray.isEmpty() ? "true" : "false");
    return 0;
}