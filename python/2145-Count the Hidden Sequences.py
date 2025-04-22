class Solution(object):
  def numberOfArrays(self, differences, lower, upper):
    """
    :type differences: List[int]
    :type lower: int
    :type upper: int
    :rtype: int
    """
    curr = 0
    lowest = 0
    highest = 0
    diff = 0
    inputRange = upper - lower + 1
    for d in differences:
      curr += d
      highest = max(highest, curr)
      lowest = min(lowest, curr)

    diff = highest - lowest
    ret = inputRange - diff
    return max(0, ret)
