#include "SLNode.hpp"
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
  SLNode<T> *first;
  size_t count;

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

  void push(T data)
  {
    SLNode<T> *newNode = new SLNode<T>(data);
    newNode->next = first;
    first = newNode;
    count++;
  }

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

  void display()
  {
    SLNode<T> *ptr;

    if (first != nullptr)
    {
      ptr = first;
      cout << "Stack elements are: ";
      while (ptr != NULL)
      {
        cout << ptr->data << " ";
        ptr = ptr->next;
      }
      // cout << endl;
    }
  }

  /// @brief Compte
  /// @return Nombre de données
  size_t size()
  {
    return count;
  }
};