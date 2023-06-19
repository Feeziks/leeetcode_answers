class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        vector<int> altitudes;
        int current = 0;
        for(int i = 0; i<gain.size(); i++)
        {
          altitudes.push_back(current);
          current = current + gain[i];
        }
        altitudes.push_back(current);
        return *max_element(altitudes.begin(),altitudes.end());
    }
};