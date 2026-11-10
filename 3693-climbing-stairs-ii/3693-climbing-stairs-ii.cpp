class Solution {
public:
    int x(int i,int n,vector<int>&costs,vector<int>&dp){
        if(i>=n)return 0;

        if(dp[i]!=-1)return dp[i];

        int one = INT_MAX;
        int two = INT_MAX;
        int three = INT_MAX;

        if(i+1 <= n)
            one = costs[i] + 1 + x(i+1,n,costs,dp);

        if(i+2 <= n)
            two = costs[i+1] + 4 + x(i+2,n,costs,dp);

        if(i+3 <= n)
            three = costs[i+2] + 9 + x(i+3,n,costs,dp);

        return dp[i]=min(one,min(two,three));
    }
    int climbStairs(int n, vector<int>& costs) {
        int m=costs.size();
        vector<int>dp(n+1,-1);

        return x(0,n,costs,dp);
    }
};