class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>&matrix,int prev,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(r<0 || c<0 || r>=n || c>=m || matrix[r][c]<=prev)return 0;
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
            int left=dfs(r+1,c,matrix,matrix[r][c],dp);
            int right=dfs(r-1,c,matrix,matrix[r][c],dp);
            int up=dfs(r,c+1,matrix,matrix[r][c],dp);
            int down=dfs(r,c-1,matrix,matrix[r][c],dp);
        return dp[r][c]=1+max({left,right,down,up});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    cnt=dfs(i,j,matrix,-1,dp);
                    ans=max(ans,cnt);
             }
        }
        return ans;
    }
};