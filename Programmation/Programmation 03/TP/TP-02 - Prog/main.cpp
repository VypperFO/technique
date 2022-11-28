#include "Application.hpp"
#include "MazeSolver.hpp"
//#include "Stack.hpp"
//#include "Position.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Application::getInstance()->addWindow(new MazeSolver(new Maze(2)));
	Application::getInstance()->start();

	return 0;
}
