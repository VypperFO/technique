#include "PQNode.hpp"

template <typename T>

class PriorityQueue
{
  T *first;
  size_t count;

public:
  PriorityQueue()
  {
    first = nullptr;
    count = 0;
  }
  void push(T data, size_t priority)
  {
  }

  void pop()
  {
  }

  T front()
  {
    return nullptr;
  }

  size_t frontPriority()
  {
    return nullptr;
  }

  size_t size()
  {
    return nullptr;
  }
};