
class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        int n = matrix.size();
        int m = matrix[0].size();

        if (r < 0 || c < 0 || r >= n || c >= m)
            return 0;

        if (dp[r][c] != -1)
            return dp[r][c];

        int ans = 1; 

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if (matrix[nr][nc] > matrix[r][c]) {
                ans = max(ans, 1 + dfs(nr, nc, matrix, dp));
            }
        }

        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }

        return ans;
    }
};
