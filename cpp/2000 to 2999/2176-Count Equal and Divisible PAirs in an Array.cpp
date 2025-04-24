#include <vector>
#include <iostream>

class Solution
{
public:
  int countPairs(vector<int>& nums, int k)
  {
    int ret = 0;
    int numsSize = nums.size();
    for(int i = 0; i < numsSize; i++)
    {
      for(int j = i + 1; j < numsSize; j++)
      {
        if(nums[i] == nums[j])
        {
          if(0 == (i * j) % k)
          {
            ret++;
          }
        }
      }
    }
    
    return ret;
  }
};