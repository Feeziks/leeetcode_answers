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
 #include <algorithm>
class Solution {
public:
    int prev = INT_MAX;
    int ret = INT_MAX;

    int getMinimumDifference(TreeNode* root)
    {
        /*
        if(root == nullptr)
        {
            return 0;
        }
        // Walk the tree
        // Store the values in a vector
        // Sort the vector
        // find the min between any two neighbors in the vector
        std::vector<int> values;
        depth_first_walk(root, values);
        std::sort(values.begin(), values.end());
        int min = values[1] - values[0];
        if(min == 0)
        {
            return min;
        }
        for(int i = 1; i < values.size() - 1; i++)
        {
            if((values[i + 1] - values[i]) < min)
            {
                min = (values[i + 1] - values[i]);
                if(min == 0)
                {
                    break;
                }
            }
        }

        return min;
        */

        depth_first_walk_and_compare(root);
        return ret;
    }

    void depth_first_walk_and_compare(TreeNode *this_node)
    {
        if(this_node->left != nullptr)
        {
            depth_first_walk_and_compare(this_node->left);
        }

        if(prev != INT_MAX)
        {
            ret = min(ret, abs(prev - this_node->val));
        }
        prev = this_node->val;
        if(this_node->right != nullptr)
        {
            depth_first_walk_and_compare(this_node->right);
        }
    }

    void depth_first_walk(TreeNode *this_node, std::vector<int> &vec)
    {
        vec.push_back(this_node->val);
        if(this_node->left != nullptr)
        {
            depth_first_walk(this_node->left, vec);
        }
        if(this_node->right != nullptr)
        {
            depth_first_walk(this_node->right, vec);
        }
    }
};