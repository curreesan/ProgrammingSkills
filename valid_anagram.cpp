#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    unordered_map<char, int> smap;
    unordered_map<char, int> tmap;

    for (int i = 0; i < s.size(); i++)
    {
      smap[s[i]]++;
      tmap[t[i]]++;
    }
    for (auto &pair : smap)
    {
      if (pair.second != tmap[pair.first])
      {
        return false;
      }
    }
    return true;
  }
};
int main()
{
  Solution sol;
  bool result = sol.isAnagram("carrace", "racecar");
  cout << result << endl;
}