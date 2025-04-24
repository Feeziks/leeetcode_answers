#include <string>

class Solution
{
public:
  bool canMakeSubsequence(string str1, string str2)
  {
    int ptrStr1 = 0;
    int ptrStr2 = 0;
    bool ret = false;
    while(ptrStr1 < str1.size() && ptrStr2 < str2.size())
    {
      // Strange kind of shift to "base band" increment to next idx, mod by length of alphabet, and then upshift to correct
      // ascii range
      char tmp = str1[ptrStr1] - 'a';
      tmp += 1;
      tmp = tmp % 26;
      tmp += 'a';

      if( (str1[ptrStr1] == str2[ptrStr2]) || (tmp == str2[ptrStr2]))
      {
        ptrStr1++;
        ptrStr2++;
      }
      else
      {
        ptrStr1++;
      }
    }

    if(ptrStr2 == str2.size())
    {
      ret = true;
    }

    return ret;
  }
};