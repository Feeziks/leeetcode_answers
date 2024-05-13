class Solution
{
public:

    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        std::vector<float> arrivalTimes;
        for(int i = 0; i < dist.size(); i++)
        {
            arrivalTimes.push_back((float)dist[i] / float(speed[i]));
        }
        std::sort(arrivalTimes.begin(), arrivalTimes.end());
        int monstersEliminated = 0;
        for(int i = 0; i < arrivalTimes.size(); i++)
        {
            //std::cout << "i " << i << " arrivalTimes[i] " << arrivalTimes[i] << "\n";
            if(arrivalTimes[i] <= (float)i)
            {
                break;
            }
            monstersEliminated++;
        }

        return monstersEliminated;
    }
};