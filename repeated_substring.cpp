#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    int sLength = s.length();
    for (int len = 1; len <= sLength / 2; len++)
    {
      if (sLength % len == 0)
      {
        string sub_string = s.substr(0, len);
        int subLength = sub_string.length();
        int times = sLength / subLength;

        string repeated = "";

        for (int i = 0; i < times; i++)
        {
          repeated += sub_string;
        }
        if (repeated == s)
          return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution sol;
  bool result = sol.repeatedSubstringPattern("abcabcabc");
  cout << result << endl;
}

/*
The idea behind this approach is that if a string s can be constructed by
repeating a substring, then concatenating two copies of s together
and removing the first and last character would still contain s as a substring.

Given the string "abab":

Concatenate to get "abababab".
Remove first and last characters to get "bababa".
Check if "abab" is present in "bababa" - It is. Hence, return True

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string sub = doubled.substr(1, doubled.size() - 2);
        return sub.find(s) != string::npos;
    }
};
 */