#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  double average(vector<int> &salary)
  {
    int max = salary[0], min = salary[0];
    int sum = 0;
    for (int i = 0; i < salary.size(); i++)
    {
      max = (max < salary[i]) ? salary[i] : max;
      min = (min > salary[i]) ? salary[i] : min;
      sum += salary[i];
    }
    return double((sum - max - min) / (salary.size() - 2));
  }
};

int main()
{
  vector<int> sal = {4000, 3000, 1000, 2000};
  Solution sol;
  double result = sol.average(sal);
  cout << result << endl;
}