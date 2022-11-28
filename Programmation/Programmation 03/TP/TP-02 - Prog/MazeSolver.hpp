#ifndef MAZESOLVER_HPP
#define MAZESOLVER_HPP

#include "Maze.hpp"
#include "Window.hpp"
#include "Stack.hpp"
#include "Position.hpp"
#include <ctime>

///\class Classe du MazeSolver
///\brief Classe incluant un algorithme pour trouver le chemin du labyrinthe
class MazeSolver : public Window
{
private:
	Maze *maze;			   ///< Le labyrinthe
	Stack<Position> *path; ///< Stack du chemin

public:
	MazeSolver(Maze *maze)
	{
		this->maze = maze;
		path = new Stack<Position>(); ///< Pile du chemin
		srand(time(0));				  ///< Seed du random
		findEntrance();
	}

	~MazeSolver()
	{
		delete maze;
		delete path;
	}

	///\brief Méthode permettant d'effectuer un déplacement
	void onUpdate()
	{
		if (path->size() != 0)
		{
			int x = path->top()->x; ///< Coordonnée du nouveau "x"
			int y = path->top()->y; ///< Coordonnée du nouveau "y"
			int provenance = -1;	///< Provenance de la dernière position

			if (nbDirection(path->top()) == 1)
			{
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

				pushPosition(provenance, x, y);
			}
			else if (nbDirection(path->top()) > 1)
			{
				int empreuter = randomDirection(path->top()); ///< Position aléatoire à empreuter

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

				pushPosition(provenance, x, y);
			}
			else if (nbDirection(path->top()) == 0 /* && maze->getSquare(path->top()->x, path->top()->y) != Square::EXIT*/)
			{
				path->pop();
			}
		}
	}

	///\brief Méthode d'affichage du labyrinthe et de la position actuelle
	void onRefresh()
	{
		for (unsigned char y = 0; y < 53; y++)
		{
			for (unsigned char x = 0; x < 53; x++)
			{
				drawSquare(maze->getSquare(x, y), x, y);
			}
		}

		if (path->size() != 0)
		{
			drawSquare(Square::PATH, path->top()->x, path->top()->y);
		}
	}

	///\brief Méthode pour trouver l'entrer du labyrinthe
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

	///\brief Méthode pour savoir le nombre de direction possible
	///\param pos Position actuelle en paramètre
	///\return Retourne le nombre de direction possible
	int nbDirection(Position *pos)
	{
		int counter = 0; ///< Compteur du nombre de direction

		for (size_t i = 0; i < 4; i++)
		{
			if (pos->dir[i])
			{
				counter++;
			}
		}

		return counter;
	}

	///\brief Méthode pour savoir les prochaine directions possibles
	///\param pos La position actuelle
	///\return Retourne une position avec les directions possibles
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

	///\brief Méthode pour choisir une diretion aléatoire
	///\param pos Position actuelle
	///\return Retourne une direction aléatoire
	int randomDirection(Position *pos)
	{
		int random;	   ///< Un nombre aléatoire
		int index = 0; ///< Index de la direction aléatoire choisite
		bool found;	   ///< Boolean pour savoir si la direction est possible

		do
		{
			random = rand() % 4;

			if (pos->dir[random])
			{
				found = true;
				index = random;
			}
		} while (found != true);

		return index;
	}

	///\brief Méthode pour empiler une nouvelle direction
	///\param provenance La provenance de la position
	///\param x Le nouveau x
	///\param y Le nouveau y
	void pushPosition(int provenance, int x, int y)
	{
		Position *pos = new Position(x, y);
		possibleDirection(pos);
		pos->dir[provenance] = false;
		path->push(pos);
	}
};

#endif
