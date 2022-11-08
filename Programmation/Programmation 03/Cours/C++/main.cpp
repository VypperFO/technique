///\file main.cpp
///\author Patrick Singcaster (singcaster@clogik.io)

///\brief Fonction principale.
///\param argc Nombre d'arguments.
///\param argv Arguments.
///\return Code de fin.

#include <iostream>
#include <string>
#include "ArrayStack.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  ArrayStack<double> pileEntiers(5);
  pileEntiers.push(42);

  cout << "salut" << endl;
  return 0;
}
