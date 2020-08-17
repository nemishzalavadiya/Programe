/*
Longest Palindrome

Solution
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Example 3:

Input: s = "bb"
Output: 2
 

Constraints:

1 <= s.length <= 2000
s consits of lower-case and/or upper-case English letters only.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int small[26] = {0}, big[26] = {0}, count = 0;
        bool middle = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (islower(s[i]))
            {
                small[s[i] - 'a']++;
            }
            else
            {
                big[s[i] - 'A']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (!middle)
            {
                if (small[i] % 2)
                {
                    middle = true;
                }
                else if (big[i] % 2)
                {
                    middle = true;
                }
            }
            count = count + (small[i] / 2) + (big[i] / 2);
        }
        if (middle)
        {
            return 2 * count + 1;
        }
        return 2 * count;
    }
    int longestPalindrome(string s)
    {
        int small[26] = {0}, big[26] = {0}, count = 0;
        bool middle = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (islower(s[i]))
            {
                small[s[i] - 'a']++;
            }
            else
            {
                big[s[i] - 'A']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (!middle)
            {
                if (small[i] % 2)
                {
                    middle = true;
                }
                else if (big[i] % 2)
                {
                    middle = true;
                }
            }
            count = count + (small[i] / 2) + (big[i] / 2);
        }
        if (middle)
        {
            return 2 * count + 1;
        }
        return 2 * count;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
