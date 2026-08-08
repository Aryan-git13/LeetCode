class Solution {
public:
    int f(int i,int buy,vector<int>&prices,vector<vector<int>>&dp,int k){
        if(i==prices.size() || buy==2*k)return 0;
    
        if(dp[i][buy]!=-1)return dp[i][buy];

        int profit=0;
        if(buy%2==0){
            profit=max(-prices[i]+f(i+1,buy+1,prices,dp,k),0+f(i+1,buy,prices,dp,k));
        }
        else profit=max(prices[i]+f(i+1,buy+1,prices,dp,k),0+f(i+1,buy,prices,dp,k));

        return dp[i][buy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));

        return f(0,0,prices,dp,k);
    }
};