#include <string>
#include <iostream>

struct node
{
  std::string s = "";
  node *parent = nullptr;
  node *left = nullptr;
  node *right = nullptr;
  
  int cntA = 0;
  int cntB = 0;
  int cntC = 0;
  int cntOps = 0;
};

class Solution
{
private:
  bool checkPossible(const std::string &s, const int k)
  {
    // Check if S contains at least k 'a' 'b' and 'c'
    int cntA = 0;
    int cntB = 0;
    int cntC = 0;
    for(size_t i = 0; i < s.size(); i++)
    {
      if('a' == s[i])
      {
        cntA++;
      }
      else if('b' == s[i])
      {
        cntB++;
      }
      else if('c' == s[i])
      {
        cntC++;
      }
    }
    // Not enough of each letter to perform the functionality
    if(cntA < k || cntB < k || cntC < k)
    {
      return false;
    }
    return true;
  }
  
  void createTree(node *thisNode)
  {
    if(thisNode->s != "")
    {
      if(nullptr == thisNode->left)
      {
        node *newNode = new node;
        newNode->parent = thisNode;
        thisNode->left = newNode;
        newNode->cntA = thisNode->cntA;
        newNode->cntB = thisNode->cntB;
        newNode->cntC = thisNode->cntC;
        newNode->cntOps = thisNode->cntOps + 1;
        
        // incremenet for left most entry
        thisNode->s[0] == 'a' ? newNode->cntA++ : thisNode->s[0] == 'b' ? newNode->cntB++ : newNode->cntC++;
        if(newNode->cntA >= reqK && newNode->cntB >= reqK && newNode->cntC >= reqK)
        {
          minOps = std::min(minOps, newNode->cntOps);
        }
        newNode->s = thisNode->s;
        newNode->s.erase(0, 1);
        //std::cout << "createTree took left path, calling node string is " << thisNode->s << " new node string is " << newNode->s << "\n";
        //std::cout << "calling node cntOps is " << thisNode->cntOps << " new node cntOps is " << newNode->cntOps << " minOps is " << minOps << "\n";
        createTree(newNode);
      }
      if(nullptr == thisNode->right)
      {
        node *newNode = new node;
        newNode->parent = thisNode;
        thisNode->right = newNode;
        newNode->cntA = thisNode->cntA;
        newNode->cntB = thisNode->cntB;
        newNode->cntC = thisNode->cntC;
        newNode->cntOps = thisNode->cntOps + 1;
        
        // incremenet for right most entry
        int charIdx = thisNode->s.size() - 1;
        thisNode->s[charIdx] == 'a' ? newNode->cntA++ : thisNode->s[charIdx] == 'b' ? newNode->cntB++ : newNode->cntC++;
        if(newNode->cntA >= reqK && newNode->cntB >= reqK && newNode->cntC >= reqK)
        {
          minOps = std::min(minOps, newNode->cntOps);
        }
        newNode->s = thisNode->s;
        newNode->s.erase(charIdx);
        //std::cout << "createTree took right path, calling node string is " << thisNode->s << " new node string is " << newNode->s << "\n";
        //std::cout << "calling node cntOps is " << thisNode->cntOps << " new node cntOps is " << newNode->cntOps << " minOps is " << minOps << "\n";
        createTree(newNode);
      }
    }
  }
public:
  int minOps = 0;
  int reqK = 0;
  
  int takeCharacters(const std::string &s, const int k)
  {
    if(0 == k)
    {
      return 0;
    }
    if(!checkPossible(s, k))
    {
      return -1;
    }
    
    minOps = s.size();
    reqK = k;
    
    node treeRoot;
    treeRoot.parent = nullptr;
    treeRoot.s = s;
    
    createTree(&treeRoot);
    return minOps;
  }
};