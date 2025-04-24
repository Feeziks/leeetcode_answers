#include <queue>
#include <iostream>

class Solution
{
public:
  std::vector<int> getFinalState(std::vector<int> &nums, int k, int multiplier)
  {
    for(int i = 0; i < k; i++)
    {
      int minVal = INT_MAX;
      int minIdx = 0;
      for(int j = 0; j < nums.size(); j++)
      {
        if(minVal > nums[j])
        {
          minIdx = j;
          minVal = nums[j];
        }
      }
      nums[minIdx] = minVal * multiplier;
    }
    return nums;
  }

  vector<int> getFinalStatePQ(vector<int>& nums, int k, int multiplier)
  {
    std::priority_queue<std::pair<int, int>, 
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>> prioQ;

    for(int i = 0; i < nums.size(); i++)
    {
      std::pair<int, int> temp = std::make_pair(nums[i], i);
      prioQ.push(temp);
    }

    for(int i = 0; i < k; i++)
    {
      std::pair<int, int> temp = prioQ.top();
      prioQ.pop();
      temp.first = temp.first * multiplier;
      prioQ.push(temp);
    }

    while(!prioQ.empty())
    {
      std::pair<int, int> temp = prioQ.top();
      prioQ.pop();
      nums[temp.second] = temp.first;
    }

    return nums;
  }
};