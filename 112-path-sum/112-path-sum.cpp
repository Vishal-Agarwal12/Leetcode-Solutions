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
    int fg=0;
    void pathsUntil(TreeNode* root,int curr_sum,int targetSum) {
        if(root == NULL) return;
     
        curr_sum=curr_sum+ root->val;
        if(!root->left && !root->right) {
            if(curr_sum==targetSum)
                fg=1;
                
        }
        pathsUntil(root->left,curr_sum, targetSum);
        pathsUntil(root->right, curr_sum, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr_sum=0;
        pathsUntil(root,curr_sum,targetSum);
        if(fg==1) return true;
        else return false;
    }
};