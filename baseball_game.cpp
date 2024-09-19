#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int calPoints(vector<string> &operations)
  {
    vector<int> record;

    for (auto i : operations)
    {
      if (i != "+" && i != "D" && i != "C")
      {
        record.push_back(stoi(i));
      }
      else if (i == "C")
      {
        record.pop_back();
      }
      else if (i == "D")
      {
        record.push_back(2 * (record.back()));
      }
      else if (i == "+")
      {
        record.push_back(record[record.size() - 1] + record[record.size() - 2]);
      }
    }
    int count = 0;
    for (int i : record)
    {
      count += i;
    }
    return count;
  }
};

int main()
{
  vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  Solution sol;
  int result = sol.calPoints(ops);
  cout << result << endl;
}
