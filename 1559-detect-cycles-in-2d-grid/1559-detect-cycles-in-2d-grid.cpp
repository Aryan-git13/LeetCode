class Solution {
public:
    bool dfs(int i,int j,int p1,int p2,vector<vector<char>>&grid,vector<vector<int>>&vis,int dr[],int dc[]){
        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            
            if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size())continue;

            if(grid[nr][nc]!=grid[i][j])continue;
            if(!vis[nr][nc]){
                if(dfs(nr,nc,i,j,grid,vis,dr,dc))return true;
            }
            else if(nr!=p1 || nc!=p2)return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis,dr,dc))return true;
                }
            }
        } 
        return false;
    }
};