#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution
{
private:
  bool differentParity(const int num1, const int num2)
  {
    return (num1 & 0b1) ^ (num2 & 0b1);
  }
public:
  std::vector<bool> isArraySpecial(const std::vector<int> &nums, const std::vector<std::vector<int>> &queries)
  {
    return isArraySpecialSum(nums, queries);
  }

  std::vector<bool> isArraySpecialSum(const std::vector<int> &nums, const std::vector<std::vector<int>> &queries)
  {
    std::vector<bool> ret(queries.size(), false);
    std::vector<int> parityVec(nums.size(), 0);
    for(int i = 1; i < nums.size(); i++)
    {
      parityVec[i] = parityVec[i - 1];
      if(!differentParity(nums[i-1], nums[i]))
      {
        parityVec[i]++;
      }
    }

    for(int i = 0; i < queries.size(); i++)
    {
      int left = queries[i][0];
      int right = queries[i][1];
      int sum = parityVec[right] - parityVec[left];
      ret[i] = sum == 0;
    }

    return ret;
  }

  std::vector<bool> isArraySpecialLRPtr(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
  {
    std::vector<bool> ret(queries.size(), false);

    // Build up all the unique vectors start and end idx
    std::vector<std::vector<int>> allSpecialArrays;
    // TODO: Find the first special sub array to init the left and right idx to
    int leftIdx = 0;
    int rightIdx = 1;
    while(leftIdx < nums.size() && rightIdx < nums.size() && !differentParity(nums[leftIdx], nums[rightIdx]))
    {
      leftIdx++;
      rightIdx++;
    }

    while(leftIdx < nums.size() && rightIdx < nums.size())
    {
        // Are we still special?
      if(differentParity(nums[rightIdx - 1], nums[rightIdx]))
      {
        rightIdx++;
      }
      else
      {
        // The last array we checked was never special, check if this new one is special
        if(rightIdx == leftIdx + 1)
        {
            leftIdx++;
            rightIdx++;
        //   if(differentParity(nums[leftIdx], nums[rightIdx]))
        //   {
        //     allSpecialArrays.push_back({leftIdx, rightIdx});
        //     leftIdx = rightIdx;
        //     rightIdx++;
        //   }
        }
        // we have gone off the end of a special sub array
        else
        {
          allSpecialArrays.push_back({leftIdx, rightIdx - 1});
          leftIdx = rightIdx;
          rightIdx++;
        }
      }
    }

    if(leftIdx < nums.size() - 1 && rightIdx == nums.size())
    {
      allSpecialArrays.push_back({leftIdx, rightIdx - 1});
    }

    // Check all the queries vs the allSpecialArrays vector
    for(int i = 0; i < queries.size(); i++)
    {
      if(queries[i][0] == queries[i][1])
      {
        ret[i] = true;
        continue;
      }

      for(int j = 0; j < allSpecialArrays.size(); j++)
      {
        if(queries[i][0] >= allSpecialArrays[j][0])
        {
          if(queries[i][1] <= allSpecialArrays[j][1])
          {
            ret[i] = true;
          }
        }
        else
        {
          break;
        }
      }
    }
    return ret;
  }


  // This approach loses the order of the queries passed into it
  // Wont meet the needs of the function
  vector<bool> isArraySpecialBad(vector<int>& nums, vector<vector<int>>& queries)
  {
    std::vector<bool> ret(queries.size(), false);
    std::map<int, std::set<int>> queriestByStartIdx;
    for(int i = 0; i < queries.size(); i++)
    {
      queriestByStartIdx[queries[i][0]].insert(queries[i][1]);
    }


    return ret;
  }
};