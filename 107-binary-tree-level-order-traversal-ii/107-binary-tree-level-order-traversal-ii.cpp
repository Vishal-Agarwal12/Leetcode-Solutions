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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector <int>> ans;
        vector <int> res;
        if(root == NULL) return ans;
        queue <TreeNode*> q;
        q.push(root);
        stack < vector<int> >s;
        
        while(!q.empty()) {
            
            int count=q.size();
            for(int i=0;i<count;i++) {
                TreeNode* curr = q.front();
                q.pop();
                res.push_back(curr->val);
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
            s.push(res);
            res.resize(0);
        }
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};