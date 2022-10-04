class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m=mat.size(),n=mat[0].size();
        vector<int>res;
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto x:mp){
            if(x.first%2==0){
                reverse(x.second.begin(),x.second.end());
            }
            for(auto i:x.second){
                res.push_back(i);
            }
        }

        return res;
    }
};