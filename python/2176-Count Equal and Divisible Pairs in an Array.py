from collections import defaultdict

class Solution(object):
  def countPairs(self, nums, k):
    valToIdxs = defaultdict(list)
    for i, e in enumerate(nums):
      valToIdxs[e].append(i)

    if max(len(item) for item in valToIdxs.values()) < 2:
      return 0
    
    ret = 0
    for value, idxs in valToIdxs.items():
      for i, firstIdx in enumerate(idxs[:-1]):
        for j, secondIdx in enumerate(idxs):
          if firstIdx != secondIdx and firstIdx < secondIdx:
            if 0 == firstIdx * secondIdx % k:
              ret += 1

    return ret
