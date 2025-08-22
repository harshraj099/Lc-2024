class Solution {
    unordered_set<int> set;

public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (set.count(k - root->val)) return true;
        set.insert(root->val);
        if(findTarget(root->left, k))return 1;;
        if(findTarget(root->right, k))return 1;;
        return 0;
    }
};