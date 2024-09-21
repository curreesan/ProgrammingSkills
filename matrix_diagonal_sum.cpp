#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int diagonalSum(vector<vector<int>> &mat)
  {
    int sum = 0;
    int length = mat.size();

    for (int i = 0; i < length; i++)
    {

      sum += (mat[i][i] + mat[i][length - 1 - i]);
    }

    if (length % 2 != 0)
    {
      sum -= mat[length / 2][length / 2];
    }
    return sum;
  }
};

int main()
{
  vector<vector<int>> mat = {{5}};

  Solution sol;
  int result = sol.diagonalSum(mat);
  cout << result << endl;
}

/*
O(n*n)

class Solution
{
public:
  int diagonalSum(vector<vector<int>> &mat)
  {
    int sum = 0;
    for (int i = 0; i < mat.size(); i++)
    {
      for (int j = 0; j < mat[i].size(); j++)
      {
        if (i == j)
        {
          sum += mat[i][j];
        }
        if (i == 2 - j)
        {
          sum += mat[i][j];
        }
      }
    }
    if (mat.size() % 2 != 0)
    {
      int mid = (mat.size() + 1) / 2;
      return sum - mat[mid][mid];
    }
    return sum;
  }
};

*/