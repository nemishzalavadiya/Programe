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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack<TreeNode*> st{{root}};
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->val == sum && !curr->left && !curr->right) {
                return true;
            }
            if(curr->left) {
                curr->left->val += curr->val;
                st.push(curr->left);
            
            }
            if(curr->right) {
                curr->right->val += curr->val;
                st.push(curr->right);
            }
            
        }
        return false;
    }
};