class Solution(object):
  def rotateTheBox(self, boxGrid):
    """
    :type boxGrid: List[List[str]]
    :rtype: List[List[str]]
    """
    m = len(boxGrid)
    n = len(boxGrid[0])
    ret = [ ["." for _ in range(m)] for _ in range(n)]

    stone = '#'
    empty = '.'
    obstacle = '*'

    for i in range (m):
      bottomIdx = n - 1
      for j in range(n - 1, -1, -1):
        if stone == boxGrid[i][j]:
          ret[bottomIdx][m - i - 1] = stone
          bottomIdx -= 1
        if obstacle == boxGrid[i][j]:
            ret[j][m - i - 1] = obstacle
            bottomIdx = j - 1

    return ret