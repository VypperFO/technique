#ifndef MAZESOLVER_HPP
#define MAZESOLVER_HPP

#include "Maze.hpp"
#include "Window.hpp"
#include "Stack.hpp"
#include "Position.hpp"
#include <ctime>

/// TODO: Inclusions.

class MazeSolver : public Window
{
private:
	Maze *maze;
	Stack<Position> *path;
	/// TODO: Déclarations.

public:
	MazeSolver(Maze *maze)
	{
		this->maze = maze;
		path = new Stack<Position>();
		findEntrance();
		/// TODO: Instanciations.
	}

	~MazeSolver()
	{
		/// TODO: Libérations.
		delete maze;
		delete path;
	}

	void onUpdate()
	{
		/// TODO: Avancer d'un pas.
		int x = path->top()->x;
		int y = path->top()->y;

		if (nbDirection(path->top()) == 1)
		{
			cout << "1" << endl;
			int provenance = -1;

			if (path->top()->dir[0])
			{
				y++;
				provenance = 1;
				path->top()->dir[0] = false;
			}
			else if (path->top()->dir[1])
			{
				y--;
				provenance = 0;
				path->top()->dir[1] = false;
			}
			else if (path->top()->dir[2])
			{
				x--;
				provenance = 3;
				path->top()->dir[2] = false;
			}
			else if (path->top()->dir[3])
			{
				x++;
				provenance = 2;
				path->top()->dir[3] = false;
			}

			Position *pos = new Position(x, y);
			possibleDirection(pos);
			pos->dir[provenance] = false;
			path->push(pos);
		}
		else if (nbDirection(path->top()) > 1)
		{
			cout << "plus de 1" << endl;

			int provenance = -1;
			int empreuter = randomDirection(path->top());

			switch (empreuter)
			{
			case 0:
				y++;
				provenance = 1;
				path->top()->dir[0] = false;
				break;
			case 1:
				y--;
				provenance = 0;
				path->top()->dir[1] = false;
				break;
			case 2:
				x--;
				provenance = 3;
				path->top()->dir[2] = false;
				break;
			case 3:
				x++;
				provenance = 2;
				path->top()->dir[3] = false;
				break;
			default:
				cout << "Erreur" << endl;
				break;
			}

			Position *pos = new Position(x, y);
			possibleDirection(pos);
			pos->dir[provenance] = false;
			path->push(pos);
		}
		else if (nbDirection(path->top()) == 0 && maze->getSquare(path->top()->x, path->top()->y) != Square::EXIT)
		{
			path->pop();
		}

		else if (path->size() == 0)
		{
			cout << "Aucun chemin trouver" << endl;
		}
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

		drawSquare(Square::PATH, path->top()->x, path->top()->y);

		/// TODO: Afficher la position actuelle.
	}

	void findEntrance()
	{
		for (unsigned char y = 0; y < 53; y++)
		{
			for (unsigned char x = 0; x < 53; x++)
			{
				if (maze->getSquare(x, y) == Square::ENTRY)
				{
					Position *pos = new Position(x, y);
					possibleDirection(pos);
					path->push(pos);
				}
			}
		}
	}

	int nbDirection(Position *pos)
	{
		int counter = 0;

		for (size_t i = 0; i < 4; i++)
		{
			if (pos->dir[i])
			{
				counter++;
			}
		}

		return counter;
	}

	Position *possibleDirection(Position *pos)
	{
		if (maze->getSquare(pos->x, pos->y + 1) == Square::WAY || maze->getSquare(pos->x, pos->y + 1) == Square::EXIT)
		{
			pos->dir[0] = true;
		}
		if (maze->getSquare(pos->x, pos->y - 1) == Square::WAY || maze->getSquare(pos->x, pos->y - 1) == Square::EXIT)
		{
			pos->dir[1] = true;
		}
		if (maze->getSquare(pos->x - 1, pos->y) == Square::WAY || maze->getSquare(pos->x - 1, pos->y) == Square::EXIT)
		{
			pos->dir[2] = true;
		}
		if (maze->getSquare(pos->x + 1, pos->y) == Square::WAY || maze->getSquare(pos->x + 1, pos->y) == Square::EXIT)
		{
			pos->dir[3] = true;
		}

		return pos;
	}

	int randomDirection(Position *pos)
	{
		int index = 0;
		bool found = false;
		int nbDeRandom = 0;

		do
		{
			srand(time(0));			 // une seule fois dans tout le programme
			int random = rand() % 4; // i = 0..3;
			nbDeRandom++;

			if (pos->dir[random])
			{
				found = true;
				index = random;
			}
		} while (found != true);
		cout << nbDeRandom << endl;

		return index;
	}
};

#endif
