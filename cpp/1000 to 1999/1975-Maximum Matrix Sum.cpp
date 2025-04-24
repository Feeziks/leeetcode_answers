#include <vector>
#include <iostream>

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>>& matrix)
  {
    int numNegativeValues = 0;
    int absMinVal = std::abs(matrix[0][0]);
    long long absSumMatrix = 0;
    for(size_t i = 0; i < matrix.size(); i++)
    {
      for(size_t j = 0; j < matrix[i].size(); j++)
      {
        if(matrix[i][j] < 0)
        {
          numNegativeValues++;
        }
        int thisAbsVal = std::abs(matrix[i][j]);
        absSumMatrix += thisAbsVal;
        absMinVal = std::min(absMinVal, thisAbsVal);
      }
    }

    if(1 == numNegativeValues % 2)
    {
      absSumMatrix -= 2 * absMinVal;
    }

    return absSumMatrix;
  }
};