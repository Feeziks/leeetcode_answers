class Solution(object):
  def countCompleteSubarrays(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    uniqueElems = {}
    for n in nums:
      uniqueElems[n] = 1
    
    left = 0
    ret = 0
    n = len(nums)
    while left < n - len(uniqueElems) + 1:
      right = left
      thisElem = {}
      while right < n:
        if nums[right] in thisElem:
          thisElem[nums[right]] += 1
        else:
          thisElem[nums[right]] = 1
        if len(uniqueElems) == len(thisElem):
          ret += 1
        right += 1
      left += 1
    return ret