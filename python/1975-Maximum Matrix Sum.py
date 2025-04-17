import numpy as np

class Solution(object):
  def maxMatrixSum(self, matrix):
    """
    :type matrix: List[List[int]]
    :rtype: int
    """
    numNegativeValues = 0
    minVal = abs(matrix[0][0])
    absSumMatrix = 0
    for i in range(len(matrix)):
      for j in range(len(matrix[i])):
        if matrix[i][j] < 0:
          numNegativeValues += 1

        thisAbs = abs(matrix[i][j])
        absSumMatrix += abs(matrix[i][j])
        #print(thisAbs, minVal)
        if thisAbs < minVal:
          minVal = thisAbs
    
    #print(absSumMatrix)    
    if 1 == numNegativeValues % 2:
      absSumMatrix -= 2 * minVal
    #print(numNegativeValues, absSumMatrix, minVal)
    
    return absSumMatrix