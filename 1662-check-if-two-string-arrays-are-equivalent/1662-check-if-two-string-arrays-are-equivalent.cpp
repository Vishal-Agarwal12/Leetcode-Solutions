class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1,str2;
        for(int i=0;i<word1.size();i++) {
            for(auto x: word1[i]) {
                str1.push_back(x);
            }
        }
        for(int i=0;i<word2.size();i++) {
            for(auto y: word2[i]) {
                str2.push_back(y);
            }
        }
        
        if(str1 == str2) return true;
        else return false;
    }
};