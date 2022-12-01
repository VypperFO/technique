#include "HuffmanNode.hpp"

template <typename T>

class PQNode
{
public:
  size_t priority;
  PQNode<T> *next;
  T *data;

  // Constructeur TODO
  PQNode(size_t priority, PQNode<T> *next = nullptr, T *data = nullptr)
  {
    this->data = data;
    this->next = next;
    this->priority = priority;
  }
};