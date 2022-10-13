class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int>vec(10);
        for(int i=0;i<num.size();i++)
        {
            vec[num[i]-'0']++;
        }
        string front="",back="";
        for(int i=9;i>=0;i--)
        {
            if(i==0 && front.empty())continue;
            while(vec[i]>1)
            {
                front+=to_string(i);
                back+=to_string(i);
                vec[i]-=2;
            }
        }
        for(int i=9;i>=0;i--)
        {
            if(vec[i])
            {
                front+=to_string(i);
                break;
            }
        }
        reverse(back.begin(),back.end());
        return front+back;
    
    }
};