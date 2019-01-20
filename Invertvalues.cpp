#include <vector>

std::vector<int> invert(std::vector<int> values)
{
    std::vector<int> temp(values.size());
    for (int i = 0; i < values.size(); ++i)
    {
        temp[i] = ((values[i]-1) ^ 0xFFFFFFFF);
    }
    return temp;
}