#include <vector>

class Solution
{
public:
  int countLargestGroup(int n)
  {
    int ret = 0;
    std::vector<int> sumToCount(37, 0); // 37 comes from the largest n allowed by constraints, 10^4 - 1, 9999, 9*4 = 36
    for(int i = 1; i <= n; i++)
    {
      int val = i;
      int thisSum = 0;
      while(val > 0)
      {
        thisSum += val % 10;
        val = val / 10;
      }
      sumToCount[thisSum]++;
    }

    int maxCnt = 0;
    for(const auto cnt : sumToCount)
    {
      maxCnt = std::max(maxCnt, cnt);
    }
    for(const auto cnt : sumToCount)
    {
      if(cnt == maxCnt)
      {
        ret++;
      }
    }
    return ret;
  }
};