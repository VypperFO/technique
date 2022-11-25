///\file Stack.hpp
///\brief Ce fichier contient l'implementation de la pile/
///\author Felix-Olivier Latulippe (felixlatulip@gmail.com)

#include "SLNode.hpp"
#include <iostream>

using namespace std;

template <typename T>

///\class Stack
///\brief Classe de la pile.
///\tparam T
class Stack
{
  SLNode<T> *first; ///< Le dessus de la pile
  size_t count;     ///< Le nombre de noeuds

public:
  Stack()
  {
    first = nullptr;
    count = 0;
  }

  ~Stack()
  {
    for (size_t i = 0; i < count; i++)
    {
      pop();
    }
  }

  ///\brief Methode pour empiler
  ///\param data La donnee a empiler
  void push(T *data)
  {
    SLNode<T> *newNode = new SLNode<T>(data); ///< Nouveau noeud
    newNode->next = first;
    first = newNode;
    count++;
  }

  ///\brief Methode pour depiler
  void pop()
  {
    if (first != nullptr)
    {
      first = first->next;
      count--;
      if (!count)
      {
        first = nullptr;
      }
    }
  }

  ///\brief Compte de la pile
  ///\return Nombre de données
  size_t size()
  {
    return count;
  }

  ///\brief Haut de la pile
  ///\return La donnee du haut de la pile
  T *top()
  {
    if (first != nullptr)
    {
      return first->data;
    }
  }

  ///\brief Methode pour afficher tout les elements de la pile
  void display()
  {
    SLNode<T> *ptr; ///< Pointeur du top

    if (first != nullptr)
    {
      ptr = first;
      cout << "Stack elements are: ";
      while (ptr != NULL)
      {
        cout << ptr->data << " ";
        ptr = ptr->next;
      }
      cout << endl;
    }
  }
};