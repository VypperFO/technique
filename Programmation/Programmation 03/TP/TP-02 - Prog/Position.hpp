///\file Position.hpp
///\brief Ce fichier contient l'implementation de la position/
///\author Felix-Olivier Latulippe (felixlatulip@gmail.com)

///\class Position
///\brief Classe de la position contenant les coordonnees et les chemins possibles.
class Position
{

public:
    int x;       ///< Position en axe X
    int y;       ///< Position en axe Y
    bool dir[4]; ///< Tableau indiquant les directions possible (nord, sud, est, ouest)

    Position(int x, int y)
    {
        this->x = x;
        this->y = y;

        for (unsigned char i = 0; i < 4; i++)
        {
            dir[i] = false;
        }
    }
};