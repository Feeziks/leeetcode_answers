# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
  def DFS(self, curr):
    if curr == None:
      return 0
    left = self.DFS(curr.left)
    right = self.DFS(curr.right)
    return max(left, right) + 1
  def maxDepth(self, root):
    """
    :type root: Optional[TreeNode]
    :rtype: int
    """
    return self.DFS(root)