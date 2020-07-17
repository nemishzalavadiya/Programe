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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        vector<int> ans;
        if (root == NULL) 
           return ans; 
        TreeNode* node ;
        s.push(root);
        while(!s.empty()){            
            node =  s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->left) 
                s.push(node->left); 
            if (node->right) 
                s.push(node->right); 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};