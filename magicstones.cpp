#include <iostream>
#include <string>
#include <vector>

struct Stone
{
    unsigned int stoneX;
    unsigned int stoneY;

    Stone(unsigned int X, unsigned int Y) : stoneX(X), stoneY(Y) {};
    Stone(const Stone& s) {stoneX = s.stoneX; stoneY = s.stoneY;};
    Stone(const Stone&&) = delete;
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
        const unsigned int sX1 = stone1.stoneX + dY;
        const unsigned intsY1 = stone1.stoneY;

        const unsigned int sX2 = stone2.stoneX + dY; // same Y as stone 1
        const unsigned int sY2 = stone2.stoneY;

        if (stone3.stoneX >= stone1.stoneX && stone3.stoneX <= sX1 && stone3.stoneY >= stone1.stoneY && stone3.stoneY <= sY2)
            return true;
        else
            return false;
    }
    else if (!dY)
    {
        const unsigned int sX1 = stone1.stoneX;
        const unsigned int sY1 = stone1.stoneY + dX;

        const unsigned int sX2 = stone2.stoneX; // same X as stone 1
        const unsigned int sY2 = stone2.stoneY + dX;

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

    if (dX == dY)
        return true;

    return false;
}

int silnia(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n > 1)
        return n * silnia(n - 1);
}

int main()
{
    unsigned int N;
    std::cin >> N;
    std::vector<Stone> stoneVect;

    for (int i = 0; i < N; ++i)
    {
        Stone s(0, 0);
        std::cin >> s.stoneX >> s.stoneY;
        stoneVect.push_back(s);
    }

    for (unsigned int i = 0; i < silnia(N - 1); ++i)
    {

    }
    
    return 0;
}