#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

class Solution
{
public:
  int minimumSize(std::vector<int>& nums, int maxOperations)
  {
    int low = 1;
    int high = 1e9; //*std::max_element(nums.begin(), nums.end());
    while(low < high)
    {
      int mid = low + (high - low) / 2;
      int ops = 0;
      for(const int val : nums)
      {
        ops += (val - 1) / mid;
      }
      if(ops > maxOperations)
      {
        low = mid + 1;
      }
      else
      {
        high = mid;
      }
    }

    return low;
  }

  int minimumSizeTimeLimitExceeded(vector<int>& nums, int maxOperations)
  {
    int penalty = 0;
    int numOperations = 0;
    std::map<int, int> countNums;
    for(const auto val : nums)
    {
      countNums[val]++;
    }

    for(; numOperations <= maxOperations; numOperations++)
    {
      int thisNum = countNums.rbegin()->first;
      int newValLeft = 0;
      int newValRight = 0;
      while(0 == countNums[thisNum])
      {
        countNums.erase(thisNum);
        thisNum = countNums.rbegin()->first;
      }
      // If the only "bags" left are 1, we are done, we cannot reduce our penatly any further
      if(thisNum == 1)
      {
        return 1;
      }

      countNums[thisNum]--;
      if(0 == thisNum % 2)
      {
        newValLeft = thisNum / 2;
        newValRight = thisNum / 2;
      }
      else if(3 == thisNum)
      {
        newValLeft = 1;
        newValRight = 2;
      }
      else
      {
        // Find the next smallest even value to assign to the "right" bag
        // + 2 after division will be the next smallest even
        // -1 on the "left" bag to make the addition still == the original value
        newValRight = thisNum / 2 + 2;
        newValLeft = thisNum / 2 - 1;
      }
      countNums[newValLeft]++;
      countNums[newValRight]++;
    }

    penalty = countNums.rbegin()->first;
    while(0 == countNums[penalty])
    {
      countNums.erase(penalty);
      penalty = countNums.rbegin()->first;
    }
    return penalty;
  }
};