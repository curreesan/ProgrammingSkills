#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  bool judgeCircle(string moves)
  {
    vector<int> initialPosition = {0, 0};
    vector<int> finalPosition = {0, 0};

    for (char i : moves)
    {
      if (i == 'U')
      {
        finalPosition[1]++;
      }
      else if (i == 'D')
      {
        finalPosition[1]--;
      }
      else if (i == 'R')
      {
        finalPosition[0]++;
      }
      else if (i == 'L')
      {
        finalPosition[0]--;
      }
    }
    return initialPosition == finalPosition;
  }
};

int main()
{
  Solution sol;
  bool result = sol.judgeCircle("UD");
  cout << result << endl;
}

/*
Using map

class Solution {
public:
    bool judgeCircle(string moves) {
        map<int,int>mp;
        for(int i=0;i<moves.size();i++){
            mp[moves[i]]++;
        }

        if(mp['R']!=mp['L'])return false;
        if(mp['U']!=mp['D'])return false;
        return true;
    }
};
*/