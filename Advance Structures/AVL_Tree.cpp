/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int height(node *root) {
       if(root == nullptr)
           return -1;
       else 
           return root->ht;
   }
int setH(node* root) {
       if(root == nullptr) {
           return -1;
       } 
       else {
           return 1 + max(height(root->left), height(root->right));
       }
}


node* rightRotation(node* root) {
       node* newRoot = root->left;
       root->left = newRoot->right;
       newRoot->right = root;
       root->ht = setH(root);
       newRoot->ht = setH(newRoot);
       return newRoot;
   }
node* leftRotation(node* root) {
       node* newRoot = root->right;
       root->right = newRoot->left;
       newRoot->left = root;
       root->ht = setH(root);
       newRoot->ht = setH(newRoot);
       return newRoot;
   }
node * insert(node *root,int val)
{
	if(!root){
        root = new node();
        root->val = val;
        root->ht = setH(root);
        return root;
    }
    if(val<=root->val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    int balance = height(root->left) - height(root->right);
    if(balance > 1) {
       if(height(root->left->left) >= height(root->left->right)) {
           root = rightRotation(root);
       }
       else {
           root->left = leftRotation(root->left);
           root = rightRotation(root);
       }
    }
   else if(balance < -1) {
       if(height(root->right->right) >= height(root->right->left)) {
           root = leftRotation(root);
       }
       else {
           root->right = rightRotation(root->right);
           root = leftRotation(root);
       }
   }
   else {
       root->ht = setH(root);
   }
       return root;
    
}