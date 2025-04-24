#include <string>
#include <iostream>

class Solution
{
private:
  
public:
  int takeCharacters(const std::string &s, const int k)
  {
    if(0 == k)
    {
      return 0;
    }
    
    int counts[3] = {0, 0, 0};
    for(size_t i = 0; i < s.size(); i++)
    {
      counts[s[i] - 'a']++;
    }
    
    if(counts[0] < k || counts[1] < k || counts[2] < k)
    {
      return -1;
    }
    
    int windowCounts[3] = {0, 0, 0};
    int left = 0;
    int maxWindowWidth = 0;
    
    for(int right = 0; right < s.size(); right++)
    {
      // incr count for the new right most char
      windowCounts[s[right] - 'a']++;
      
      // shrink window by moving left "ptr" if required
      while (left <= right &&
        (counts[0] - windowCounts[0] < k || counts[1] - windowCounts[1] < k ||
        counts[2] - windowCounts[2] < k))
      {
        windowCounts[s[left] - 'a']--;
        left++;
      }
      maxWindowWidth = std::max(maxWindowWidth, right - left + 1);
      //std::cout << "left " << left << " right " << right << " maxWindowWidth " << maxWindowWidth << " currWindowWidth " << right - left + 1 << "\n";
    } 
    
    return s.size() - maxWindowWidth;
  }
};