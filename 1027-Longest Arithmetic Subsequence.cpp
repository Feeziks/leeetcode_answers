class Solution {
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 2)
        {
            return size;
        }

        int max_length = 2;
        vector<map<int, int>> sequences(size);

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                // Get the difference between the values to find which map it goes into
                int diff = nums[i] - nums[j];
                if(sequences[j].count(diff) != 0)
                {
                    sequences[i][diff] = sequences[j][diff] + 1;
                }
                else
                {
                    // 2 because its the previous value plus the value of i
                    sequences[i][diff] = 2;
                }

                max_length = max(max_length, sequences[i][diff]);
            }
        }


        return max_length;
    }
};