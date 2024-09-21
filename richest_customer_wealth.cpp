#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int maximumWealth(vector<vector<int>> &accounts)
  {
    int maxWealth = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
      int iWealth = 0;
      for (int j = 0; j < accounts[i].size(); j++)
      {
        iWealth += accounts[i][j];
      }
      maxWealth = (maxWealth < iWealth) ? iWealth : maxWealth;
    }
    return maxWealth;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
  int result = sol.maximumWealth(accounts);
  cout << result << endl;
}

/*
in built spam
class Solution
{
public:
  int maximumWealth(vector<vector<int>> &accounts)
  {
    int m = 0;

    for (auto& acc: accounts) {
        m = max(m, accumulate(acc.begin(), acc.end(), 0));
    }

    return m;
  }
};
*/