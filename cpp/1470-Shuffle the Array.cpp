class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> ret;
        int n1 = 0;
        int n2 = n;

        for(int i = 0; i < n; i++)
        {
            ret.push_back(nums[n1++]);
            ret.push_back(nums[n2++]);
        }

        return ret;
    }
};