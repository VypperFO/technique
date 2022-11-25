#include "Application.hpp"
#include "MazeSolver.hpp"
#include "Stack.hpp"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	// Application::getInstance()->addWindow(new MazeSolver(new Maze(3)));
	// Application::getInstance()->start();

	Stack<int> *path = new Stack<int>();

	path->push(1);
	path->push(2);
	path->push(3);

	path->display();

	path->pop();
	path->pop();
	path->pop();

	path->display();

	return 0;
}
