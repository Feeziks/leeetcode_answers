class Solution {
public:
    int maximumCount(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int pos_count = 0;
        int neg_count = 0;

        while(left <= right)
        {
            if(nums[left] < 0)
            {
                neg_count++;
                left++;
            }
            else if(nums[right] > 0)
            {
                pos_count++;
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }

        return max(pos_count, neg_count);
    }
};