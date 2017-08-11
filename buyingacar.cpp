#include <math.h>
class BuyCar
{

  public:
  static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

std::vector<int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
    int saving = 0;
    double actualPriceOld = log10(startPriceOld);
    double actualPriceNew = log10(startPriceNew);
    std::vector<int> result;

    int month = 0;
    while(saving+pow(10, actualPriceOld) < pow(10, actualPriceNew))
    {
        month++;
        saving = (saving) + savingperMonth;
        
        if (month%2 == 0)
        {
          percentLossByMonth += 0.5;
        }
        actualPriceOld = (actualPriceOld + log10(100.0-percentLossByMonth))-2;
        actualPriceNew = (actualPriceNew + log10(100.0-percentLossByMonth))-2;

    }
    
    result.push_back(month);
    result.push_back(saving+pow(10, actualPriceOld) - pow(10, actualPriceNew));
    return result;
}