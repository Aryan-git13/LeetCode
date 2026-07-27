class Solution {
public:
    int f(int i,vector<vector<int>>& dp,vector<int>& coins,int amount){
        
        if(i==0){
            if(amount%coins[i]==0)return amount/coins[i];
            return 1e9;
        }

        if(dp[i][amount]!=-1)return dp[i][amount];
        int pick=1e9;
        if(coins[i]<=amount) pick=1+f(i,dp,coins,amount-coins[i]);
        int notpick=f(i-1,dp,coins,amount);

        return dp[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,dp,coins,amount);
        if(ans==1e9)return -1;
        return ans;
    }
};