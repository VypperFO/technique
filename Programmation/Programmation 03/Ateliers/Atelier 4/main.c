///\file main.c
///\brief Atelier 4
///\author Prénom Nom (adresse@courriel.com)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//#include "StringArrayStack.h"
#include "StringArrayQueue.h"

///\brief Déterminer s'il s'agit d'un opérateur.
///\param term Terme.
///\return S'il s'agit d'un opérateur.
bool isOperator(char *term)
{
  if (strcmp(*term, "(") == 0 || strcmp(term, ")") == 0 || strcmp(term, "+") == 0 || strcmp(term, "-") == 0 || strcmp(term, "*") == 0 || strcmp(term, "/") == 0 || strcmp(term, "%") == 0)
  {
    return true;
  }
  return false;
}

///\brief Obtention de la priorité d'un opérateur.
///\param op Opérateur.
///\return Priorité de l'opérateur.
unsigned char getPriority(char *op)
{
  if (isOperator(op))
  {
    return "t";
  }
}

///\brief Transformation d'une expression infixe en expression postfixe.
///\param infixExpression Expression infixe.
///\return Expression postfixe.
struct StringArrayQueue *infixToPostfix(struct StringArrayQueue *infixExpression)
{
  /// TODO: Implémentation.
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

  char myArg = "(";
  isOperator(&myArg);
  return 0;
}