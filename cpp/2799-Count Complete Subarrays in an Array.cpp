#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <bitset>

class Solution
{
public:
  int countCompleteSubarrays(const std::vector<int> &nums)
  {
    int numsSize = nums.size();
    const size_t constraintMaxNumsValue = 2000;
    std::bitset<constraintMaxNumsValue + 1> uniqueElems;

    for(const int val : nums)
    {
      uniqueElems.set(val);
    }

    int leftPtr = 0;
    int ret = 0;
    while(leftPtr < numsSize)
    {
      std::bitset<constraintMaxNumsValue + 1> currentElems;
      int rightPtr = leftPtr;
      while(rightPtr < numsSize)
      {
        currentElems.set(nums[rightPtr]);
        if(currentElems == uniqueElems)
        {
          ret++;
        }
        rightPtr++;
      }
      leftPtr++;
    }
    return ret;
  }

  int countCompleteSubarraysFirstApproach(vector<int>& nums)
  {
    // Early out
    if(nums.size() == 1)
    {
      return 1;
    }

    std::set<int> uniqueElems;
    for(const int val : nums)
    {
      uniqueElems.insert(val);
    }
    int numUniqueElems = uniqueElems.size();

    int ret = 0;
    int leftPtr = 0;
    while(leftPtr <= nums.size() - numUniqueElems)
    {
      std::unordered_map<int, int> uniqueValuesToCounts;
      int rightPtr = leftPtr;
      while(rightPtr < nums.size())
      {
        //std::cout << "leftPtr " << leftPtr << " rightPtr " << rightPtr << "\n";
        uniqueValuesToCounts[nums[rightPtr]]++;
        if(uniqueValuesToCounts.size() == numUniqueElems)
        {
          ret++;
          rightPtr++;
        }
        else if(uniqueValuesToCounts.size() < numUniqueElems)
        {
          rightPtr++;
        }
        else // uniqueValuesToCounts.size() > numUniqueElems
        {
          break;
        }
      }
      leftPtr++;
    }

    return ret;
  }
};