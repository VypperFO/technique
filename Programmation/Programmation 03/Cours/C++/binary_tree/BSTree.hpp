#include "DLNode.hpp"
#include <cstdlib>
template <typename T>

class BSTree
{
  DLNode<T> *root;
  size_t count;

  void add(T data, DLNode<T> *node)
  {
    if (data < node->data)
    {
      if (node->left)
      {
        add(data, node->left);
      }
      else
      {
        node->left = DLNode<T>(data);
        count++;
      }
    }
    else if (data > node->data)
    {
      if (node->right)
      {
        add(data, node->right);
      }
      else
      {
        node->right = DLNode<T>(data);
        count++;
      }
    }
  }

  bool search(T data, DLNode<T> *node)
  {
    if (data < node->data)
    {
      if (node->left)
      {
        return search(data, node->left);
      }
      else
      {
        return false;
      }
    }
    else if (data > node->data)
    {
      if (node->right)
      {
        return search(data, node->right);
      }
      else
      {
        return false;
      }
    }
    else
    {
      return true;
    }
  }

public:
  BSTree()
  {
    root = nullptr;
    count = 0;
  }

  void add(T data)
  {
    if (root)
    {
      add(data, root);
    }
    else
    {
      root = new DLNode<T>(data);
      count++;
    }
  }

  bool search(T data)
  {
    if (root)
    {
      search(data, root);
    }
    return false;
  }
  /*
  void add(T data)
  {
    if (root)
    {
      // Arbre non vide
      DLNode<T> *squirrel = root;
      while (squirrel)
      {
        // Gauche
        if (data < squirrel->data)
        {
          // Possede une branche
          if (squirrel->left)
          {
            squirrel = squirrel->left;
          }
          else
          {
            squirrel->left = new DLNode<T>(data);
            squirrel = nullptr;
            count++;
          }
        }
        // Droite
        else if (data > squirrel->data)
        {
          // Possede une branche
          if (squirrel->right)
          {
            squirrel = squirrel->right;
          }
          else
          {
            squirrel->right = new DLNode<T>(data);
            squirrel = nullptr;
            count++;
          }
        }
        else
        {
          squirrel = nullptr;
        }
      }
    }
    else
    {
      // Arbre vide
      root = new DLNode<T>(data);
    }
    count++;
  }

  bool search(T data)
  {
    if (root)
    {
      DLNode<T> *squirrel = root;

      while (squirrel)
      {
        // Gauche
        if (data < squirrel->data)
        {
          // Possede une branche
          if (squirrel->left)
          {
            squirrel = squirrel->left;
          }
          else
          {
            return false;
          }
        }
        // Droite
        else if (data > squirrel->data)
        {
          // Possede une branche
          if (squirrel->right)
          {
            squirrel = squirrel->right;
          }
          else
          {
            return false;
          }
        }
        else
        {
          return true;
        }
      }
    }
    else
    {
      return false;
    }
  }*/
};