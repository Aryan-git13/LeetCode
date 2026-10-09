class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    isWater[i][j]=0;
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int h=q.front().first;
                int i=q.front().second.first;
                int j=q.front().second.second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];

                    if(nr<0 || nr>=n || nc<0 || nc>=m)continue;

                    if(!vis[nr][nc]){
                        q.push({h+1,{nr,nc}});
                        vis[nr][nc]=1;
                        isWater[nr][nc]=h+1;
                    }
                }
            }
        }
        return isWater;
    }
};