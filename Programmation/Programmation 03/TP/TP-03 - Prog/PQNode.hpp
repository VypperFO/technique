/// @file PQNode.hpp
/// @brief Classe PQNode relier a la priority queue
/// @author Felix-Olivier Latulippe felixlatulip@gmail.com

template <typename T>

/// @class PQNode
/// @brief PQNode de la classe priority queue
/// @tparam T
class PQNode
{
public:
  size_t priority; ///< Numero de prioriter
  T data;          ///< Donnee a ajouter dans le noeud
  PQNode<T> *next; ///< le prochain noeud

  PQNode(size_t priority, T data = nullptr, PQNode<T> *next = nullptr)
  {
    this->priority = priority;
    this->data = data;
    this->next = next;
  }
};