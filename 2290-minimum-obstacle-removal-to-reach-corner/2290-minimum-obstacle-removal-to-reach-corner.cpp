class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, 
        pair<int, int>>>>q;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        vis[0][0]=1;

        q.push({0,{0,0}});
        while(!q.empty()){
                auto it=q.top();
                int t=it.first;
                int r=it.second.first;
                int c=it.second.second;

                q.pop();

                if(r==n-1 && c==m-1)return t;

                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];

                    if(nr<0 || nr>=n || nc<0 || nc>=m)continue;

                    if(!vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        q.push({t+1,{nr,nc}});
                    }
                    else if(!vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({t,{nr,nc}});
                    }
            }
        }
        return -1;
    }
};