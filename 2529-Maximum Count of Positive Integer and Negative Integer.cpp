class Solution {
public:
    int maximumCount(vector<int>& nums)
    {
        int first_pos = binary_search_positive(nums);
        int first_neg = binary_search_negative(nums);
        std::cout << first_pos << " " << first_neg << "\n";
        if(first_pos == -1 && first_neg == -1)
        {
            return 0;
        }
        if(first_pos != -1)
        {
            if(nums.size() - first_pos > first_neg + 1)
            {
                return nums.size() - first_pos;
            }
        }
        if(first_neg + 1 < nums.size())
        {
            return first_neg + 1;
        }
        return nums.size();
    }

private:
    int binary_search_positive(std::vector<int>& vec)
    {
        int left = 0;
        int right = vec.size() - 1;

        while (left <= right) {
            std::cout << left << "   " << right << "\n";
            int mid = left + (right - left) / 2;
            if(mid == 0 && vec[mid] > 0)
                return mid;

            if (vec[mid] > 0 && vec[mid - 1] <= 0)
            {
                return mid;  // Found the target
            }
            else if (vec[mid] < 0 || vec[mid] == 0)
            {
                left = mid + 1;  // Search the right half
            } else {
                right = mid - 1;  // Search the left half
            }
        }

        return -1;  // Target not found
    }

    int binary_search_negative(std::vector<int>& vec)
    {
        int left = 0;
        int right = vec.size() - 1;

        while (left <= right) {
            std::cout << left << "   " << right << "\n";
            int mid = left + (right - left) / 2;
            if(mid == vec.size() - 1 && vec[mid] < 0)
                return mid;

            if (vec[mid] < 0 && vec[mid + 1] >= 0)
            {
                return mid;  // Found the target
            }
            else if (vec[mid] < 0)
            {
                left = mid + 1;  // Search the right half
            }
            else
            {
                right = mid - 1;  // Search the left half
            }
        }

        return -1;  // Target not found
    }
};