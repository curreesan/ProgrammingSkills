#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int end = s.size() - 1;

    while (end >= 0 && s[end] == ' ')
    {
      end--;
    }

    int start = end;
    while (start >= 0 && s[start] != ' ')
    {
      start--;
    }

    return end - start;
  }
};

int main()
{
  Solution sol;
  int result = sol.lengthOfLastWord("   fly me   to   the moon  ");
  cout << result << endl;
}