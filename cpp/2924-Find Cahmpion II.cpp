#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int findChampion(int n, const vector<vector<int>>& edges)
  {
    std::vector<bool> isTeamPointedToInEdges(n, false);
    int m = edges.size();
    int champion = -1;
    for(int i = 0; i < m; i++)
    {
      isTeamPointedToInEdges[edges[i][1]] = true;
    }

    for(size_t i = 0; i < isTeamPointedToInEdges.size(); i++)
    {
      if(isTeamPointedToInEdges[i] == false)
      {
        if(champion != -1)
        {
          champion = -1;
          break;
        }
        champion = i;
      }
    }
    return champion;
  }
};