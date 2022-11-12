///\file main.cpp
///\author Patrick Singcaster (singcaster@clogik.io)

///\brief Fonction principale.
///\param argc Nombre d'arguments.
///\param argv Arguments.
///\return Code de fin.

#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  Queue<int> *fileEntiers = new Queue<int>();
  fileEntiers->push(42);
  fileEntiers->push(32);
  fileEntiers->pop();
  fileEntiers->pop();

  delete fileEntiers;
  return 0;
}
