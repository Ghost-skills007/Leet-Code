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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maxSum = INT_MIN;
        int currLevel = 1;
        int resLevel = 0;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode*curr = q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                resLevel = currLevel;
            }
            currLevel++;
        }
        return resLevel;
    }
};