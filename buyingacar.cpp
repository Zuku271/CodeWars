#include <math.h>
class BuyCar
{

  public:
  static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

std::vector<int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
    int saving = 0;
    double actualPriceOld = startPriceOld;
    double actualPriceNew = startPriceNew;
    std::vector<int> result;

    int month = 0;
    while(saving+actualPriceOld < actualPriceNew)
    {
        month += 1;
        saving += savingperMonth;
        
        if (month%2 == 0)
        {
          percentLossByMonth += 0.5;
        }
        actualPriceOld = ((100.0-percentLossByMonth) * actualPriceOld)/100.0;
        actualPriceNew = ((100.0-percentLossByMonth) * actualPriceNew)/100.0;
    }
    
    result.push_back(month);
    result.push_back(round(saving+actualPriceOld - actualPriceNew));
    return result;
}