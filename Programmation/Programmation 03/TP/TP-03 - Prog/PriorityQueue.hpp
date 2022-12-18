/// @file PriorityQueue.hpp
/// @brief Classe PriorityQueue et ces methodes
/// @author Felix-Olivier Latulippe felixlatulip@gmail.com

#include "PQNode.hpp"

template <typename T>

/// @class PriorityQueue
/// @brief Classe permettant d'implementer le Priority Queue
/// @tparam T
class PriorityQueue
{
  PQNode<T> *first; ///< Le premier noeud
  size_t count;     ///< Le nombre de noeuds

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

  /// @brief Permet d'ajouter un noeud ayant une donnee de type T dans la PriorityQueue
  /// @param data Donnee de type T
  /// @param priority Le numero de prioriter
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

  /// @brief Permet d'enlever un noeud de la PriorityQueue
  void pop()
  {
    if (first != nullptr)
    {
      PQNode<T> *tmp = first;
      first = first->next;
      delete tmp;
      count--;
    }
  }

  /// @brief Permet de savooir la donnee du noeud du devant
  /// @return La donnee de type T
  T front()
  {
    if (first)
    {
      return first->data;
    }
    return nullptr;
  }

  /// @brief Permet de savoir la prioriter du noeud de devant
  /// @return La prioriter du noeud de devant
  size_t frontPriority()
  {
    if (first)
    {
      return first->priority;
    }
    return -1;
  }

  /// @brief Permet de savoir la taille du PriorityQueue
  /// @return Le nombre de noeud
  size_t size()
  {
    return count;
  }
};