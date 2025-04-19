#include <queue>
#include <vector>
#include <iostream>
#include <climits>

class Solution
{
private:
  std::vector<std::vector<std::vector<int>>> constructAdjList(std::map<int, std::vector<std::vector<int>>> &edges, int num)
  {
    std::vector<std::vector<std::vector<int>>> adj(num);
    for(const auto &pair : edges)
    {
      int u = pair.first;
      for(int i = 0; i < edges[pair.first].size(); i++)
      {
        int v = edges[u][i][1];
        int wt = edges[u][i][2];
        adj[u].push_back({v, wt});
        //adj[v].push_back({u, wt});
        // std::cout<< "u " << u << " v " << v << " wt " << wt << " size " << adj[u].size() << "\n";
      }
      // std::cout<< "adj[" << u << "] ";
      for(int i = 0; i < adj[u].size(); i++)
      {
        // std::cout<< adj[u][i][0] << " " << adj[u][i][1] << ",   ";
      }
      // std::cout<< "\n";
    }
    return adj;
  }

  std::vector<int> dijkstra(int num, std::map<int, std::vector<std::vector<int>>> &edges, int src)
  {
    std::vector<std::vector<std::vector<int>>> adjList = constructAdjList(edges, num);
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> prioQ;
    std::vector<int> distances(num, INT_MAX);

    prioQ.push({0, src});
    distances[src] = 0;

    while(!prioQ.empty())
    {
      int u = prioQ.top()[1];
      prioQ.pop();
      // std::cout<< "\n";
      // std::cout<< "u " << u;
      for(auto neighbor : adjList[u])
      {
        int next = neighbor[0];
        int weight = neighbor[1];
        // std::cout<< " next " << next;
        // std::cout<< " distances[next] = " << distances[next];
        // std::cout<< " distances[u] " << distances[u];
        // std::cout<< " weight " << weight << "\n";
        if(distances[next] > distances[u] + weight)
        {
          distances[next] = distances[u] + weight;
          prioQ.push({distances[next], next});
        }
      }
      if(u == num - 1)
        break;
    }
    for(int i = 0; i < distances.size(); i++)
    {
        // std::cout<< distances[i] << "\n";
    }
    return distances;
  }
public:
  int minimumObstacles(vector<vector<int>>& grid)
  {
    // Construct the edges vector and weights
    std::map<int, std::vector<std::vector<int>>> edges;
    int n = grid.size();
    int m = grid[0].size();
    if(n == 1)
    {
        //std::cout <<" shits flat \n";
        return std::accumulate(grid[0].begin(), grid[0].end(), 0);
    }
    // std::cout<< "n " << n << " m " << m << "\n";
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        int thisCell = i*m + j;
        // std::cout<< "thisCell " << thisCell << " i " << i << " j " << j << " grid[i][j] " << grid[i][j] <<" ";
        // Go right
        if(j + 1 < m)
        {
          // std::cout<< "right grid[i][j + 1] " << grid[i][j + 1] << " ";
          edges[thisCell].push_back({thisCell, thisCell + 1, grid[i][j + 1]});
        }
        // Go Down
        if(i + 1 < n)
        {
          // std::cout<< "down grid[i+1][j] " << grid[i + 1][j] << " ";
          edges[thisCell].push_back({thisCell, (i + 1) * m + j, grid[i + 1][j]});
        }
        // Go Left
        if(j - 1 >= 0)
        {
          // std::cout<< "left grid[i][j-1] " << grid[i][j-1] << " ";
          edges[thisCell].push_back({thisCell, thisCell - 1, grid[i][j - 1]});
        }
        // Go Up
        if(i - 1 >= 0)
        {
          // std::cout<< "up grid[i-1][j] " << grid[i-1][j] << " ";
          edges[thisCell].push_back({thisCell, (i - 1) * m + j, grid[i - 1][j]});
        }
        // std::cout<< "\n";
      }
    }
    
    // // std::cout<< "edges\n";
    // for(const auto &pair : edges)
    // {
    //   for(int i = 0; i < edges[pair.first].size(); i++)
    //   {
    //     // std::cout<< "edges[" << pair.first << "] ";
    //     // std::cout<< "source " << edges[pair.first][i][0] << " ";
    //     // std::cout<< "dest " << edges[pair.first][i][1] << " ";
    //     // std::cout<< "weight " << edges[pair.first][i][2] << "\n";
    //   }
    //   // std::cout<< "\n";
    // }
    

    // Call dijkstra with the  grid and return the distance from 0 to the last entry in the grid
    std::vector<int> distances = dijkstra(n * m, edges, 0);
    return distances[distances.size() - 1];
  }
};