#include <iostream>
#include <string>
#include <array>

struct Stone
{
    unsigned int stoneX;
    unsigned int stoneY;

    Stone(unsigned int X = 0, unsigned int Y = 0) : stoneX(X), stoneY(Y) {};
};

bool operator==(const Stone& stone1, const Stone& stone2)
{
    if (stone1.stoneX == stone2.stoneX && stone1.stoneY == stone2.stoneY)
        return true;
    else
        return false;
}
bool isSquare(const Stone& stone1, const Stone& stone2);

bool isInside(const Stone& stone1, const Stone& stone2, const Stone& stone3)
{
    if (!isSquare(stone1, stone2))
        return false;
    
    const int dX = stone2.stoneX - stone1.stoneX;
    const int dY = stone2.stoneY - stone1.stoneY;

    //int sX1, sY1;
    //int sX2, sY2;

    if (!dX)
    {
        const int sX1 = stone1.stoneX + dY;
        const int sY1 = stone1.stoneY;

        const int sX2 = stone2.stoneX + dY; // same Y as stone 1
        const int sY2 = stone2.stoneY;

        if (stone3.stoneX >= stone1.stoneX && stone3.stoneX <= sX1 && stone3.stoneY >= stone1.stoneY && stone3.stoneY <= sY2)
            return true;
        else
            return false;
    }
    else if (!dY)
    {
        const int sX1 = stone1.stoneX;
        const int sY1 = stone1.stoneY + dX;

        const int sX2 = stone2.stoneX; // same X as stone 1
        const int sY2 = stone2.stoneY + dX;

        if (stone3.stoneX >= stone1.stoneX && stone3.stoneX <= stone2.stoneX && stone3.stoneY >= stone1.stoneY && stone3.stoneY <= sY2)
            return true;
        else
            return false;
    }
    else
    {/*
        sX1 = stone1.stoneX;
        sY1 = stone2.stoneY;

        sX2 = stone2.stoneX;
        sY2 = stone1.stoneY;
*/
        if (stone3.stoneX >= stone1.stoneX && stone3.stoneX <= stone2.stoneX && stone3.stoneY >= stone1.stoneY && stone3.stoneY <= stone2.stoneY)
            return true;
        else
            return false;
    }

}

bool isSquare(const Stone& stone1, const Stone& stone2)
{
    if (stone1 == stone2)
        return false;
    
    const int dX = stone2.stoneX - stone1.stoneX;
    const int dY = stone2.stoneY - stone1.stoneY;

    if (dX == 0 || dY == 0)
        return true;
    else if (!(dX - dY))
        return false;
}

int main()
{
    
    return 0;
}