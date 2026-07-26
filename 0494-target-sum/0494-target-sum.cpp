class Solution {
public:
    const int mod=1e9+7;
    int f(int i,vector<int>& nums,vector<vector<int>>&dp,int target){
        if(i==0){
            if(target==0 && nums[i]==0)return 2;
            if(target==0 || nums[i]==target)return 1;

            return 0;
        }

        if(dp[i][target]!=1e9)return dp[i][target];

        int notpick=f(i-1,nums,dp,target);
        int pick=0;
        if(target-nums[i]>=0)
         pick=f(i-1,nums,dp,target-nums[i]);

        return dp[i][target]=(pick+notpick)%mod;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)sum+=nums[i];

        int k=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,1e9));
        if((abs(target)>sum) || (sum-target)%2==1)return 0;

        return f(n-1,nums,dp,k);
    }
};