class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sum = amount;
        int size = coins.size();
        
        int dp[size+1][sum+1];
        
        for(int i=0;i<size+1;i++) dp[i][0]=0;
        for(int i=0;i<sum+1;i++) dp[0][i]=INT_MAX-1;
        
        // for(int i=1)
        
        for(int i=1;i<size+1;i++) {
            for(int j=1;j<sum+1;j++) {
                if(coins[i-1]<=j) {
                    dp[i][j]=min(dp[i][j-coins[i-1]] + 1 ,
                                dp[i-1][j]);
                    
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        if(dp[size][sum]==INT_MAX-1) return -1; 
        else return dp[size][sum];
    }
};