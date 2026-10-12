class Solution {
public:
    bool bfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&vis){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        bool valid=true;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            if(grid1[x][y]==0)valid=false;

            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];

                if(nr<0 || nr>=grid1.size() || nc<0 || nc>=grid1[0].size())continue;
                if(grid2[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return valid;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    if(bfs(i,j,grid1,grid2,vis))cnt++;
                }
            }
        }
        return cnt;
    }
};