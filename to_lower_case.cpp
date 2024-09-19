#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string toLowerCase(string s)
  {
    for (int i = 0; i <= s.size(); i++)
    {
      if (s[i] <= 90 && s[i] >= 65)
      {
        s[i] += 32;
      }
    }
    return s;
  }
};

int main()
{
  Solution sol;
  string result = sol.toLowerCase("EVEr Since I wAs a JIT , knEW i wAs tHe SH*T");
  cout << result << endl;
}

/*
tolower() to convert to lowercase
*/