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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        return max(height(root->left),height(root->right))+1;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* node = root;
        queue<pair<TreeNode*,int>> Qdata;
        vector<vector<int>> Adata(height(node));
        if(root==NULL) return Adata;
        node = root;
        Qdata.push({node,0});
        while(!Qdata.empty()){
           pair<TreeNode*,int> current = Qdata.front();
            Qdata.pop();
            Adata[current.second].push_back(current.first->val);
            if(current.first->left){
                Qdata.push({current.first->left,current.second+1});
            }
            if(current.first->right){
                Qdata.push({current.first->right,current.second+1});
            }
        }
        return Adata;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        
        if(root == NULL)
        {
            return result;
        }
        
        queue<TreeNode*> que;
        
        que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            
            vector<int> temp;
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = que.front();
                que.pop();
                
                temp.push_back(curr -> val);
                
                if(curr -> left)
                {
                    que.push(curr -> left);
                }
                
                if(curr -> right)
                {
                    que.push(curr -> right);
                }
            }
            
            result.emplace_back(temp);
        }
        
        return result;
        
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            vector<int> row;

            int s=q.size();
            
            while(s>0){
                TreeNode* temp=q.front();
            q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                s--;
                row.push_back(temp->val);
            }
            ans.push_back(row);
            
        }
        return ans;
    }
};