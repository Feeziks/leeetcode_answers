class Solution(object):
  def countGood(self, nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: int
    """
    n = len(nums)
    same = 0
    right = -1
    cnt = Counter()
    ans = 0
    for left in range(n):
      while same < k and right + 1 < n:
        right += 1
        same += cnt[nums[right]]
        cnt[nums[right]] += 1
      if same >= k:
        ans += n - right
      cnt[nums[left]] -= 1
      same -= cnt[nums[left]]
      #print(ans)
    
    return ans