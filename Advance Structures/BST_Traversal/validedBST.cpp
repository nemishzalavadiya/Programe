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
class Solution {
public:
    bool isvalid(TreeNode* root,long long min,long long max){
        if(!root) return true;
    
            return (root->val>min && root->val<max) && isvalid(root->left,min,root->val) && isvalid(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        cout<<LONG_MIN<<" "<<LONG_MAX<<endl;
        return isvalid(root,LONG_MIN,LONG_MAX);
    }
};