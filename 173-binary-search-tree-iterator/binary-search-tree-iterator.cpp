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
class BSTIterator {
public:
    // consider  the example 1
    // inorder - 3,7,9,15,20
    // here next() is the current ele 3 the move to 7
    // hasnext() if 7 has element next to it , i.e true
    // so we use the stack ,
    // tc- o(H) o.e the height thatswhy we aint using vector to store inorder already
    // sc-o(1)

    stack<TreeNode*>s;
    void push(TreeNode* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode* node=s.top();
        s.pop();
        if(node->right)push(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */