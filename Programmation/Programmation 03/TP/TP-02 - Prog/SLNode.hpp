///\file SLNode.hpp
///\brief Ce fichier contient l'implementation du SLNode
///\author Felix-Olivier Latulippe (felixlatulip@gmail.com)

template <typename T>

///\brief Classe du SLNode
///\tparam T
class SLNode
{
public:
  T *data;         ///< Donnee du noeud
  SLNode<T> *next; ///< Adresse du prochain noeud

  SLNode(T *data, SLNode<T> *next = nullptr)
  {
    this->data = data;
    this->next = next;
  }
};
