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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector <int>> ans;
        vector <int> res;
        if(root == NULL) return ans;
        queue <TreeNode*> q;
        stack <int> s;
        bool reverse = false;
        q.push(root);
        
        while(!q.empty()) {
            
            int count=q.size();
            for(int i=0;i<count;i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(reverse) s.push(curr->val);
                else res.push_back(curr->val);
                
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
            if(reverse) {
                while(!s.empty()) {
                    res.push_back(s.top());
                    s.pop();
                }
                ans.push_back(res);
                res.resize(0);
                reverse = !reverse;
            }
            else {
                ans.push_back(res);
                res.resize(0);
                reverse = !reverse;
            }
        }
        return ans;
    }
};