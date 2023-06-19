class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int current = 0;
        int max_altitude = INT_MIN;
        for(int i = 0; i < gain.size(); i++)
        {
            current += gain[i];
            max_altitude = max(max_altitude, current);
        }
        // Initial altitude is 0 so a negative value cannot be the max value
        if(max_altitude < 0)
            max_altitude = 0;
        return max_altitude;   
    }
};