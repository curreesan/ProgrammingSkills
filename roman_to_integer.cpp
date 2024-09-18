#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    unordered_map<char, int> romanToInt = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int intValue = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
      if (i > 0 && (romanToInt[s[i]] > romanToInt[s[i - 1]]))
      {
        intValue += romanToInt[s[i]] - romanToInt[s[i - 1]];
        i--;
      }
      else
      {
        intValue += romanToInt[s[i]];
      }
    }
    return intValue;
  }
};

int main()
{
  Solution sol;
  int result = sol.romanToInt("III");
  cout << result << endl;
}

/*
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }
};
*/