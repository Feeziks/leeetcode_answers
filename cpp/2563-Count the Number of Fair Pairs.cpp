#include <vector>
#include <algorithm>

class Solution
{
private:
  long long helper(const std::vector<int> &nums, int val)
  {
    int sortedNumsSize = nums.size() - 1;
    long long numFairPairs = 0;
    int leftSorted = 0;
    int rightSorted = sortedNumsSize;

    while(leftSorted < rightSorted)
    {
      int leftVal = nums[leftSorted];
      int rightVal = nums[rightSorted];
      int sum = leftVal + rightVal;

      if(sum < val)
      {
        //std::cout << leftSorted << "  " << rightSorted << "\n";
        numFairPairs += rightSorted - leftSorted;
        leftSorted++;
      }
      else
      {
        rightSorted--;
      }
    }
    return numFairPairs;
  }
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper)
  {
    std::sort(nums.begin(), nums.end());   
    return helper(nums, upper + 1) - helper(nums, lower);
  }
};