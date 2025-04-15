class Solution {
public:
// First approach - checks inside the inner loop
/*
    vector<int> getAverages(vector<int>& nums, int k)
    {
        // Low hanging fruits
        if(k == 0)
        {
            return nums;
        }   
        vector<int> ret(nums.size(), -1);  
        if(k >= nums.size() / 2)
        {
            return ret;
        }   
        for(int i = 0; i < nums.size(); i++)
        {
            int avg = 0;
            for(int j = -k; j <= k; j++)
            {
                std::cout << "i: " << i << "   k: " << k << "    j: " << j << "\n";
                if(i + j < 0 || i + j >= nums.size())
                {
                    //ret[i] = -1;
                    avg = -1;
                    break;
                }
                avg += nums[i+j];
            }
            if(avg != -1)
            {
                avg = avg / (k * 2 + 1);
                ret[i] = avg;
            }
        }
        return ret;
    }
*/
// Second approach checks outside the inner loop to reduce unecessary computations
/*
    vector<int> getAverages(vector<int>& nums, int k)
    {
        // Low hanging fruits
        if(k == 0)
        {
            return nums;
        }   
        vector<int> ret(nums.size(), -1);  
        if(k >= nums.size() / 2)
        {
            return ret;
        } 

        for(int i = k; i < nums.size() - k; i++)
        {
            if(i - k < 0 || i + k >= nums.size())
            {
              continue;
            }
            int avg = 0;
            for(int j = -k; j <= k; j++)
            {
                avg += nums[i+j];
            }

            avg = avg / (k * 2 + 1);
            ret[i] = avg;
        }
        return ret;
    }
*/
// Third approach sliding window - the previous approach gets time limit exceeded
vector<int> getAverages(vector<int>& nums, int k)
    {
        // Low hanging fruits
        if(k == 0)
        {
            return nums;
        }   
        vector<int> ret(nums.size(), -1);  
        long window_sum = 0;
        int window_size = 2 * k + 1;
        if(window_size > nums.size())
        {
            return ret;
        } 
        // "Prime" the sliding window by getting the first average
        for(int i = 0; i < window_size; i++)
        {
          window_sum += nums[i];
        }
        ret[k] = window_sum / window_size;

        for(int i = window_size; i < nums.size(); i++)
        {
          // Remove the element that slide off the front of the window
          window_sum = window_sum - nums[ i - window_size];
          // Add the element at the end of the window
          window_sum = window_sum + nums[i];
          // Average them and save that value
          ret[i - k] = window_sum / window_size;
        }
        return ret;
    }

};