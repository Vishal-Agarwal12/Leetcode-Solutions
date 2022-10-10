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
    TreeNode* buildBST(TreeNode* &root, int element) {
        if(!root) 
            return root = new TreeNode(element);
        
        if(root->val > element) {
            root->left = buildBST(root->left, element);
        }
        else {
            root->right = buildBST(root->right, element);
        }
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(auto x: preorder) {
            buildBST(root, x);
        }
        
        return root;
    }
};