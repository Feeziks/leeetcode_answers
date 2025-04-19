#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
class Solution
{
public:
  long long pickGifts(vector<int> &gifts, const int k)
  {
    //return pickGiftsSpeed(gifts, k);
    return pickGiftsMem(gifts, k);
  }

  long long pickGiftsSpeed(const vector<int> &gifts, const int k)
  {
    std::priority_queue<int> giftsQueue(gifts.begin(), gifts.end());
    for(int i = 0; i < k; i++)
    {
      int max = giftsQueue.top();
      giftsQueue.pop();
      giftsQueue.push(std::sqrt(max));
    }

    long long ret = 0;
    while(!giftsQueue.empty())
    {
      ret += giftsQueue.top();
      giftsQueue.pop();
    }
    return ret;
  }

  long long pickGiftsMem(vector<int>& gifts, int k)
  {
    for(int i = 0; i < k; i++)
    {
      auto it = std::max_element(gifts.begin(), gifts.end());
      int max = *it;
      int idx = it - gifts.begin();
      gifts[idx] = std::sqrt(max);
    }
    long long ret = 0;
    for(const auto &val : gifts)
    {
      ret += val;
    }
    return ret;
  }
};