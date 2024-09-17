#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
      if (nums[right] != 0)
      {
        swap(nums[right], nums[left]);
        left++;
      }
    }
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 1, 0, 3, 12};
  sol.moveZeroes(arr);

  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << endl;
  }
}