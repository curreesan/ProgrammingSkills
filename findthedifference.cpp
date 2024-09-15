#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    unordered_map<char, int> map_s;
    unordered_map<char, int> map_t;

    for (int i = 0; i < s.length(); i++)
    {
      map_s[s[i]] += 1;
    }

    for (int j = 0; j < t.length(); j++)
    {
      map_t[t[j]] += 1;
    }

    for (const auto &pair : map_t)
    {
      if (pair.second != map_s[pair.first])
      {
        return pair.first;
      }
    }
    return '\0';
  }
};

int main()
{
  Solution sol;
  char result = sol.findTheDifference("abcd", "abcde");
  cout << result << endl;
  return 0;
}

// Using 2 loops
// Subtracting values from s string in hashmap t
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    unordered_map<char, int> map_t;

    for (int j = 0; j < t.length(); j++)
    {
      map_t[t[j]] += 1;
    }

    for (int i = 0; i < s.length(); i++) {
        map_t[s[i]]--;

    }

    for (const auto &pair : map_t)
    {
        if (pair.second != 0)
        {
        return pair.first;
        }

    }
  return '\0';
  }
};
*/

// ASCII
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_sum = 0, t_sum = 0;
        for (char c : s) {
            s_sum += int(c);
        }
        for (char c : t) {
            t_sum += int(c);
        }
        return char(t_sum - s_sum);
    }
};
*/