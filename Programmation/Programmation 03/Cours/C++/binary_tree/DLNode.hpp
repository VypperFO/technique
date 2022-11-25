template <typename T>
class DLNode
{
public:
  T data;           ///< Donnee
  DLNode<T> *left;  ///< Branche de gauche
  DLNode<T> *right; ///< Branche de droite

  DLNode(T data, DLNode<T> *left = nullptr, DLNode<T> *right = nullptr)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};