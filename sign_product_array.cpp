#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int arraySign(vector<int> &nums)
  {
    int negative_count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        return 0;
      if (nums[i] < 0)
      {
        negative_count++;
      }
    }
    return (negative_count % 2 == 0) ? 1 : -1;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {-1, 1, 0};

  int result = sol.arraySign(arr);
  cout << result << endl;
}

// class Solution {
//     int signFunc(int product)  {
//         if (product > 0) {
//             return 1;
//         } else if (product < 0) {
//             return -1;
//         }
//         return product;
//     }
// public:
//     int arraySign(vector<int>& nums) {
//         int product = 1;

//         for (int i=0; i < nums.size(); i++) {
//             if (nums[i] == 0) return 0;

//             if (nums[i] > 0)
//             {
//                 nums[i] = 1;
//             }
//             else
//             {
//             nums[i] = -1;
//             }
//         }

//         for (int i=0; i < nums.size(); i++) {
//             product *= nums[i];
//         }

//      return signFunc(product);
//     }
// };