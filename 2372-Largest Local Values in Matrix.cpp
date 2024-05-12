class Solution
{
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid)
  {
    int gridSize = grid.size();
    for(int i = 1; i < gridSize - 1; i++)
    {
      for(int j = 1; j < gridSize -1; j++)
      {
        int temp = 0;

        // This is basically the same exact thing as the find local max function from before but "inlined"
        for(int x = i - 1; x <= i + 1; x++)
        {
          for(int y = j - 1; y <= j + 1; y++)
          {
            temp = std::max(temp, grid[x][y]);
          }
        }

        grid[i - 1][j - 1] = temp;
      }
    }

    // Saving memory by messing up the passed vector
    // In real world use seems like a bad idea
    // But in leet-code use where the memory is made up and we dont have co-workers we can do whatever
    grid.resize(gridSize-2);
    for(int i = 0; i < grid.size(); i++)
    {
      grid[i].resize(gridSize - 2);
    }

    return grid;
  }
};