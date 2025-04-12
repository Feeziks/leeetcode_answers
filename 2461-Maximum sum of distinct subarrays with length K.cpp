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
    std::unordered_map<int, int> window;
    // Fill the first window
    for(size_t i = 0; i < k; i++)
    {
      window[nums[i]]++;
      thisSum += nums[i];
    }
    if(k == window.size())
    {
      ret = thisSum;
    }
    
    for(size_t i = k; i < nums.size(); i++)
    {
      // remove the front of the window and add the new entry
      window[nums[i - k]]--;
      if(0 == window[nums[i - k]])
      {
        window.erase(nums[i - k]);
      }
      window[nums[i]]++;
      
      // Same for the running sum
      thisSum += nums[i];
      thisSum -= nums[i - k];
      if(k == window.size())
      {
        ret = std::max(ret, thisSum);
      }
    }
    
    return ret;
  }
};