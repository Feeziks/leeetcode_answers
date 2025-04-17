#include <map>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countPairs(vector<int>& nums, int k)
  {
    std::map<int, std::vector<int>> valsToIdxs;
    for(size_t i = 0; i < nums.size(); i++)
    {
      valsToIdxs[nums[i]].push_back(i);
    }

    int ret = 0;
    for(auto it = valsToIdxs.begin(); it != valsToIdxs.end(); it++)
    {
      for(size_t i = 0; i < it->second.size() - 1; i++)
      {
        for(size_t j = i + 1; j < it->second.size(); j++)
        {
          if(0 == it->second[i] * it->second[j] % k)
          {
            ret++;
          }
        }
      }
    }
    return ret;
  }
};