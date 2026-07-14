class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;

            queue<pair<int,pair<int,int>>> q;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=1;
        q.push({1,{0,0}});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col==m-1)return dist;

            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dist+1<dis[nrow][ncol]){
                    dis[nrow][ncol]=dist+1;
                    q.push({dis[nrow][ncol],{nrow,ncol}});
                }
            }

        }
        return -1;
    }
};