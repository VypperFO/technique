#include "SLNode.hpp"

template <typename T>
class Queue
{
  SLNode<T> *last;
  SLNode<T> *first;
  size_t count;

public:
  Queue()
  {
    first = last = nullptr;
    count = 0;
  }

  ~Queue()
  {
    for (size_t i = 0; i < count; i++)
    {
      pop();
    }
  }

  void push(T data)
  {
    if (last)
    {
      last->next = new SLNode<T>(data);
      last = last->next;
    }
    else
    {
      first = last = new SLNode<T>(data);
    }
    count++;
  }

  void pop()
  {
    if (last) // Last == nullptr **ASK WHAT THIS DOES**
    {
      SLNode<T> *toDelete = first; // Temp var points to the first element
      first = toDelete->next;      // First equals the pointer of todelete.next (first)
      delete toDelete;             // free toDelete
      count--;                     // Decrement the total count
      if (!count)                  // **ASK WHAT THIS DOES**
        last = nullptr;
    }
  }

  /// @brief Devant
  /// @return Donnée au devant
  T front()
  {
    if (first) // **ASK WHAT THIS DOES**
      return first->data;
    return NULL;
  }

  /// @brief Derrière
  /// @return Donnée au derrière
  T back()
  {
    if (last)
      return last->data;
    return NULL;
  }

  /// @brief Compte
  /// @return Nombre de données
  size_t size()
  {
    size_t counter = 0;
    SLNode<T> *runner = first;
    while (runner)
    {
      counter++;
      runner = runner->next;
    }

    return counter;
  }
};