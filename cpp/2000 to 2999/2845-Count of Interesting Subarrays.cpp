#include <vector>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
  long long countInterestingSubarrays(vector<int>& nums, const int modulo, const int k)
  {
    std::unordered_map<int, int> counts;
    long long ret = 0;
    int runningCount = 0;
    counts[0] = 1;
    for(int i = 0; i < nums.size(); i++)
    {
      int modResult = k == nums[i] % modulo;
      runningCount += modResult;
      ret += counts[(runningCount - k + modulo) % modulo];
      counts[runningCount % modulo]++;
    }
    return ret;
  }
};