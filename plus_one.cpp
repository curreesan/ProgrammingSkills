#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    for (int i = digits.size() - 1; i >= 0; i--)
    {
      if (digits[i] + 1 != 10)
      {
        digits[i] += 1;
        return digits;
      }
      digits[i] = 0;
      if (i == 0)
      {
        digits.insert(digits.begin(), 1);
        return digits;
      }
    }
    return digits;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {9, 9};
  vector<int> result = sol.plusOne(arr);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }
  return 0;
}