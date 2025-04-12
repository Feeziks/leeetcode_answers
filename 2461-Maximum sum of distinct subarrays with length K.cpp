#include <vector>
#include <set>
#include <iostream>

class Solution
{
public:
  long long maximumSubarraySum(vector<int>& nums, int k)
  {
    long long ret = 0;
    long long thisSum = 0;
    // traverse the sub arrays
    for(int i = 0; i <= nums.size() - k; i++)
    {
      std::unordered_set<int> unique(nums.begin() + i, nums.begin() + i + k);
      thisSum = 0;
      if(k == unique.size())
      {
        thisSum = std::accumulate(unique.begin(), unique.end(), 0);
      }
      ret = std::max(thisSum, ret);
    }
    
    return ret;
  }
};