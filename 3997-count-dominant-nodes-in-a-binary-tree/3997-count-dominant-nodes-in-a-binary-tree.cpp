class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* node) {
        if (!node) return INT_MIN;

        int leftMax = dfs(node->left);
        int rightMax = dfs(node->right);

        int mx = max(node->val, max(leftMax, rightMax));

        if (node->val == mx)
            ans++;

        return mx;
    }

    int countDominantNodes(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};