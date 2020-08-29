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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        if(!root->left && !root->right) 
        return true; 
        queue <TreeNode*> q;  
        q.push(root); 
        q.push(root); 
        TreeNode* leftNode, *rightNode;
        while(!q.empty()){
            leftNode = q.front(); 
            q.pop(); 

            rightNode = q.front(); 
            q.pop(); 
            
            if(leftNode->val != rightNode->val){ 
                return false; 
            } 
            if(leftNode->left && rightNode->right){ 
                q.push(leftNode->left); 
                q.push(rightNode->right); 
            } 
            else if (leftNode->left || rightNode->right) 
                return false; 
            if(leftNode->right && rightNode->left){ 
                q.push(leftNode->right); 
                q.push(rightNode->left); 
            }  
            else if(leftNode->right || rightNode->left) 
            return false; 
            }
        return true;
    }
};