#include <iostream>
#include <vector>

class Solution
{
public:
  vector<int> decrypt(vector<int>& code, int k)
  {
    vector<int> ret(code.size(), 0);
    if(k > 0)
    {
      for(int i = 0; i < code.size(); i++)
      {
        for(int j = 1; j <= k; j++)
        {
          ret[i] += code[(i + j) % code.size()];
        }
      }
    }
    else if (k < 0)
    {
      for(int i = 0; i < code.size(); i++)
      {
        for(int j = std::abs(k); j > 0; j--)
        {
          if( (i - j) < 0)
          {
            // std::cout << code.size() + (i - j) << "  " << i << "  " << j << "  " << "\n";
            ret[i] += code[code.size() + (i - j)];
          }
          else
          {
            ret[i] += code[i - j];
          }
        }
      }
    }
    
    return ret;
  }
};