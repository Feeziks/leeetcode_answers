class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int ret = -1;

        //Get all values and their counts
        std::map<int, int> valCounts;
        int maxVal = 0;
        for(auto x : nums)
        {
            if(x > maxVal)
            {
                maxVal = x;
            }
            valCounts[x]++;
        }

        int specialNum = 0;
        int thisCount = 0;

        while(specialNum <= maxVal)
        {
            for(auto const& x : valCounts)
            {
                if(x.first >= specialNum)
                {
                    thisCount += x.second;
                }

                std::cout << "specialNum = " << specialNum << " thisCount = " << thisCount << " x.first == " << x.first << " x.second = " << x.second << "\n";

                if(thisCount > specialNum)
                {
                    break;
                }
            }

            if(thisCount == specialNum)
            {
                ret = specialNum;
                break;
            }
            else
            {
                thisCount = 0;
                specialNum++;
            }
        }

        return ret;
    }
};