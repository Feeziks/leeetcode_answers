class Solution {
private:
    int depth_first_search(int idx, int prev, vector<int> &arr1, vector<int> &arr2, map<pair<int, int>, int> &dp)
    {
        //Base case
        if(idx == arr1.size()) {
            return 0;
        }

        //Explore all paths;
        if(dp.find({idx, prev}) != dp.end()) {
            return dp[{idx, prev}];
        }
        int replace = 1e9, not_replace = 1e9;

        //Replace
        int i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(i < arr2.size()) {
            replace = 1 + depth_first_search(idx + 1, arr2[i], arr1, arr2, dp);            
        }

        //Not replace
        if(arr1[idx] > prev) {
            not_replace = depth_first_search(idx + 1, arr1[idx], arr1, arr2, dp);
        }

        return dp[{idx, prev}] = min(replace, not_replace);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        map<pair<int, int>, int> dp;
        vector<int> sorted_arr2 = arr2;
        sort(sorted_arr2.begin(), sorted_arr2.end());
        int res = depth_first_search(0, -1, arr1, sorted_arr2, dp);
        return res >= 1e9 ? -1 : res;
    }
};