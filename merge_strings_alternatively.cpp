#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    string merged_string = "";

    int l1 = word1.length();
    int l2 = word2.length();
    int maxLength = max(l1, l2);
    int minLength = min(l1, l2);
    int variedLength = l1 - l2;

    for (int i = 0; i < minLength; i++)
    {
      merged_string += word1[i];
      merged_string += word2[i];
    }
    if (variedLength == 0)
    {
      return merged_string;
    }
    else if (variedLength < 0)
    {
      return merged_string.append(word2.substr(minLength, -variedLength));
    }
    else
    {
      return merged_string.append(word1.substr(minLength, variedLength));
    }
  }
};

int main()
{
  Solution sol;
  string result = sol.mergeAlternately("ree", "shack");
  cout << result << endl;

  return 0;
}

// 2 Pointer
/*
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";
        int i = 0, j = 0;

        while (i < m || j < n) {
            if (i < m) {
                result.push_back(word1[i++]);
            }
            if (j < n) {
                result.push_back(word2[j++]);
            }
        }

        return result;
    }
};
*/

// 1 Pointer
/*
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";

        for (int i = 0; i < max(m, n); i++) {
            if (i < m) {
                result.push_back(word1[i]);
            }
            if (i < n) {
                result.push_back(word2[i]);
            }
        }

        return result;
    }
};
 */