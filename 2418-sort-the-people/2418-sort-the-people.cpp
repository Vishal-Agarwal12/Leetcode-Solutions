class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int ,string, greater<int>>mp;
        for(int i=0;i<heights.size();i++) {
            mp[heights[i]]=names[i];
        }
        vector <string> ans;
        for(auto x: mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};