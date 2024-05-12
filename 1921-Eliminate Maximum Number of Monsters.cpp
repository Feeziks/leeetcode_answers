class Solution
{
public:

    struct monsterData_t
    {
        int dist;
        int speed;
        float arrivalTime;
    };

    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        // Get the arrival times of all monsters
        std::vector<monsterData_t> monsters;
        for(int i = 0; i < dist.size(); i++)
        {
            monsterData_t tmp;
            tmp.dist = dist[i];
            tmp.speed = speed[i];
            tmp.arrivalTime = (float)tmp.dist / (float)tmp.speed;
            monsters.push_back(tmp);
        }

        print(monsters);

        return 0;


        std::vector<int> arrivalTimes;
        for(int i = 0; i < dist.size(); i++)
        {
            arrivalTimes.push_back(dist[i]/speed[i]);
        }
        // Sort least to greatest
        print(arrivalTimes);
        std::sort(arrivalTimes.begin(), arrivalTimes.end());
        print(arrivalTimes);
        // We start with weapon charged - remove the first entry
        int monstersEliminated = 1;
        arrivalTimes.erase(arrivalTimes.begin());
        int currTime = 0;
        bool alive = arrivalTimes[0] > currTime;

        while(alive)
        {
            currTime++;
            std::cout << "Looping\n\t";
            print(arrivalTimes);
            std::cout << "\tcurrTime: " << currTime << " arrivalTimes[0]: " << arrivalTimes[0];
            if(arrivalTimes[0] > currTime)
            {
                arrivalTimes.erase(arrivalTimes.begin());
                // Was this the last monster?
                if(arrivalTimes.empty())
                {
                    std::cout << " last monster eliminated\n";
                    monstersEliminated++;
                    break;
                }

                std::cout << " new arrivalTimes[0]: " << arrivalTimes[0];

                // see if another monster has the same arrival time
                if(arrivalTimes[0] <= currTime)
                {
                    std::cout << " another monster arrived at the same time\n";
                    alive = false;
                }
                else
                {
                    std::cout << " ending this loop\n";
                    alive = true;
                    monstersEliminated++;
                }
            }
            else
            {
                std::cout << " You died\n";
                alive = false;
            }
        }
        

        return monstersEliminated;
    }

    void print(std::vector<int> &v)
    {
        for(auto x : v)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    void print(std::vector<monsterData_t> &v)
    {
        for(auto x : v)
        {
            std::cout << "dist: " << x.dist << " speed: " << x.speed << " arrivalTime: " << x.arrivalTime << "\n";
        }
    }
};