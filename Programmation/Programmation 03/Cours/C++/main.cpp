///\file main.cpp
///\author Patrick Singcaster (singcaster@clogik.io)

///\brief Fonction principale.
///\param argc Nombre d'arguments.
///\param argv Arguments.
///\return Code de fin.

#include <iostream>
#include <string>
#include "./binary_tree/BSTree.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  BSTree<int> *intSearchTree = new BSTree<int>();

  intSearchTree->add(42);
  intSearchTree->add(7);
  intSearchTree->add(666);
  intSearchTree->add(404);
  intSearchTree->add(-42);
  intSearchTree->add(42);

  if (intSearchTree->search(-42))
  {
    cout << "Present" << endl;
  }
  else
  {
    cout << "Absent" << endl;
  }

  delete intSearchTree;

  return 0;
}
