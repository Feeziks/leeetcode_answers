class Solution(object):
  def countLargestGroup(self, n):
    """
    :type n: int
    :rtype: int
    """
    myDict = {}
    thisSum = 0
    for i in range(1, n + 1):
      thisSum = 0
      # Get the sum of i's digits
      value = i
      thisSum += value % 10
      while value > 0:
        value = value / 10
        thisSum += value % 10
        
      if thisSum in myDict:
        myDict[thisSum] += 1
      else:
        myDict[thisSum] = 1
    
    maxCount = max(myDict.values())
    ret = 0
    # How many keys share this max value?
    for key, val in myDict.items():
      if val == maxCount:
        ret += 1
      print(key, val)
    
    return ret