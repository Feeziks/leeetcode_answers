#include <string>
#include <vector>
#include <queue>

class Solution
{
public:
  bool canChange(string start, string target)
  {
    int n = start.size();
    std::vector<int> numL = {0, 0};
    std::vector<int> numR = {0, 0};
    std::queue<char> startQueue;
    std::queue<char> targetQueue;
    int idxFinalTargetL = 0;
    int cntStartLPastLastTargetL = 0;
    for(int i = 0; i < n; i++)
    {
      if(start[i] == 'L')
      {
        cntStartLPastLastTargetL++;
        startQueue.push(start[i]);
        numL[0]++;
      }
      if(start[i] == 'R')
      {
        // If there are any 'R' to the left of our current idx we can never obtain the target string
        if(numR[1] > numR[0])
        {
          // std::cout << "There is a target R to the left of a start R " << i << " numR[1] " << numR[1] << "\n";
          return false;
        }
        startQueue.push(start[i]);
        numR[0]++;
      }
      if(target[i] == 'L')
      {
        // If there are any 'L' to the left of our current idx we can never obtain the target string
        if(numL[0] > numL[1] && start[i] != 'L')
        {
          // std::cout << "There is a start L to the left of a target L " << i << " numL[0] " << numL[0] << " start[i] " << start[i] << "\n";
          return false;
        }
        idxFinalTargetL = i;
        cntStartLPastLastTargetL = 0;
        targetQueue.push(target[i]);
        numL[1]++;
      }
      if(target[i] == 'R')
      {
        targetQueue.push(target[i]);
        numR[1]++;
      }
    }

    if( (numL[0] != numL[1]) || (numR[0] != numR[1]) )
    {
      // std::cout << "Left cnts " << numL[0] << " " << numL[1] << " Right cnts " << numR[0] << " " << numR[1] << "\n";
      return false;
    }
    // Check if the L and R values are in the same order
    while(startQueue.size() > 0 && targetQueue.size() > 0)
    {
      char startChar = startQueue.front();
      char targetChar = targetQueue.front();
      startQueue.pop();
      targetQueue.pop();

      if(startChar != targetChar)
      {
        // std::cout << "startChar " << startChar << " targetChar " << targetChar << "\n";
        return false;
      }
    }

    return true;
  }
};