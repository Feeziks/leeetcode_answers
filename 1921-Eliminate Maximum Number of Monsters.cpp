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

        int monstersEliminated = 0;
        int currTime = 0;
        bool alive = true;
        while(alive)
        {
            //print(monsters);
            // Eliminate the closest monster
            float minArrivalTime = std::numeric_limits<float>::max();
            int minIdx = -1;
            for(int i = 0; i < monsters.size(); i++)
            {
                // check if we are already dead
                if(monsters[i].arrivalTime <= currTime)
                {
                    alive = false;
                    break;
                }

                if(monsters[i].arrivalTime < minArrivalTime)
                {
                    minArrivalTime = monsters[i].arrivalTime;
                    minIdx = i;
                }
            }
            if(!alive)
            {
                break;
            }

            //std::cout << "currTime " << currTime << " Removing the monster at index " << minIdx << " which has an arrival time of " << minArrivalTime << "\n";

            // Remove the monster at the minimum time
            monsters.erase(monsters.begin() + minIdx);
            monstersEliminated++;
            // increment the time for the next iteration
            currTime++;
            //check if we are out of monsters
            if(monsters.empty())
            {
                break;
            }
        }
        return monstersEliminated;
    }

    void print(std::vector<monsterData_t> &v)
    {
        for(auto x : v)
        {
            std::cout << "dist: " << x.dist << " speed: " << x.speed << " arrivalTime: " << x.arrivalTime << "\n";
        }
    }
};