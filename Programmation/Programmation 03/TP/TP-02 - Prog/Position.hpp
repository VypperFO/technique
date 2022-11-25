#include <stdlib.h>
class Position
{

public:
    size_t x;
    size_t y;
    bool dir[4];

    Position(size_t x, size_t y, bool dir[4])
    {
        this->x = x;
        this->y = y;

        for (size_t i = 0; i < 4; i++)
        {
            dir[i] = false;
        }
    }
};