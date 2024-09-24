#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  int checkSlope(int x1, int x2, int y1, int y2)
  {
    if (x1 == x2)
    {
      return INT_MAX;
    }
    else
    {
      return (y2 - y1) / (x2 - x1);
    }
  }

public:
  bool checkStraightLine(vector<vector<int>> &coordinates)
  {
    int n = coordinates.size();

    if (n == 2)
      return true;

    int slope = checkSlope(coordinates[0][0], coordinates[1][0], coordinates[0][1], coordinates[1][1]);

    for (int i = 2; i < n; i++)
    {
      int x1 = coordinates[i - 1][0];
      int x2 = coordinates[i][0];

      int y1 = coordinates[i - 1][1];
      int y2 = coordinates[i][1];

      if (slope != checkSlope(x1, x2, y1, y2))
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  vector<vector<int>> coord = {
      {1, 2},
      {2, 3},
      {3, 4},
      {4, 5},
      {5, 6},
      {6, 7}};
  Solution sol;
  bool result = sol.checkStraightLine(coord);
  cout << result << endl;
}