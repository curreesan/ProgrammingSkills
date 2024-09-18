#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canMakeArithmeticProgression(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());

    for (int i = 1; i < arr.size() - 1; i++)
    {
      if ((2 * arr[i]) != (arr[i - 1] + arr[i + 1]))
        return false;
    }
    return true;
  }
};

int main()
{
  vector<int> nums = {1, 2, 4};
  Solution sol;
  bool result = sol.canMakeArithmeticProgression(nums);
  cout << result << endl;
}

/*
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[0] - arr[1];

        for (int i=0; i < arr.size()-1; i++) {
            if (diff != (arr[i] - arr[i+1])) return false;
        }
        return true;

    }
};
*/
