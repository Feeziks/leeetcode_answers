class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int len = arr.size();
        int ret = -1;

        int left = 0;
        int right = len;
        int idx;

        if(len == 3)
            return 1;

        //std::cout << "length: " << len << "\n";
        //for(int i = 0; i < len; i++)
        //{
            //std::cout << "arr[" << i << "]: " << arr[i] << "\n";
        //}

        while(ret == -1)
        {
            idx = left + (right - left) / 2;
            if(idx == 0)
            {
                idx = 1;
            }
            if(idx == len)
            {
                idx--;
            }

            //std::cout << "idx: " << idx << "    arr[idx - 1]: " << arr[idx - 1] << "    arr[idx]: " << arr[idx] << "    arr[idx + 1]: " << arr[idx+1] << "\n";

            if(arr[idx] > arr[idx - 1] && arr[idx] > arr[idx + 1])
            {
                ret = idx;
            }
            else
            {
                // Do we need to move right or left?
                if(arr[idx] < arr[idx + 1]) // move right
                {
                    left = idx + 1;
                }
                else // Move left
                {
                    right = idx - 1;
                }
            }
        }
        return ret;
    }
};