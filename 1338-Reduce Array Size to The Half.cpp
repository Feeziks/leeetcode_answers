class Solution
{
public:
    int minSetSize(vector<int>& arr)
    {
        std::unordered_map<int, int> counts;
        int totalSize = arr.size();
        for(int i = 0; i < arr.size(); i++)
        {
            counts[arr[i]] += 1;
        }

        std::vector<int> sorting;
        for(auto [_, cnt] : counts)
        {
            sorting.push_back(cnt);
        }
        std::sort(sorting.begin(), sorting.end());

        int desiredSize = arr.size() / 2;
        int numRemovals = 0;
        int i = sorting.size() - 1;
        //std::cout << "Array size: " << arr.size() << " desiredSize: " << desiredSize << "\n";
        while(totalSize > desiredSize)
        {
            //std::cout << "Looping\n";
            
            numRemovals++;
            totalSize -= sorting[i--]; // Remove the highest freq values which are at the end of the sorted list

            //std::cout << "\tRemaining values in array: " << totalSize << "\n";
            //std::cout << "\tDesired values in array: " << desiredSize << "\n";
        }

        return numRemovals;
    }
};