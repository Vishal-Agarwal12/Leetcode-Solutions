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
    int dfs(int node, unordered_map<int,vector<int>>&adj,  vector<int>&vis){
      vis[node]=1;
        int res=0;
        for(auto it:adj[node]){
            if(vis[it]==0){
                res=max(res,1+dfs(it,adj,vis));
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
       
        unordered_map<int,vector<int>>adj;
            int maxi=0;
        if(!root)return 0;  
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            auto cur=q.front();
            maxi=max(cur->val,maxi);
            q.pop();
            if(cur->left){
                adj[cur->val].push_back(cur->left->val);
                adj[cur->left->val].push_back(cur->val);
                q.push(cur->left);
            }
            if(cur->right){
                adj[cur->val].push_back(cur->right->val);
                adj[cur->right->val].push_back(cur->val);
                q.push(cur->right);
            }
        }
        vector<int>vis(maxi+1,0);
    
        return dfs(start,adj,vis);
    }
};