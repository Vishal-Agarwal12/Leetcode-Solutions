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
    
    void pathsUntil(TreeNode* root, vector <vector<int>> &res, vector <int> curr_path) {
        if(root == NULL) return;
     
        curr_path.push_back(root->val);
        if(!root->left && !root->right) {
            res.push_back(curr_path);
        }
        pathsUntil(root->left, res, curr_path);
        pathsUntil(root->right, res, curr_path);
    }
    
    int sumNumbers(TreeNode* root) {
        vector <vector<int>> res;
        vector <int> curr_path;
        pathsUntil(root, res, curr_path);
        
        int sum=0;
        for(int i=0;i<res.size();i++) {
            string s="";
            for(auto x: res[i]) {
                s = s + to_string(x);
            }
            sum=sum+stoi(s);
        }
        
        return sum;
    }
};