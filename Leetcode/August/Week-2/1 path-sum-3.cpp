/*
Path Sum III
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void check(TreeNode *root, int sum, int &count)
    {
        //cout<<"checking at "<<root->val<<"  for value sum = "<<sum<<endl;
        if (root->val == sum)
        {
            count++;
        }
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            check(root->left, sum - root->val, count);
        }
        if (root->right)
        {
            check(root->right, sum - root->val, count);
        }
    }
    int ans = 0;
    int pathSum(TreeNode *root, int sum)
    {

        if (!root)
            return 0;
        //cout<<"Main func running for root = "<<root->val<<"  for sum max = "<<sum<<endl;
        if (root->val == sum)
            ans++;
        if (root->left)
        {
            int count = 0;
            check(root->left, sum - root->val, count);
            ans += count;
        }
        if (root->right)
        {
            int count = 0;
            check(root->right, sum - root->val, count);
            ans += count;
        }
        //cout<<"got ans at position root ="<<root->val<<" ans = "<<ans<<endl;
        if (root->left)
        {
            pathSum(root->left, sum);
        }
        if (root->right)
        {
            pathSum(root->right, sum);
        }

        return ans;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}