/*
Detect Capital

Solution
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() == 1)
            return true;
        char first = word[0];
        if (isupper(first))
        {
            if (isupper(word[1]))
            {
                for (int i = 2; i < word.size(); i++)
                {
                    if (islower(word[i]))
                        return false;
                }
            }
            else
            {
                for (int i = 2; i < word.size(); i++)
                {
                    if (isupper(word[i]))
                        return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < word.size(); i++)
            {
                if (isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};
int main(int argc, char *argv[])
{
    /* code */
    Solution *ans = new Solution();
    cout << ans->detectCapitalUse("Nemish") << endl;
    return 0;
}
