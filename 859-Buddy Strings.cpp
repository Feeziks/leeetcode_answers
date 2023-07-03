class Solution {
public:
    bool buddyStrings(string s, string goal)
    {
        if(s.length() != goal.length())
        {
            return false;
        }

        if(s == goal)
        {
            std::set<char> temp(s.begin(), s.end()); // Get the unique chars from the string s
            return temp.size() < goal.size(); // See if there are less unique characters than the tota length of the string, if so we can freely swap any matching chars
        }

        // Two pointer approach
        int left = 0;
        int right = goal.length() - 1;

        while(left < right && s[left] == goal[left])
        {
            left++;
        }

        while(right >= 0 && s[right] == goal[right])
        {
            right--;
        }

        if(left < right)
        {
            std::swap(s[left],s[right]);
        }

        return s == goal;
    }
};