class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        int ret = 0;
        std::vector<int> sorted_arr2 = arr2;
        std::sort(sorted_arr2.begin(), sorted_arr2.end());

        int arr2_start = 0;
        bool replaced = false;
        std::cout << "Doing the work\n";
        // Iterate arr1
        for(int i = 0; i < arr1.size(); i++)
        {
            std::cout << "i: " << i << "\t";
            if(i == 0)
            {
                if(arr1[i] < arr1[i+1])
                {
                    std::cout << "is increasing\n";
                    continue;
                }
            }
            else if(i == arr1.size() - 1)
            {
                if(arr1[i] > arr1[i - 1])
                {
                    std::cout << "is increasing\n";
                    continue;
                }
            }
            else
            {
                if(arr1[i] < arr1[i + 1] && arr1[i] > arr1[i - 1])
                {
                    std::cout << "is increasing\n";
                    continue;
                }
            }
            // See if we are strictly increasing currently
            std::cout << "is not increasing, checking arr2 for a replacement\n";
            // Otherwise we need to find a replacement in arr2 that is the smallest strictly larger value for arr1[i+1]
            for(int j = arr2_start; j < sorted_arr2.size(); j++)
            {
                if(i == 0)
                {
                    if(sorted_arr2[j] < arr1[i + 1])
                    {
                        std::cout << "found replacement arr1[i]: " << arr1[i] << "\tarr1[i+1]: " << arr1[i+1] << "\tsorted_arr2[j]: " << sorted_arr2[j] <<"\n";
                        //std::swap(arr1[i], sorted_arr2[j]);
                        arr1[i] = sorted_arr2[j];
                        arr2_start = 0; //j-1;
                        ret++;
                        replaced = true;
                        break;
                    }
                }
                else
                {
                    if(sorted_arr2[j] > arr1[i - 1])
                    {
                        std::cout << "found replacement arr1[i]: " << arr1[i] << "\tarr1[i-1]: " << arr1[i-1] << "\tsorted_arr2[j]: " << sorted_arr2[j] <<"\n";
                        //std::swap(arr1[i], sorted_arr2[j]);
                        arr1[i] = sorted_arr2[j];
                        arr2_start = 0; //j-1;
                        ret++;
                        replaced = true;
                        break;
                    }
                }
            }
            /*
            if(!replaced)
            {
                std::cout << "No replacment found\n";
                return -1;
            }
            replaced = false;
            */
        }
        std::cout << "After the work is done\n";
        // See if arr1 is strictly increasing
        for(int i = 0; i < arr1.size(); i++)
        {
            std::cout << arr1[i] << "\n";
        }

        return ret;
        
    }
};