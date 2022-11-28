#include "Application.hpp"
#include "MazeSolver.hpp"
//#include "Stack.hpp"
//#include "Position.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Application::getInstance()->addWindow(new MazeSolver(new Maze(1)));
	Application::getInstance()->start();

	/*Position *pos01 = new Position(1, 4);
	Position *pos02 = new Position(2, 4);
	Position *pos03 = new Position(3, 4);

	pos01->dir[1] = true;
	pos02->dir[2] = true;
	pos03->dir[3] = true;

	Stack<Position> stack;

	stack.push(pos01);
	stack.push(pos02);
	stack.push(pos03);

	stack.display();
*/
	return 0;
}
