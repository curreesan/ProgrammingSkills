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

int main()
{
  Solution sol;
  int result = sol.countOdds(3, 7);
  cout << result << endl;
}