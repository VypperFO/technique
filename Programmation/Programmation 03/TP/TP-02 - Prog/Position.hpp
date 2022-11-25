#include <stdlib.h>
class Position
{

public:
    size_t x;
    size_t y;
    bool dir[4] = {false, false, false, false};

    Position(size_t x, size_t y)
    {
        this->x = x;
        this->y = y;
    }

    void setDir(bool direction[])
    {
        dir = direction;
    }
};