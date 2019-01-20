#include <iostream>
#include <string>
#include <array>

std::array<int, 4> explode(const std::string &input)
{
    std::array<int, 4> tmp = {0, 0, 0, 0};
    unsigned int t = 0;
    unsigned int pos = 1;
    for (int i = input.size() - 1; i >= 0; --i)
    {
        
        if (input[i] != '.')
        {
            tmp[t] += (input[i] - 0x30) * pos;
            pos *= 10;
        }
        else
        {
            pos = 1;
            ++t;
        }
    }
    return tmp;
}

int main() {
  /*
   * Cheatsheet: how to read & write data from standard I/O
   * for (std::string line; std::getline(std::cin, line);) {
   *   std::cout << line << std::endl;
   * }
   */
  
  std::string Local_IP, Netmask, Remote_IP;
  std::cin >> Local_IP;
  auto x = explode(Local_IP);
std::cout << x[0] << ' ' << x[1]<< ' ' << x[2] << ' ' << x[3];
  
  
  return 0;
}