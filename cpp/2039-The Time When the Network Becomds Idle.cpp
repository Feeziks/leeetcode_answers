#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class Solution
{
private:
  void findShortestPathToMaster(int curr, int level, std::vector<int> &distances)
  {
    // Right now we are assuming the dest is always 0
    // We can change the function signatures in the future to accept a a destination server to extend the functionality
    for(auto nextServer : networkConnections[curr])
    {
      //std::cout << "nextServer: " << nextServer << "  distances[nextServer] " << distances[nextServer] << "  distances[curr] " << distances[curr] << "  level " << level << "\n";
      if(distances[nextServer] > distances[curr] + 1)
      {
        distances[nextServer] = distances[curr] + 1;
        findShortestPathToMaster(nextServer, level + 1, distances);
      }
    }
  }

public:
  std::unordered_map<int, std::unordered_set<int>> networkConnections;
  int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience)
  {
    // Build up the connections list
    for(int i = 0; i < edges.size(); i++)
    {
      networkConnections[edges[i][0]].insert(edges[i][1]);
      networkConnections[edges[i][1]].insert(edges[i][0]);
    }
    // Detect Cycles
    vector<bool> visited(networkConnections.size(), false);
    // Print map for debug
    // for(const auto &pair : networkConnections)
    // {
    //   std::cout << pair.first << "(";
    //   for(const int &elm : pair.second)
    //   {
    //     std::cout << elm << ", ";
    //   }
    //   std::cout << ")\n";
    // }
    // Find the shortest path for each server to reach the master server (0)
    std::vector<int> shortestPathToMaster(networkConnections.size(), 0x7FFFFFFF);
    shortestPathToMaster[0] = 0;
    findShortestPathToMaster(0, 0, shortestPathToMaster);
    // Print shortest for debug
    for(int i = 0 ; i < shortestPathToMaster.size(); i++)
    {
      std::cout << shortestPathToMaster[i] << ", ";
    }
    std::cout << "\n";
    int maxTime = *std::max_element(shortestPathToMaster.begin(), shortestPathToMaster.end());
    maxTime *= 2;
    for(const auto &serv : networkConnections)
    {
      if(serv.first != 0)
      {
        // Did this server resend? 2* is for round trip time
        if(2 * shortestPathToMaster[serv.first] > patience[serv.first])
        {
          // What was the last time this server re-sent thier packet?
          // they RX packet 0 at time 2*shortest
          // They TX last packet at time 2*shortest % patience?
          int numExcessMsg = (2 * shortestPathToMaster[serv.first] - 1) / patience[serv.first];
          int lastMsgTime = numExcessMsg * patience[serv.first];
          int finalMgsRecv = lastMsgTime + 2 * shortestPathToMaster[serv.first];
          maxTime = std::max(maxTime, finalMgsRecv);
        }
      }
    }
    
    return maxTime + 1;
  }
};