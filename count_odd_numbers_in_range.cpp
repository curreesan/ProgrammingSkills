#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int countOdds(int low, int high)
  {
    int oddNumbers = (high - low) / 2;
    if (high % 2 == 0 && low % 2 == 0)
    {
      return oddNumbers;
    }
    return oddNumbers + 1;
  }
};

int main()
{
  Solution sol;
  int result = sol.countOdds(3, 7);
  cout << result << endl;
}

/*
Brute Force
class Solution
{
public:
  int countOdds(int low, int high)
  {
    int count = 0;
    for (int i = low; i < high + 1; i++)
    {
      if (i % 2 != 0)
      {
        count++;
      }
    }
    return count;
  }
};

*/