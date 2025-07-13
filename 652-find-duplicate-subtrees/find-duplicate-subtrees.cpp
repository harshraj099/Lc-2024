class Solution {
public:
    unordered_map<string, int> subtreeCount;
    vector<TreeNode*> result;

    string serialize(TreeNode* root) {
        if (!root) return "#";  // null node

        // Post-order: left, right, root
        string left = serialize(root->left);
        string right = serialize(root->right);
        string curr = to_string(root->val) + "," + left + "," + right;

        // Count how many times this serialization has occurred
        subtreeCount[curr]++;

        if (subtreeCount[curr] == 2) {
            result.push_back(root);  // Only add once
        }

        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};
