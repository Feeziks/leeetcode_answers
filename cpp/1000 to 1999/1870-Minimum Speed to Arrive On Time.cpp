class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int n = dist.size();
        if(hour <= n - 1)
        {
            return -1.0;
        }
        return binary_search(1, 1e7, dist, n, hour);
    }

    int binary_search(int left, int right, vector<int>& dist, int n, double hour)
    {
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            double time = 0.0;
            for(int i = 0; i < n - 1; i++)
            {
                time += ceil((double)dist[i] / mid);
            }
            time += (double)dist[n-1] / mid;

            if(time <= hour)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};