class Solution {
public:
    double myPow(double x, int n)
    {
        double ret = 1.0;
        if(n == 0)
        {
            return 1.0;
        }
        for(int i = n; i; i/=2)
        {
            if(i  & 1)
                ret *= x;
            x *= x;
        }
        if(n >= 0.0)
        {
            return ret;
        }
        else
        {
            return 1 / ret;
        }
    }
};