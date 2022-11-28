#include "Application.hpp"
#include "MazeSolver.hpp"
//#include "Stack.hpp"
//#include "Position.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Application::getInstance()->addWindow(new MazeSolver(new Maze(3)));
	Application::getInstance()->start();

	// Position *pos01 = new Position(1, 4);

	// pos01->dir[1] = true;
	// pos01->dir[3] = true;

	return 0;
}
