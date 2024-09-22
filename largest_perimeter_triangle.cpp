#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int largestPerimeter(vector<int> &nums)
  {
    sort(nums.begin(), nums.end(), greater<int>());
    int n = nums.size();
    int largestP = 0;

    for (int i = 2; i < n; i++)
    {
      int high = nums[i - 2];
      int mid = nums[i - 1];
      int low = nums[i];

      if (mid + low > high)
      {
        int perimeter = mid + low + high;
        largestP = (largestP < perimeter) ? perimeter : largestP;
      }
    }
    return largestP;
  }
};

int main()
{
  vector<int> nums = {2, 1, 2};
  Solution sol;
  int result = sol.largestPerimeter(nums);
  cout << result << endl;
}