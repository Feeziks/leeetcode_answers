#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  void printBox(const std::vector<std::vector<char>> & in)
  {
    for(size_t i = 0; i < in.size(); i++)
    {
      for(size_t j = 0; j < in[i].size(); j++)
      {
        std::cout << in[i][j] << ", ";
      }
      std::cout << "\n";
    }
  }

  std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>> & boxGrid)
  {
    std::vector<std::vector<char>> ret;

    const char empty = '.';
    const char stone = '#';
    const char obstacle = '*';

    // Find the "bottom" of any given row
    for(size_t i = 0; i < boxGrid.size(); i++)
    {
      int bottomIdx = boxGrid[i].size() - 1;
      for(int j = boxGrid[i].size() - 1; j >= 0; j--)
      {
        if(empty == boxGrid[i][j])
        {
          // Nothing to do here
        }
        else if(stone == boxGrid[i][j])
        {
          // Move the stone down to the bottom idx
          // Update the bottom idx to be "on top" of the new stone
          /*
          std::cout << "Found a stone at " << i << ", " << j << " current bottom idx is " << bottomIdx;
          std::cout << "\nAt bottom idx currently is " << boxGrid[i][bottomIdx];
          std::cout << "\nMoving this stone 'Down' to that location and updating the bottomIdx to " << bottomIdx - 1 << "\n";
          */
          boxGrid[i][j] = empty;
          boxGrid[i][bottomIdx] = stone;
          bottomIdx--;
        }
        else if(obstacle == boxGrid[i][j])
        {
          // Update the bottom idx to be "on top" of this obstacle
          bottomIdx = j - 1;
        }
      }
    }
    
    // Rotate clockwise
    ret.resize(boxGrid[0].size());
    for(int i = 0; i < boxGrid[0].size(); i++)
    {
      for(int j = 0; j < boxGrid.size(); j++)
      {
        ret[i].push_back(boxGrid[j][i]);
      }

      std::reverse(ret[i].begin(), ret[i].end());
    }

    //printBox(boxGrid);
    //std::cout << "\n\n";
    //printBox(ret);

    return ret;
  }
};