#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

class Solution
{
private:
  void BFS(int start, const std::vector<std::vector<std::tuple<int, int>>> &graph, std::vector<int> &distances)
  {
    std::queue<int> q;
    q.push(start);
    while(!q.empty())
    {
      for(int i = q.size(); i > 0; i--)
      {
        int curr = q.front();
        q.pop();
        for(auto next : graph[curr])
        {
          int nextNode = std::get<0>(next);
          int nextWeight = std::get<1>(next);
          //std::cout << "curr node " << curr << " next node " << nextNode << " distances[curr] " << distances[curr] << " distances[next] " << distances[nextNode] << " weight to add " << nextWeight << "\n";
          if( (distances[nextNode] == -1) || (distances[nextNode] > distances[curr] + nextWeight) )
          {
            q.push(nextNode);
            distances[nextNode] = distances[curr] + nextWeight;
            //std::cout << "minTime " << minTime << ", distances[curr] " << distances[curr] << ", distances[nextNode] " << distances[nextNode] << "\n";
          }
        }
      }
    }
  }
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k)
  {
    // Build the graph
    std::vector<std::vector<std::tuple<int, int>>> networkGraph(n + 1);
    for(int i = 0; i < times.size(); i++)
    {
      //std::cout << times[i][1] << "    " << times[i][2] << "\n";
      auto thisTuple = std::make_tuple(times[i][1], times[i][2]);
      networkGraph[times[i][0]].push_back(thisTuple);
    }

    // Try to find the minimum time, if we cannot find a path from K to each other node in the graph, return -1
    std::vector<int> distances(n + 1, -1);
    distances[0] = 0;
    distances[k] = 0;
    BFS(k, networkGraph, distances);
    int minTime = 0;
    // Are any entries in distances still -1? Meaning we didnt visit that node at any point?
    for(int i = 0; i <= n; i++)
    {
      //std::cout << distances[i] << ", ";
      if(-1 == distances[i])
      {
        //std::cout << "We never visited the node " << i+1 << "\n";
        minTime = -1;
        break;
      }
      minTime = std::max(minTime, distances[i]);
    }


    return minTime;
  }
};