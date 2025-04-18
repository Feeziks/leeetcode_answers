from collections import defaultdict

class Solution(object):
  def shortestDistance(self, start, curr, dest, connections, distances):
    if dest - 1 == curr:
      return 0

    if distances[curr] != -1:
      return distances[curr]
    
    minDistance = dest
    for nextCity in connections[curr]:
      minDistance = min(minDistance, self.shortestDistance(start, nextCity, dest, connections, distances) + 1)
      #print(curr, nextCity, minDistance)

    distances[curr] = minDistance
    #print(distances)
    return minDistance

  def shortestDistanceAfterQueries(self, n, queries):
    """
    :type n: int
    :type queries: List[List[int]]
    :rtype: List[int]
    """
    cityConnections = defaultdict(list)
    distances = []
    answer = []
    for i in range(n):
      distances.append(-1)
      cityConnections[i].append(i+1)
    for i, e in enumerate(queries):
      cityConnections[e[0]].append(e[1])
      answer.append(self.shortestDistance(0, 0, n, cityConnections, distances))
      distances = []
      distances = [-1] * n

    return answer