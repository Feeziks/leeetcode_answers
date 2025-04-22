#include <algorithm>
#include <vector>

class Solution
{
public:
//   int numberOfArrays(vector<int>& differences, int lower, int upper)
//   {
//     std::vector<long long> hidden(differences.size() + 1, 0);
//     // Build the hidden vector
//     for(int i = 0; i < differences.size(); i++)
//     {
//       hidden[i + 1] = differences[i] + hidden[i];
//       //std::cout << hidden[i] << "  ";
//     }
//     //std::cout << hidden[hidden.size() - 1] << "\n";

//     int ret = 0;

//     // How many possible variations of the hidden vector can exist within the lower and upper bounds?
//     auto lowIt = std::min_element(hidden.begin(), hidden.end());
//     auto highIt = std::max_element(hidden.begin(), hidden.end());

//     int lowestVal = *lowIt;
//     int highestVal = *highIt;
//     int range = highestVal - lowestVal;
//     int diffInputs = upper - lower;
//     ret = diffInputs + 1 - range;
//     if(ret < 0)
//       ret = 0;

//     return ret;
//   }

  int numberOfArrays(vector<int>& differences, int lower, int upper)
  {
    long long lowest = 0;
    long long highest = 0;
    long long curr = 0;
    for(int i = 0; i < differences.size(); i++)
    {
      curr += differences[i];
      if(curr > highest)
      {
        highest = curr;
      }
      if(curr < lowest)
      {
        lowest = curr;
      }
    }

    int range = highest - lowest;
    int inputRange = std::abs(upper - lower +  1);
    std::cout << range << "  " << inputRange << "\n";
    int ret = inputRange - range;
    if(ret < 0)
      ret = 0;

    return ret;
  }
};