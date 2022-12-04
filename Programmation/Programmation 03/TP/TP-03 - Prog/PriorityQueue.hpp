#include "PQNode.hpp"

template <typename T>

class PriorityQueue
{
  PQNode<T> *first;
  size_t count;

public:
  PriorityQueue()
  {
    first = nullptr;
    count = 0;
  }

  ~PriorityQueue()
  {
    for (size_t i = 0; i < count; i++)
    {
      pop();
    }
  }

  void push(T data, size_t priority)
  {
    PQNode<T> *tmp = new PQNode<T>(priority, data);
    PQNode<T> *rear;

    tmp->data = data;
    tmp->priority = priority;

    if (first == nullptr || priority <= first->priority)
    {
      tmp->next = first;
      first = tmp;
    }
    else
    {
      rear = first;
      while (rear->next != nullptr && rear->next->priority <= priority)
      {
        rear = rear->next;
      }

      tmp->next = rear->next;
      rear->next = tmp;
    }
    count++;
  }

  void pop()
  {
    PQNode<T> *tmp;

    if (first != nullptr)
    {
      tmp = first;
      first = first->next;
      delete (tmp);
      count--;
    }
  }

  T front()
  {
    if (first)
    {
      return first->data;
    }
    return nullptr;
  }

  size_t frontPriority()
  {
    if (first)
    {
      return first->priority;
    }
    return -1;
  }

  size_t size()
  {
    return count;
  }
};