/*
Best Time to Buy and Sell Stock III

Solution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int ans[3][prices.size()];
        for (int i = 0; i < prices.size(); i++)
        {
            ans[0][i] = 0;
        }
        ans[1][0] = 0;
        ans[2][0] = 0;

        for (int i = 1; i < 3; i++)
        {
            int maxSoFar = INT_MIN;
            for (int j = 1; j < prices.size(); j++)
            {
                maxSoFar = max(maxSoFar, ans[i - 1][j - 1] - prices[j - 1]);
                ans[i][j] = max(maxSoFar + prices[j], ans[i][j - 1]);
            }
        }
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<prices.size();j++){
        //        cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans[2][prices.size() - 1];
    }
};
int main(int argc, char *argv[])
{

    return 0;
}