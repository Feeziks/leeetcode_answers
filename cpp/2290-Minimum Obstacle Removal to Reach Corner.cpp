#include <queue>
#include <vector>
#include <iostream>
#include <climits>

class Solution
{
private:
  inline bool isOutside(int i, int j, int n, int m)
  {
    return i < 0 || i >= n || j < 0 || j >= m;
  }
  inline int toIdx(int i, int j, int m)
  {
    return i * m + j;
  }
  inline std::tuple<int, int> fromIdx(int idx, int m)
  {
    return std::make_tuple(idx / m, idx % m);
  }

  int dijkstra(const vector<vector<int>>& grid, int src)
  {
    int n = grid.size();
    int m = grid[0].size();

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> prioQ;
    std::vector<int> distances(n * m,  INT_MAX);

    prioQ.push({0, src});
    distances[src] = 0;

    while(!prioQ.empty())
    {
      int u = prioQ.top()[1];
      prioQ.pop();
      if(u == n * m -1)
      {
        return distances[u];
      }
      
      for(int i = 0; i < 4; i++)
      {
        int nextIdx = 0;
        switch(i)
        {
          case 0: //right
            nextIdx = u + 1;
            break;
          case 1: //down
            nextIdx = u + m;
            break;
          case 2: //left
            nextIdx = u - 1;
            break;
          case 3: // up
            nextIdx = u + m;
            break;
        }
        int r = std::get<0>(fromIdx(nextIdx, m));
        int c = std::get<1>(fromIdx(nextIdx, m));
        if(isOutside(r, c, n, m))
        {
          continue;
        }
        int nextDistance = grid[r][c] + distances[u];
        if(nextDistance < distances[nextIdx])
        {
          distances[nextIdx] = nextDistance;
          prioQ.push({nextDistance, nextIdx});
        }
      }
    }
    return -1;
  }
public:
  int minimumObstacles(vector<vector<int>>& grid)
  {
    // Call dijkstra with the  grid and return the distance from 0 to the last entry in the grid
    return dijkstra(grid, 0);
  }
};