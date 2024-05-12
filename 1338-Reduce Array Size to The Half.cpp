class Solution
{
public:
    int minSetSize(vector<int>& arr)
    {
        std::map<int, int> counts;
        int totalSize = arr.size();
        for(int i = 0; i < arr.size(); i++)
        {
            counts[arr[i]] += 1;
        }
/*
        for(auto x : counts)
        {
            //std::cout << x.first << ", " << x.second << "\n";
        }
*/
        int desiredSize = arr.size() / 2;
        int numRemovals = 0;
        //std::cout << "Array size: " << arr.size() << " desiredSize: " << desiredSize << "\n";
        while(totalSize > desiredSize)
        {
            //std::cout << "Looping\n";
            int temp = 0;
            int tempKey = 0;
            for(auto x : counts)
            {
                if(x.second > temp)
                {
                    temp = x.second;
                    tempKey = x.first;
                }
            }
            //std::cout << "\tRemoving key: " << tempKey << " with " << tempKey << " entries\n";
            counts.erase(tempKey);
            totalSize -= temp;
            numRemovals++;
            //std::cout << "\tRemaining values in array: " << totalSize << "\n";
            //std::cout << "\tDesired values in array: " << desiredSize << "\n";
        }

        return numRemovals;
    }
};