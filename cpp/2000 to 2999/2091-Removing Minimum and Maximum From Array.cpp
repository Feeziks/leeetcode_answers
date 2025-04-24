class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        // Get low hanging fruit first
        if(nums.size() <= 2)
        {
            return nums.size();
        }
        if(nums.size() == 3)
        {
            // You can always complete a vector of size 3 with 2 deletions
            return 2;
        }

        int num_delete = 0;
        // First approach
        // Iterate over the vector
        // Finding the min and max values
        // Store the indicies of those values
        // Calculate the offset from the front / end of the vector for each 
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int min_idx = -1;
        int max_idx = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < minimum)
            {
                min_idx = i;
                minimum = nums[i];
            }
            if(nums[i] > maximum)
            {
                max_idx = i;
                maximum = nums[i];
            }
        }

        // Find the offsets of each idx from the start and the end of the vector
        // The offset from the start is just the idx, from the end is size - idx
        int min_offset = nums.size() - min_idx;
        int max_offset = nums.size() - max_idx;

        // Which value of the offsets is lowest? We want to remove that value first
        int offset_min = std::min({min_idx, min_offset, max_idx, max_offset});

        if(offset_min == min_idx)
        {
            // Remove min first starting from index 0, +1 is to include idx 0
            num_delete += min_idx + 1;

            // Now see if the max is closer to the updated front, or the end
            max_idx = max_idx - num_delete;
            if(max_idx < max_offset)
            {
                // Remove from the front till the new max
                num_delete += max_idx + 1;
            }
            else
            {
                // Remove from the back till the new max
                num_delete += max_offset;
            }
        }
        else if(offset_min == min_offset)
        {
            // Remove the min starting from the end
            num_delete += min_offset;
            // Now see if the max is closer to the updated end, or the front
            max_offset = nums.size() - num_delete - max_idx;
            if(max_idx < max_offset)
            {
                num_delete += max_idx + 1;
            }
            else
            {
                num_delete += max_offset;
            }
        }
        else if(offset_min == max_idx)
        {
            // Remove max first starting from index 0, +1 is to include idx 0
            num_delete += max_idx + 1;

            // Now see if the min is closer to the updated front, or the end
            min_idx = min_idx - num_delete;
            if(min_idx < min_offset)
            {
                // Remove from the front till the new max
                num_delete += min_idx + 1;
            }
            else
            {
                // Remove from the back till the new max
                num_delete += min_offset;
            }
        }
        else
        {
            // Remove the max starting from the end
            num_delete += max_offset;
            // Now see if the max is closer to the updated end, or the front
            min_offset = nums.size() - num_delete - min_idx;
            if(min_idx < min_offset)
            {
                num_delete += min_idx + 1;
            }
            else
            {
                num_delete += min_offset;
            }
        }
        
        
        return num_delete;
    }
};