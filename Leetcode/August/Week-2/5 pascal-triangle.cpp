/*
Pascal's Triangle II

Solution
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 40
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        vector<vector<int>> ans;
        ans.push_back({1, 1});
        rowIndex--;
        int count = 0;
        while (rowIndex > 0)
        {
            vector<int> calc;
            count++;
            calc.push_back(1);
            int i = 1;
            while (i <= count)
            {
                calc.push_back(ans[count - 1][i - 1] + ans[count - 1][i]);
                i++;
            }
            calc.push_back(1);
            rowIndex--;
            ans.push_back(calc);
        }
        return ans[count];
    }
};
int main(int argc, char *argv[])
{

    return 0;
}