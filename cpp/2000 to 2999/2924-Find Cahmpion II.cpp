#include <vector>
#include <iostream>
#include <cstdint>

#define IS_BIT_SET(var, pos) ((var) & (1ll << (pos)))
#define SET_BIT(var, pos) ((var) |= (1ll << (pos)))

class Solution
{
public:
  int findChampion(const int n, const vector<vector<int>>& edges)
  {
    // Question states that n is between 1 and 100 inclusive
    // 2 64 bit values gives us 128 bits to use
    uint64_t isTeamPointedToInEdges[2];
    isTeamPointedToInEdges[0] = 0;
    isTeamPointedToInEdges[1] = 0;
    int m = edges.size();
    int champion = -1;
    for(uint64_t i = 0; i < m; i++)
    {
      uint64_t teamPointedTo = edges[i][1];
      //std::cout << "teamPointedTo " << teamPointedTo << "\n";
      if(teamPointedTo < 64)
      {
        SET_BIT(isTeamPointedToInEdges[0], teamPointedTo);
        //isTeamPointedToInEdges[0] |= 1 << teamPointedTo;
      }
      else
      {
        SET_BIT(isTeamPointedToInEdges[1], teamPointedTo - 64);
        //isTeamPointedToInEdges[1] |= 1 << (teamPointedTo - 64);
      }
    }

    for(int i = 0; i < n; i++)
    {
      if(i < 64)
      {
        if(0 == IS_BIT_SET(isTeamPointedToInEdges[0], i))
        {
          if(champion != -1)
          {
            return -1;
          }
          champion = i;
        }
      }
      else
      {
        if(0 == IS_BIT_SET(isTeamPointedToInEdges[1], i - 64))
        {
          if(champion != -1)
          {
            return -1;
          }
          champion = i;
        }
      }
    }
    return champion;
  }
};