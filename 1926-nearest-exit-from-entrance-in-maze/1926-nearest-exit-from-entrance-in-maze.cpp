class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         int n=maze.size();
         int m=maze[0].size();

         vector<vector<int>>vis(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]=='+'){
                    vis[i][j]=-1;
                }
            }
         }

         queue<pair<pair<int,int>,int>>q;
         q.push({{entrance[0],entrance[1]},0});
         vis[entrance[0]][entrance[1]]=1;

         while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            q.pop();

            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};

            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && maze[nrow][ncol]=='.'){
                    q.push({{nrow,ncol},tm+1});
                    vis[nrow][ncol]=1;
                    if(nrow==0 || ncol==0 || nrow==n-1 || ncol==m-1)return tm+1;
                }
            }
         }
         return -1;
    }
};