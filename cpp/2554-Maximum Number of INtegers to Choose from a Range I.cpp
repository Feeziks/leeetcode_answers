#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int maxCount(vector<int>& banned, int n, int maxSum)
  {
    int ret = 0;
    int sum = 0;
    std::sort(banned.begin(), banned.end());
    int bannedIdx = 0;
    int idx = 1;
    while(idx <= n)
    {
      // std::cout << bannedIdx << "  " << idx;
      if(bannedIdx >= banned.size())
      {
        // std::cout << " bannedIdx > banned.size()";
        sum += idx;
        if(sum <= maxSum)
        {
          ret++;
          idx++;
          continue;
        }
        else
        {
          break;
        }
      }

      if(banned[bannedIdx] == idx)
      {
        // std::cout << " banned[bannedIdx] == idx";
        bannedIdx++;
        idx++;
      }
      else if(banned[bannedIdx] < idx)
      {
        // std::cout << " banned[bannedIdx] < idx";
        while(bannedIdx < banned.size() && banned[bannedIdx] < idx)
        {
          bannedIdx++;
        }
      }
      else
      {
        // std::cout << " banned[bannedIdx] > idx";
        sum += idx;
        if(sum <= maxSum)
        {
          ret++;
          idx++;
        }
        else
        {
          break;
        }
      }

      // std::cout << "\n";
    }

    return ret;
  }
};