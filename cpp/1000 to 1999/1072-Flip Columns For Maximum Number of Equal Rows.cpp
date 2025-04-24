#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  void printMatrix(const std::vector<std::vector<int>>& matrix)
  {
    for(size_t i = 0; i < matrix.size(); i++)
    {
      for(size_t j = 0; j < matrix[i].size(); j++)
      {
        std::cout << matrix[i][j] << ", ";
      }
      std::cout << "\n";
    }
  }

  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
  {
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    int maxEquals = 0;
    printMatrix(matrix);
    // How many are equal without any flips?
    for(size_t i = 0; i < rowCount; i++)
    {
      std::vector<int> flippedRow(colCount);
      int thisEqualCount = 0;

      for(int j = 0; j < colCount; j++)
      {
        flippedRow[j] = 1^matrix[i][j];
      }

      for(size_t j = 0; j < rowCount; j++)
      {
        // Check if the row matches with the original OR the flipped version
        // Matrix[i] is outermost loop - i == the one we are trying to flip right now
        // matrix[j] is this inner loop - j == the one we are comparing aginst right now
        if( (matrix[i] == matrix[j]) || (flippedRow == matrix[j]) )
        {
            thisEqualCount++;
        }
      }
      
      maxEquals = std::max(thisEqualCount, maxEquals);
    }

    return maxEquals;
  }
};