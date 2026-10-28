class Solution {
public:
    int ps(int n,vector<int>&dp){
        if(n==0)return 0;

        if(dp[n]!=-1)return dp[n];

        int ans=INT_MAX;

        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+ps(n-i*i,dp));
        }        
        return dp[n]=ans;
    }
    int numSquares(int n) {
        if(n==1 || n==4 || n==9 || n==16)return 1;

        int cnt=INT_MAX;
        vector<int>dp(n+1,-1);
        return ps(n,dp);
    }
};