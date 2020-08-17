/*
Excel Sheet Column Number

Solution
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int titleToNumber(string s)
    {
        int po = s.size() - 1;
        int output = 0;
        for (int i = 0; i < s.size(); i++)
        {
            output += (s[i] - 'A' + 1) * pow(26, po--);
        }
        return output;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}