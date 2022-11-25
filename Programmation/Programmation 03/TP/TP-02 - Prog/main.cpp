#include "Application.hpp"
#include "MazeSolver.hpp"
#include "Stack.hpp"
#include <iostream>
#include "Position.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	// Application::getInstance()->addWindow(new MazeSolver(new Maze(3)));
	// Application::getInstance()->start();
	bool arr[] = {false, false, true, true};
	Position *pos = new Position(1, 1, arr);

	cout << pos->dir[2] << endl;
	delete pos;
	return 0;
}
