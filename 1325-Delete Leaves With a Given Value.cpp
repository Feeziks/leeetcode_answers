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
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        _target = target;
        return recurseDelete(root);
    }

    int _target;

    TreeNode* recurseDelete(TreeNode* node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        if(node->left != nullptr)
        {
            node->left = recurseDelete(node->left);
        }
        if(node->right != nullptr)
        {
            node->right = recurseDelete(node->right);
        }

        // chgeck if we are a leaf
        if(node->left == nullptr && node->right == nullptr)
        {
            // IF we are a leaf do we have the target val?
            if(node->val == _target)
            {
                // Delete this node
                // Need the parent node
                return nullptr;
            }
        }

        return node;
    }
};