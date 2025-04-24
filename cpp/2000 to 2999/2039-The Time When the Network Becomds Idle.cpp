#include <vector>
#include <iostream>
#include <queue>

class Solution
{
private:
  int findShortestPathToMaster(int start, vector<int> &distances)
  {
    std::queue<int> q;
    q.push(start);
    int max = 0;
    while(!q.empty())
    {
      for(int i = q.size(); i > 0; --i)
      {
        int curr = q.front();
        q.pop();
        for(auto next : networkConnections[curr])
        {
          if(-1 == distances[next])
          {
            q.push(next);
            distances[next] = distances[curr] + 1;
            max = std::max(max, distances[curr] + 1);
          }
        }
      }
    }
    return max;
  }

public:
  std::vector<std::vector<int>> networkConnections;
  int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience)
  {
    networkConnections.resize(patience.size());
    // Build up the connections list
    for(int i = 0; i < edges.size(); i++)
    {
      networkConnections[edges[i][0]].push_back(edges[i][1]);
      networkConnections[edges[i][1]].push_back(edges[i][0]);
    }
    // Find the shortest path for each server to reach the master server (0)
    std::vector<int> shortestPathToMaster(networkConnections.size(), -1);
    shortestPathToMaster[0] = 0;
    int maxTime = findShortestPathToMaster(0, shortestPathToMaster);
    maxTime *= 2;    
    for(int i = 1; i < networkConnections.size(); i++)
    {
      // Did this server resend? 2* is for round trip time
      if(2 * shortestPathToMaster[i] > patience[i])
      {
        // What was the last time this server re-sent thier packet?
        // they RX packet 0 at time 2*shortest
        // They TX last packet at time 2*shortest % patience?
        int numExcessMsg = (2 * shortestPathToMaster[i] - 1) / patience[i];
        int lastMsgTime = numExcessMsg * patience[i];
        int finalMgsRecv = lastMsgTime + 2 * shortestPathToMaster[i];
        maxTime = std::max(maxTime, finalMgsRecv);
      }
    }
    
    return maxTime + 1;
  }
};