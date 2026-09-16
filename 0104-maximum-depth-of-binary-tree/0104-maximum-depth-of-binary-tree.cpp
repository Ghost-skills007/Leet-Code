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
 int  ht(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int lefth =ht(root->left);
    int righth=ht(root->right);
    int currht= max(lefth,righth)+1;
    return currht;
 }
    int maxDepth(TreeNode* root) {
        return ht(root);
    }
};