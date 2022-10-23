class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int sum = amount;
        int N = coins.size();
        long long dp[N+1][sum+1];
        
        for(int i=0;i<sum+1;i++) dp[0][i]=0;
        for(int i=0;i<N+1;i++) dp[i][0]=1;
        
        for(int i=1;i<N+1;i++) {
            for(int j=1;j<sum+1;j++) {
                if(coins[i-1]<=j) 
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
};