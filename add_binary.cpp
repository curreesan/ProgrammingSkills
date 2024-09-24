#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    int aI = a.size() - 1;
    int bI = b.size() - 1;
    int carry = 0;

    string output = "";

    while (bI >= 0 || aI >= 0 || carry)
    {
      int sum = carry;
      if (aI >= 0)
        sum += a[aI] - '0';
      if (bI >= 0)
        sum += b[bI] - '0';

      carry = sum / 2;
      int current = sum % 2;
      output.push_back(current + '0');

      aI--;
      bI--;
    }

    reverse(output.begin(), output.end());
    return output;
  }
};

int main()
{
  Solution sol;
  string result = sol.addBinary("111", "11");
  cout << result << endl;
}
