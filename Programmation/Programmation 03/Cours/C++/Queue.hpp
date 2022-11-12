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

  void push(T data)
  {
    if (last) // Last == nullptr **ASK WHAT THIS DOES**
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
      SLNode<T> *toDelete = first; // Temp var points to the first
      first = toDelete->next;      // First equals the pointer of todelete.next (first)
      delete toDelete;             // free toDelete
      count--;                     // Decrement the total count
      if (!count)                  // **ASK WHAT THIS DOES**
        last = nullptr;
    }
  }

  T front()
  {
    if (first) // **ASK WHAT THIS DOES**
    {
      return first->data;
    }
    return "";
  }

  T back()
  {
  }
  size_t size()
  {
  }
};