class Solution(object):
    def dfs(self, i, j,grid,area):
        n=len(grid)
        m=len(grid[0])
        if i>=n or i<0 or j>=m or j<0 or grid[i][j]!=1:
            return 0

        grid[i][j]=-1

        return (1+
        self.dfs(i+1,j,grid,area)+
        self.dfs(i-1,j,grid,area)+
        self.dfs(i,j+1,grid,area)+
        self.dfs(i,j-1,grid,area))
    def maxAreaOfIsland(self, grid):
        n=len(grid)
        m=len(grid[0])
        area=0

        for i in range(n):
            for j in range(m):
                if grid[i][j]==1 :
                    area=max(area,self.dfs(i,j,grid,area))

        return area
        