template <typename T>

class PQNode
{
public:
  size_t priority;
  T data;
  PQNode<T> *next;

  PQNode(size_t priority, T data = nullptr, PQNode<T> *next = nullptr)
  {
    this->priority = priority;
    this->data = data;
    this->next = next;
  }
};