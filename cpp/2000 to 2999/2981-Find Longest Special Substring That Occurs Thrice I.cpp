#include <string>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
  int maximumLength(const std::string &s)
  {
    std::unordered_map<std::string, int> subStringToCount;
    int ret = -1;
    int left = 0;
    while(left < s.size())
    {
      int right = left;
      while(right < s.size())
      {
        if(s[right] == s[left])
        {
          std::string sub = s.substr(left, right - left + 1);
          subStringToCount[sub]++;
          //std::cout << sub << " " << subStringToCount[sub] << " " << left << " " << right << "\n";
        }
        else
        {
          break;
        }
        right++;
      }
      left++;
    }

    for(auto const &pair : subStringToCount)
    {
      if(pair.second >= 3)
      {
        ret = std::max(ret, (int)pair.first.size());
      }
    }
    return ret;
  }

  int maximumLengthFirstApproach(const std::string &s)
  {
    std::vector<int> cntLetters(26, 0);
    int ret = -1;
    for(int i = 0; i < s.size(); i++)
    {
      cntLetters[s[i] - 'a'] += 1;
    }
    // If there arent 3 of any letter
    // We cant possibly have a thrice occuring substring of it
    if(*std::max_element(cntLetters.begin(), cntLetters.end()) < 3)
    {
      return ret;
    }

    for(int i = 0; i < cntLetters.size(); i++)
    {
      if(cntLetters[i] >= 3)
      {
        std::cout << cntLetters[i] << "\n";
      }
    }

    return ret;
  }
};