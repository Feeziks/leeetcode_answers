#include <vector>
#include <iostream>


class Solution
{
private:
  bool doEventsOverlap(const std::vector<int> &event1, const std::vector<int> &event2)
  {
    bool ret = false;
    const int startTimeIdx = 0;
    const int endTimeIdx = 1;
    if(event2[startTimeIdx] <= event1[startTimeIdx] && event2[endTimeIdx] >= event1[startTimeIdx])
    {
      ret = true;
    }
    if(event2[startTimeIdx] >= event1[startTimeIdx] && event2[startTimeIdx] <= event1[endTimeIdx])
    {
      ret = true;
    }
    if(event1[startTimeIdx] <= event2[startTimeIdx] && event2[endTimeIdx] >= event2[startTimeIdx])
    {
      ret = true;
    }

    return ret;
  }

public:
  // This is from the editorial
  int maxTwoEvents(vector<vector<int>>& events)
  {
    vector<array<int, 3>> times;
    for (auto& e : events) {
        // 1 denotes start time.
        times.push_back({e[0], 1, e[2]});
        // 0 denotes end time.
        times.push_back({e[1] + 1, 0, e[2]});
    }
    int ans = 0, maxValue = 0;
    sort(begin(times), end(times));
    for (auto& timeValue : times) {
        // If current time is a start time, find maximum sum of maximum end
        // time till now.
        if (timeValue[1]) {
            ans = max(ans, timeValue[2] + maxValue);
        } else {
            maxValue = max(maxValue, timeValue[2]);
        }
    }
    return ans;
 }

  int maxTwoEventsGreedy(std::vector<std::vector<int>> & events)
  {
    // I did not finish this in the time I alloted myself before moving on
    int maxValue = 0;
    std::vector<std::vector<int>> time;
    // build the vector time
    for(int i = 0; i < events.size(); i++)
    {
      std::cout << "events[" << i << "][1] " << events[i][1] << " ";
      if(events[i][1] > time.size())
      {
        time.resize(events[i][1] + 2);
      }
      std::cout << "time.size() " << time.size() << "\n";
      for(int j = events[i][0]; j <= events[i][1]; j++)
      {
        std::cout << "j " << j << "\n";
        time[j].push_back(i);
      }
    }

    for(int t = 1; t < time.size(); t++)
    {
        std::cout << "time " << t << " events are ";
        for(int i = 0; i < time[t].size(); i++)
        {
            std::cout << time[t][i] << ", ";
        }
        std::cout << "\n";
    }

    return maxValue;
  }

  int maxTwoEventsNsq(vector<vector<int>>& events)
  {
    int maxValue = 0;
    for(int i = 0; i < events.size(); i++)
    {
      int event1Start = events[i][0];
      int event1End = events[i][1];
      int event1Value = events[i][2];
      // Is going to just this single event our highest value?
      maxValue = std::max(maxValue, event1Value);
      for(int j = 0; j < events.size(); j++)
      {
        if( i == j)
        {
          continue;
        }
        // Do we have a collision in time?
        int event2Start = events[j][0];
        int event2End = events[j][1];
        int event2Value = events[j][2];

        if(!doEventsOverlap(events[i], events[j]))
        {
            maxValue = std::max(maxValue, event1Value + event2Value);
        }
      }
    }
    return maxValue;
  }
};