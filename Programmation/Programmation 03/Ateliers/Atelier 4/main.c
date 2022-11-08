///\file main.c
///\brief Atelier 4
///\author Prénom Nom (adresse@courriel.com)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "ArrayStack.h"
#include "StringArrayQueue.h"

///\brief Déterminer s'il s'agit d'un opérateur.
///\param term Terme.
///\return S'il s'agit d'un opérateur.
bool isOperator(char *term)
{
  if (strcmp(term, "(") == 0 || strcmp(term, ")") == 0 || strcmp(term, "+") == 0 || strcmp(term, "-") == 0 || strcmp(term, "*") == 0 || strcmp(term, "/") == 0 || strcmp(term, "%") == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

///\brief Obtention de la priorité d'un opérateur.
///\param op Opérateur.
///\return Priorité de l'opérateur.
unsigned char getPriority(char *op)
{
  if (strcmp(op, "(") == 0 || strcmp(op, ")") == 0)
  {
    return (3);
  }
  else if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0)
  {
    return (2);
  }
  else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

///\brief Transformation d'une expression infixe en expression postfixe.
///\param infixExpression Expression infixe.
///\return Expression postfixe.
struct StringArrayQueue *infixToPostfix(struct StringArrayQueue *infixExpression)
{
  struct StringArrayQueue *postFixQueue;
  struct ArrayStack *opStack;

  StringArrayQueueInit(postFixQueue, 255);
  opStack = init(255);

  for (size_t i = 0; i < sizeof(infixExpression); i++)
  {
    char lastOP = StringArrayQueueFront(infixExpression);
    if (!isOperator(lastOP))
    {
      StringArrayQueuePush(postFixQueue, lastOP);
    }
    else if (lastOP == '(')
      push(opStack, lastOP);
    else if (lastOP == ')')
    {
      char op;
      do
      {
        op = pop(opStack);
        StringArrayQueuePush(postFixQueue, op);
      } while (op != '(');
    }
    else
    {
      while (getPriority(pop(opStack)) >= getPriority(peek(opStack)))
      {
        // StringArrayQueuePush();
      }
    }
  }
}

///\brief Calcul du résultat d'un expression postfixe.
///\param postfixExpression Expression postfixe.
///\return Résultat de l'expression.
int postfixToResult(struct StringArrayQueue *postfixExpression)
{
  /// TODO: Implémentation.
}

///\brief Fonction principale.
///\param argc Nombre d'arguments.
///\param argv Arguments.
///\return Code de fin de programme.
int main(int argc, char *argv[])
{
  struct StringArrayQueue infixExpression;
  StringArrayQueueInit(&infixExpression, 11);

  // 1 + 2 * (5 + 10) + 11
  StringArrayQueuePush(&infixExpression, "1");
  StringArrayQueuePush(&infixExpression, "+");
  StringArrayQueuePush(&infixExpression, "2");
  StringArrayQueuePush(&infixExpression, "*");
  StringArrayQueuePush(&infixExpression, "(");
  StringArrayQueuePush(&infixExpression, "5");
  StringArrayQueuePush(&infixExpression, "+");
  StringArrayQueuePush(&infixExpression, "10");
  StringArrayQueuePush(&infixExpression, ")");
  StringArrayQueuePush(&infixExpression, "+");
  StringArrayQueuePush(&infixExpression, "11");

  for (unsigned char i = 0; i < StringArrayQueueSize(&infixExpression); i++)
  {
    printf("%s", StringArrayQueueFront(&infixExpression));
    char *tmpFront = StringArrayQueueFront(&infixExpression);
    StringArrayQueuePop(&infixExpression);
    StringArrayQueuePush(&infixExpression, tmpFront);
  }
  /// TODO: Implémentation.

  return 0;
}