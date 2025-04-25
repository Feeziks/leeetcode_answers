from collections import defaultdict

class Solution(object):
  def maximumLength(self, s):
    """
    :type s: str
    :rtype: int
    """
    specialSubstrToCnt = defaultdict(int)
    for i, left in enumerate(s):
      for right in range(i, len(s)):
        if left == s[right]:
          specialSubstrToCnt[s[i:right+1]] += 1
        else:
          break
    ret = -1
    for key, val in specialSubstrToCnt.items():
      if val >= 3:
        ret = max(ret, len(key))
    
    return ret