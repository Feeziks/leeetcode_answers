#include <string>
#include <vector>
#include <sstream>

class Solution
{
public:
  int isPrefixOfWord(string sentence, string searchWord)
  {
    std::stringstream ss(sentence);
    std::string token;
    int idx = 1;
    while(std::getline(ss, token, ' '))
    {
      if(token.size() >= searchWord.size())
      {
        std::string wordPre = token.substr(0, searchWord.size());
        if(wordPre == searchWord)
        {
          return idx;
        }
      }
      idx++;
    }
    return -1;
  }
};