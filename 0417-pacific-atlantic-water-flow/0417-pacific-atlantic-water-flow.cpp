class Solution {
public:
    void pbfs(vector<vector<int>>&vis,int n,int m,vector<vector<int>>&heights){
        queue<pair<int,int>>q;
        for(int j=0;j<m;j++){
            q.push({0,j});
            vis[0][j]=1;
        }
        for(int i=0;i<n;i++){
            q.push({i,0});
            vis[i][0]=1;
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0 || nr>=n || nc<0 || nc>=m)continue;

                if(!vis[nr][nc] && heights[r][c]<=heights[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }  
    }
    void abfs(vector<vector<int>>&vis1,int n,int m,vector<vector<int>>&heights){
        queue<pair<int,int>>q;
        for(int j=0;j<m;j++){
            q.push({n-1,j});
            vis1[n-1][j]=1;
        }
        for(int i=0;i<n;i++){
            q.push({i,m-1});
            vis1[i][m-1]=1;
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0 || nr>=n || nc<0 || nc>=m)continue;

                if(!vis1[nr][nc] && heights[r][c]<=heights[nr][nc]){
                    q.push({nr,nc});
                    vis1[nr][nc]=1;
                }
            }
        }  
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>vis1(n,vector<int>(m,0));

        vector<vector<int>>ans;

        pbfs(vis,n,m,heights);
        abfs(vis1,n,m,heights);

        for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(vis[i][j] && vis1[i][j]) {
                ans.push_back({i,j});
            }
        }
    }
    return ans;
    }
};