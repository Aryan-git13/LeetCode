class Solution {
public:
      int dfs1(int i,int j,vector<vector<int>>& grid,int area){
         int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1)return 0;
        grid[i][j]=-1;
        
       return 1+dfs1(i-1,j,grid,area) +
        dfs1(i+1,j,grid,area) +
        dfs1(i,j+1,grid,area) +
        dfs1(i,j-1,grid,area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                area=max(area,dfs1(i,j,grid,area));
                }
            }
        }
        return area;
    }
};