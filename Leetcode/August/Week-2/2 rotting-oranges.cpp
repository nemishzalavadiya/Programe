/*
Rotting Oranges

Solution
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int timeframe = 0;
        queue<pair<int, int>> process;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    process.push({i, j});
                }
            }
        }
        while (!process.empty())
        {
            timeframe++;
            int size = process.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> temp = process.front();
                process.pop();
                if (temp.first + 1 < row)
                {
                    if (grid[temp.first + 1][temp.second] == 1)
                    {
                        grid[temp.first + 1][temp.second] = 2;
                        process.push({temp.first + 1, temp.second});
                    }
                }
                if (temp.first - 1 >= 0)
                {
                    if (grid[temp.first - 1][temp.second] == 1)
                    {
                        grid[temp.first - 1][temp.second] = 2;
                        process.push({temp.first - 1, temp.second});
                    }
                }
                if (temp.second + 1 < col)
                {
                    if (grid[temp.first][temp.second + 1] == 1)
                    {
                        grid[temp.first][temp.second + 1] = 2;
                        process.push({temp.first, temp.second + 1});
                    }
                }
                if (temp.second - 1 >= 0)
                {
                    if (grid[temp.first][temp.second - 1] == 1)
                    {
                        grid[temp.first][temp.second - 1] = 2;
                        process.push({temp.first, temp.second - 1});
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return timeframe == 0 ? 0 : timeframe - 1;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}