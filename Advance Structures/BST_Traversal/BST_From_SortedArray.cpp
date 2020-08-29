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
    TreeNode *connect(TreeNode* root,int i,int j,vector<int>& nums){
        
        if(i==j){
            root = new TreeNode;
            root->val = nums[i];
            return root;
        }
        if(i==j-1){
                root = new TreeNode;
                root->val = nums[j];
                root->left=new TreeNode;
                root->left->val=nums[i];
                return root;
            
        }
        int mid = ceil((i+j)*1.0/2);
        root = new TreeNode;
        root->val = nums[mid];        
        root->left=connect(root->left,i,mid-1,nums);        
        root->right=connect(root->right,mid+1,j,nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        TreeNode* head;
        head = connect(head,0,nums.size()-1,nums);
        return head;
    }
};