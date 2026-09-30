class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int cnt=INT_MIN;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dis(n,vector<int>(m,0));

        int c1=0;
        int c0=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)c1++;
                else c0++;
            }
        }

        if(c1==n*m || c0==n*m)return -1;

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)q.push({i,j});
            }
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int r=q.front().first;
                int c=q.front().second;

                q.pop();
                
                for(int i=0;i<4;i++){
                    int nrow=r+drow[i];
                    int ncol=c+dcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                        if(grid[nrow][ncol]==0){
                        dis[nrow][ncol]=dis[r][c]+1;
                        grid[nrow][ncol]=1;
                        q.push({nrow,ncol});
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dis[i][j]>cnt)cnt=dis[i][j];
            }
        }
        return cnt;
    }
};