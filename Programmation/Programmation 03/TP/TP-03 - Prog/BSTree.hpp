#include <cstdlib>
#include <cstddef>
#include <queue>
#include <iostream>
#include "DLNode.hpp"

using namespace std;

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
        node->left = new DLNode<T>(data);
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
        node->right = new DLNode<T>(data);
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
      return true;
  }

  void prefiTraversal(DLNode<T> *node, queue<T> *traversalQueue)
  {
    traversalQueue->push(node->data);
    if (node->left)
    {
      infixTraversal(node->left, traversalQueue);
    }

    if (node->right)
    {
      infixTraversal(node->right, traversalQueue);
    }
  }

  void infixTraversal(DLNode<T> *node, queue<T> *traversalQueue)
  {
    if (node->left)
    {
      infixTraversal(node->left, traversalQueue);
    }
    traversalQueue->push(node->data);

    if (node->right)
    {
      infixTraversal(node->right, traversalQueue);
    }
  }

  void postfixTraversal(DLNode<T> *node, queue<T> *traversalQueue)
  {
    if (node->left)
    {
      postfixTraversal(node->left, traversalQueue);
    }

    if (node->right)
    {
      infixTraversal(node->right, traversalQueue);
    }
    traversalQueue->push(node->data);
  }

  void timber(DLNode<T> *node)
  {
    if (node->left)
    {
      timber(node->left);
      delete node->left;
    }

    if (node->right)
    {
      timber(node->right);
      delete node->right;
    }
  }

public:
  BSTree()
  {
    root = nullptr;
    count = 0;
  }

  ~BSTree()
  {
    if (root)
    {
      timber(root);
      delete root;
    }
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
      return false;
    }
  }

  queue<T> *prefixTraversal()
  {
    if (root)
    {
      queue<T> *traversalQueue = new queue<T>();
      prefixTraversal(root, traversalQueue);
      return traversalQueue;
    }
    return nullptr;
  }

  queue<T> *infixTraversal()
  {
    if (root)
    {
      queue<T> *traversalQueue = new queue<T>();
      infixTraversal(root, traversalQueue);
      return traversalQueue;
    }
    return nullptr;
  }
  queue<T> *postfixTraversal()
  {
    if (root)
    {
      queue<T> *traversalQueue = new queue<T>();
      postfixTraversal(root, traversalQueue);
      return traversalQueue;
    }
    return nullptr;
  }

  queue<T> *breathfirstTraversal()
  {
    if (root)
    {
      queue<T> *traversalQueue = new queue<T>();
      queue<DLNode<T> *> *breathfirstQueue = new queue<Dlnode<T> *>();
      breathfirstQueue->push(root);
      while (!breathfirstQueue.empty())
      {
        if (breathfirstqueue.front()->left)
        {
          breathfirstQueue.push(breathfirstQueue.front()->left);
        }
        if (breathfirstqueue.front()->right)
        {
          breathfirstQueue.push(breathfirstQueue.front()->right);
        }
        traversalQueue->push(breathfirstQueue.front()->data);
        breathfirstQueue.pop()
      }
      return traversalQueue;
    }
    return nullptr;
  }

  /*
  void add(T data){
      if (root){
          DLNode<T> *squirrel = root;
          while (squirrel){

              if (data < squirrel->data){
                  if (squirrel->left){
                      squirrel = squirrel->left;
                  }
                  else{
                      squirrel->left = new DLNode<T>(data);
                      squirrel=nullptr;
                      count++;
                  }
              }
              else if (data > squirrel->data){
                  if (squirrel->right){
                      squirrel = squirrel->right;
                  }
                  else{
                      squirrel->right = new DLNode<T>(data);
                      squirrel=nullptr;
                      count++;
                  }
              } else {
                  squirrel = nullptr;
              }
          }
      }
      else{
          root = new DLNode<T>(data);
          count++;
      }
  }


  bool search(T data){
       if (root){
          DLNode<T> *squirrel = root;
          while (squirrel){

              if (data < squirrel->data){
                  if (squirrel->left){
                      squirrel = squirrel->left;
                  }
                  else{
                      return false;
                  }
              }
              else if (data > squirrel->data){
                  if (squirrel->right){
                      squirrel = squirrel->right;
                  }
                  else{
                      return false;
                  }
              } else {
                  return true;
              }
          }
      }
      else{
         return false;
      }
  }
*/
};