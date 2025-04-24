#include <string>
#include <vector>

class Solution
{
public:
  string addSpaces(string s, vector<int>& spaces)
  {
    std::string ret(s.size() + spaces.size(), ' ');
    int spacesIdx = 0;
    int spacesLen = spaces.size();
    for(int i = 0; i < s.size(); i++)
    {
      if( (spacesIdx < spacesLen) && (spaces[spacesIdx] == i) )
      {
        ret[i + spacesIdx] = ' ';
        spacesIdx++;
      }
      ret[i + spacesIdx] = s[i];
    }
    return ret;
  }
};