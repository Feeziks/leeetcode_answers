class Solution
{
  public:
    int matrixScore(vector<vector<int>>& grid)
    {
      // First step make sure all the MSB's are set to high
      for(int i = 0; i < grid.size(); i++)
      {
        if(0 == grid[i][0])
        {
          // Flip this row
          flipRow(grid, i);
        }
      }

      // Flip any col that has more 0's than 1's
      int numZero = 0;
      int numOne = 0;
      for(int col = 1; col < grid[0].size(); col++)
      {
        numZero = 0;
        numOne = 0;
        for(int row = 0; row < grid.size(); row++)
        {
          if(0 == grid[row][col])
          {
            numZero++;
          }
          else
          {
            numOne++;
          }
        }

        if(numZero > numOne)
        {
          flipCol(grid, col);
        }
      }

      return getScore(grid);
    }

    void flipRow(vector<vector<int>> &grid, int row)
    {
      for(int i = 0; i < grid[row].size(); i++)
      {
        grid[row][i] ^= 1;
      }
    }

    void flipCol(vector<vector<int>> &grid, int col)
    {
      for(int i = 0; i < grid.size(); i++)
      {
        grid[i][col] ^= 1;
      }
    }

    void printGrid(const vector<vector<int>> &grid)
    {
      for(auto x: grid)
      {
        for(auto y: x)
        {
          std::cout << y << " ";
        }
        std::cout << "\n";
      }
    }

    int getScore(const vector<vector<int>> &grid)
    {
      int score = 0;
      int val = 0;
      for(int i = 0; i < grid.size(); i++)
      {
        val = 0;
        int rowSize = grid[i].size();
        for(int j = rowSize - 1; j >= 0; j--)
        {
          val += grid[i][j] << (rowSize - 1 - j);
        }
        score += val;
      }
      return score;
    }
};