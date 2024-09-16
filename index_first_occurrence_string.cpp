#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    int hLength = haystack.length();
    int nLength = needle.length();

    if (hLength < nLength)
      return -1;

    for (int i = 0; i < hLength; i++)
    {
      if (haystack.substr(i, nLength) == needle)
        return i;
    }
    return -1;
  }
};

int main()
{
  Solution sol;
  int result = sol.strStr("leetcode", "leeto");
  cout << result << endl;

  return 0;
}