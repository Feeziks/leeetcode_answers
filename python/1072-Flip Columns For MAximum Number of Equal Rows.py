class Solution:
  def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
    colCount = len(matrix[0])
    rowCount = len(matrix)
    maxEqualRows = 0

    for currentRow in matrix:
      # Flip this currentRow
      flippedCurrentRow = [x^1 for x in currentRow]
      thisEqualRows = 0
      # Count the number of matching rows for currentRow and for flippedCurrentRow
      for comparedRow in matrix:
        if (comparedRow == currentRow) or (comparedRow == flippedCurrentRow):
          thisEqualRows = thisEqualRows + 1
      
      maxEqualRows = max(maxEqualRows, thisEqualRows)
    
    return maxEqualRows