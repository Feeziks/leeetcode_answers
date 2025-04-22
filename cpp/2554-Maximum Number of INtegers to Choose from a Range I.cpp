#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int maxCount(vector<int>& banned, int n, int maxSum)
  {
    int ret = 0;
    std::sort(banned.begin(), banned.end());
    std::vector<int> legalValues;
    int bannedIdx = 0;
    for(int i = 1; i <= n; i++)
    {
      while(banned[bannedIdx] < i && bannedIdx < banned.size())
      {
        bannedIdx++;
      }
      if(bannedIdx >= banned.size() || banned[bannedIdx] != i)
      {
        legalValues.push_back(i);
      }
    }
    for(const auto val : legalValues)
    {
      std::cout << val << ", ";
    }
    std::cout <<"\n";
    return ret;
  }
};