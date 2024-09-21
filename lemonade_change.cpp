#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{

public:
  bool lemonadeChange(vector<int> &bills)
  {
    int count5 = 0;
    int count10 = 0;
    for (int i = 0; i < bills.size(); i++)
    {
      if (bills[i] == 5)
      {
        count5++;
      }
      else if (bills[i] == 10)
      {
        count5--;
        count10++;
        if (count5 < 0)
        {
          return false;
        }
      }
      else
      {
        if (count10 >= 1 && count5 >= 1)
        {
          count10--;
          count5--;
        }
        else if (count5 >= 3)
        {
          count5 -= 3;
        }
        else
          return false;
      }
    }
    return true;
  }
};

int main()
{
  vector<int> bills = {5, 5, 5, 10, 20};
  Solution sol;
  bool result = sol.lemonadeChange(bills);
  cout << result << endl;
}