class Solution
{
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid)
  {
      std::vector<std::vector<int>> ret;
      ret.resize(grid.size() - 2);
      for(int x = 0; x < ret.size(); x++)
      {
          for(int y = 0; y < ret.size(); y++)
          {
              ret[x].push_back(0);
          }
      }
      int max = 0;
      int prevMax = 0;
      bool prevMaxInWindow = false;
      for(int x = 1; x < grid.size() - 1; x++)
      {
          for(int y = 1; y < grid[x].size() - 1; y++)
          {
              ret[x-1][y-1] = getMaxInWindow(grid, x, y);
          }
      }
      //printMatrix(grid);
      //printMatrix(ret);
      return ret;
  }
  void printMatrix(vector<vector<int>> &matrix)
  {
      for(auto x: matrix)
      {
          for(auto y: x)
          {
              std::cout << y << " ";
          }
          std::cout << "\n";
      }
  }
  int getMaxInWindow(std::vector<std::vector<int>> &vec, int x, int y)
  {
      int max = 0;
      //std::cout << "getMaxInWindow\t";
      //std::cout << "x: " << x << " y: " << y << "\n";
      for(int i = x - 1; i <= x + 1; i++)
      {
          for(int j = y - 1; j <= y + 1; j++)
          {
              //std::cout << " i: " << i << " j: " << j << "\n";
              if(vec[i][j] > max)
              {
                  max = vec[i][j];
              }
          }
      }
      return max;
  }
};