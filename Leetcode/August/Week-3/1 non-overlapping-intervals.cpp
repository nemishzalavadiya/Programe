/*
Non-overlapping Intervals

Solution
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[1] < b[1])
        {
            return true;
        }
        else if (a[1] == b[1] && a[1] < b[1])
        {
            return true;
        }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        int res = intervals[0][1];

        int n = intervals.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < res)
            {
                ans++;
            }
            else
            {
                res = intervals[i][1];
            }
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}