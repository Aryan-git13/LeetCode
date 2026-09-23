class Solution {
public:
    queue<pair<int,int>>q;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    void dfs(vector<vector<int>>&grid,int x,int y){
        int n=grid.size();
        int m=grid[0].size();

        if(x<0 || y<0 || x>=n || y>=m)return;

        if(grid[x][y]!=1)return;

        grid[x][y]=2;
        q.push({x,y});

        for(int i=0;i<4;i++){
            int nr=x+dr[i];
            int nc=y+dc[i];

            dfs(grid,nr,nc);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        bool flag=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }

        int distance=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nr=x+dr[i];
                    int nc=y+dc[i];
                     if(nr<0 || nc<0 || nr>=n || nc>=m)continue;
                     if(grid[nr][nc]==1)return distance;

                     if(grid[nr][nc]==0){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                     }
                }
            }
            distance++;
        }
        return -1;
    }
};