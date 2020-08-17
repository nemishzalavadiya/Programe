/*
Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
            return 0;
        while (n != 1)
        {
            if (n % 4 != 0)
                return 0;
            n = n / 4;
        }
        return 1;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}