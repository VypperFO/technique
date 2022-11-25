#ifndef MAZESOLVER_HPP
#define MAZESOLVER_HPP

#include "Maze.hpp"
#include "Window.hpp"
/// TODO: Inclusions.

class MazeSolver : public Window
{
private:
	Maze *maze;
	/// TODO: Déclarations.

public:
	MazeSolver(Maze *maze)
	{
		this->maze = maze;
		/// TODO: Instanciations.
	}

	~MazeSolver()
	{
		/// TODO: Libérations.
		delete maze;
	}

	void onUpdate()
	{
		/// TODO: Avancer d'un pas.
	}

	void onRefresh()
	{
		for (unsigned char y = 0; y < 53; y++)
		{
			for (unsigned char x = 0; x < 53; x++)
			{
				drawSquare(maze->getSquare(x, y), x, y);
			}
		}

		//drawSquare(Square::PATH, path->top()->x, path->top()->y);

		/// TODO: Afficher la position actuelle.
	}
};

#endif
