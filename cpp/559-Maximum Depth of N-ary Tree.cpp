/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
  int DFS(const Node* curr)
  {
    if(nullptr == curr)
    {
      return 0;
    }
    std::cout << curr->val << "\n";
    std::vector<int> depths(curr->children.size());
    int max = 0;
    for(int i = 0; i < curr->children.size(); i++)
    {
      depths.push_back(DFS(curr->children[i]));
    }
    auto maxIt = std::max_element(depths.begin(), depths.end());
    if(maxIt != depths.end())
    {
        max = *maxIt;
    }
    return max + 1;
  }
public:
  int maxDepth(Node* root)
  {
    return DFS(root);
  }
};