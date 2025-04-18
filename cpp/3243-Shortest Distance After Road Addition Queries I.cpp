#include <vector>
#include <iostream>
#include <map>

class Solution
{
private:
  void updateShortestDistances(std::vector<int> &distances)
  {
    for(auto it = cityConnections.begin(); it != cityConnections.end(); it++)
    {
      //std::cout << "Updating the shortest distance for city " << it->first << "\n";
      int thisDistance = getShortestDistance(it->first, it->first, distances);
      distances[it->first] = distances[it->first];
    }
  }

  int getShortestDistance(int startingCity, int thisCity, std::vector<int> &distances)
  {
    //std::cout << "in getShortestDistance, startingCity " << startingCity << ", thisCity " << thisCity << "\n";
    if(thisCity == 0)
    {
      return 0;
    }
    if(distances[thisCity] != -1)
    {
      return distances[thisCity];
    }
    int minDistance = thisCity;
    for(int i = 0; i < cityConnections[thisCity].size(); i++)
    {
      //distance = 0;
      minDistance = std::min(minDistance, getShortestDistance(startingCity, cityConnections[thisCity][i], distances) + 1);
      //std::cout << "\n";
    }
    distances[thisCity] = minDistance;
    
    return distances[minDistance];
  }

public:
  std::map<int, std::vector<int>> cityConnections;
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
  {
    int numQueries = queries.size();
    std::vector<int> shortestDistances;
    std::vector<int> distances(n, -1);
    distances.resize(n);
    for(int i = n - 1; i > 0; i--)
    {
      cityConnections[i] = {i - 1};
    }

    // for(const auto &pair : cityConnections)
    // {
    //   std::cout << "city: " << pair.first << ", vector of connections ";
    //   for(size_t i = 0; i < pair.second.size(); i++)
    //   {
    //     std::cout << pair.second[i] << ", ";
    //   }
    //   std::cout << "\n";
    // }

    for(size_t i = 0; i < numQueries; i++)
    {
    // After applying each queury we need to find the shortest path and append it to the return value
      cityConnections[queries[i][1]].push_back(queries[i][0]);
      updateShortestDistances(distances);
      shortestDistances.push_back(distances[n - 1]);
      //std::cout << shortestDistances[shortestDistances.size() - 1] << ", ";
      distances.clear();
      distances.resize(n, -1);
    }
    //std::cout << "\n";

    return shortestDistances;
  }
};