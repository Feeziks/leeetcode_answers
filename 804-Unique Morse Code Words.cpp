class Solution
{
  public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
      
      const std::string morseAlphabet[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
      std::map<std::string, int> transformations;
      for(auto w : words)
      {
        std::string thisTransform = "";
        for(char& c: w)
        {
          thisTransform += morseAlphabet[c - 'a'];
        }
        transformations[thisTransform]++;
      }
      return transformations.size();
    }
};