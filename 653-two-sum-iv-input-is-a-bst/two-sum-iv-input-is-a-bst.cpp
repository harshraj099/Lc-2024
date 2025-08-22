class Solution {
    unordered_set<int> set;

public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (set.count(k - root->val)) return true;
        set.insert(root->val);
        int l=0,r=0;
        if(findTarget(root->left, k))return l=1;;
        if(findTarget(root->right, k))return r=1;;
        return l|r;
    }
};