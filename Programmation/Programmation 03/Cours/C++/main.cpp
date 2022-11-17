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

struct Skydiver
{
  string firstName, lastName;

  Skydiver(string firstName, string lastName)
  {
    this->firstName = firstName;
    this->lastName = lastName;
  }
};

int main(int argc, char *argv[])
{
  Skydiver *skydiverA = new Skydiver("patrick", "nigger");
  Skydiver *skydiverB = new Skydiver("patrick", "lebeaunigger");

  Queue<Skydiver *> *skydiverQueue = new Queue<Skydiver *>();

  skydiverQueue->push(skydiverA);
  skydiverQueue->push(skydiverB);

  cout << "Devant: " << skydiverQueue->front()->firstName << " " << skydiverQueue->front()->lastName << endl;
  cout << "Derriere: " << skydiverQueue->back()->firstName << " " << skydiverQueue->back()->lastName << endl;
  cout << "Compte: " << skydiverQueue->size() << endl;
  cout << "Defiler" << endl;
  skydiverQueue->pop();
  cout << "Devant: " << skydiverQueue->front()->firstName << " " << skydiverQueue->front()->lastName << endl;
  cout << "Derriere: " << skydiverQueue->back()->firstName << " " << skydiverQueue->back()->lastName << endl;
  cout << "Compte: " << skydiverQueue->size() << endl;

  delete skydiverQueue;

  delete skydiverA;
  delete skydiverB;
  
  return 0;
}
