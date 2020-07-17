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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* node = root;
        while(!s.empty() || node!=NULL){            
            while(node!=NULL){
                s.push(node);
                node=node->left;
            }
            node = s.top();
            s.pop(); 
            ans.push_back(node->val);
            node=node->right;        
        }
        return ans;
    }
};