class Solution(object):
    def f(self,i,j,s,p,dp):
        if i<0 or j<0:
            return 0

        if dp[i][j]!=-1:
            return dp[i][j]

        if(s[i]==p[j]):
            dp[i][j]=1+self.f(i-1,j-1,s,p,dp)

        else:
            dp[i][j]=max(self.f(i-1,j,s,p,dp),self.f(i,j-1,s,p,dp))
        return dp[i][j]
    def longestPalindromeSubseq(self, s):
        n=len(s)
        p=s[::-1]

        dp = [[-1] * n for _ in range(n)]

        return self.f(n-1,n-1,s,p,dp)
        