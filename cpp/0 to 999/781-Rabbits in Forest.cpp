#include <unordered_map>
#include <vector>

class Solution
{
public:
  int numRabbits(vector<int>& answers)
  {
    std::unordered_map<int, int> numRabbitsColor;
    for(int i : answers)
    {
      numRabbitsColor[i]++;
    }
    int total = 0;
    for(const auto &color : numRabbitsColor)
    {
      total += std::ceil( (double)color.second / (color.first + 1) ) * (color.first + 1);
    }
    return total;
  }
};