/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
  int DFS(const TreeNode* currNode)
  {
    if(nullptr == currNode)
    {
      return 0;
    }
    int left = DFS(currNode->left);
    int right = DFS(currNode->right);
    return std::max(left, right) + 1;
  }

public:
  int maxDepth(TreeNode* root)
  {
    int maxDepth = 0;
    maxDepth = DFS(root);
    return maxDepth;
  }
};