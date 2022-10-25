class Solution {
public:
    int minInsertions(string s) {
        
        string s2;
        int x = s.size();
        int y = s.size();
        
        for(int i=x-1;i>=0;i--) {
            s2.push_back(s[i]);
        }
        
        int t[x+1][y+1];
        for(int i=0;i<x+1;i++) 
            for(int j=0;j<y+1;j++) 
                if(i==0 || j==0)
                    t[i][j]=0;
        
        for(int i=1;i<x+1;i++) {
            for(int j=1;j<y+1;j++) {
                if(s[i-1]==s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else 
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        } 
        
        return x - t[x][y];
    }
};