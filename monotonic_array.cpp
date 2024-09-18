#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isMonotonic(vector<int> &nums)
  {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] < nums[i + 1])
      {
        decreasing = false;
      }
      if (nums[i] > nums[i + 1])
      {
        increasing = false;
      }
    }

    return increasing || decreasing;
  }
};

int main()
{
  vector<int> arr = {1, 3, 2};
  Solution sol;
  bool result = sol.isMonotonic(arr);
  cout << result << endl;
}

/*
class Solution {
    int increasingCheck(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) return false;
        }
        return true;
    }

    int decreasingCheck(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) return false;
        }
        return true;
    }
 public:
    bool isMonotonic(vector<int>& nums) {
        return (nums[0] < nums.back()) ? increasingCheck(nums) : decreasingCheck(nums);
    }
};
*/