class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<int>>&land,vector<int>&arr,vector<vector<int>>&vis){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int a=i;
        int b=j;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            a=max(x,a);
            b=max(y,b);

            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=m)continue;
                if(land[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }   
        }
        arr.push_back(a);
        arr.push_back(b);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();

        vector<vector<int>>ans;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && !vis[i][j]){
                    vector<int>arr;
                    arr.push_back(i);
                    arr.push_back(j);
                    bfs(i,j,n,m,land,arr,vis);
                    ans.push_back(arr);
                }
            }
        }
        return ans;
    }
};