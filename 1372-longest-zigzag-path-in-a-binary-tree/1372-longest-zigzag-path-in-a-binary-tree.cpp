/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;https://leetcode.com/subscribe/?ref=lp_pl&source=qd$0
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,char>>>q;
        int maxi=0;
        // we are not pushing root node, because we can't decide L or R for root node. So push left child and right child if there
        if(root->left){
            q.push({root->left,{1,'L'}});
        }
        if(root->right){
            q.push({root->right,{1,'R'}});
        }
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int l=q.front().second.first;
            maxi=max(maxi,l);
            char ch=q.front().second.second;
            q.pop();
            if(curr->left){
                if(ch=='L'){ //if going left and L, then restart
                    q.push({curr->left,{1,'L'}});
                }
                else{  //if goinf left and R, then increase
                    q.push({curr->left,{l+1,'L'}});
                }
            }
            if(curr->right){
                if(ch=='R'){ //if going right and R, then restart
                    q.push({curr->right,{1,'R'}});
                }
                else{ //if going right and L, then increase
                    q.push({curr->right,{l+1,'R'}});
                }
            }
        }
        return maxi;
    }
};