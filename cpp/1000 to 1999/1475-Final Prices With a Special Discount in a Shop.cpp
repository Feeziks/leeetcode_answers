#include <vector>

class Solution
{
public:
  std::vector<int> finalPrices(std::vector<int> &prices)
  {
    //return finalPricesSpeed(prices);
    return finalPricesMem(prices);
  }

  std::vector<int> finalPricesMem(std::vector<int> &prices)
  {
    for(int i = 0; i < prices.size(); i++)
    {
      for(int j = i + 1; j < prices.size(); j++)
      {
        if(prices[j] <= prices[i])
        {
          prices[i] -= prices[j];
          break;
        }
      }
    }
    return prices;
  }

  std::vector<int> finalPricesSpeed(const std::vector<int>& prices)
  {
    std::vector<int> ret(prices);
    for(int i = 0; i < prices.size(); i++)
    {
      for(int j = i + 1; j < prices.size(); j++)
      {
        if(prices[j] <= prices[i])
        {
          ret[i] -= prices[j];
          break;
        }
      }
    }
    return ret;
  }
};