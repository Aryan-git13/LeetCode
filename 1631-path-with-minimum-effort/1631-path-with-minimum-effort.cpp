class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});


        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;


            if(row==n-1 && col==m-1)return diff;
            if (diff > dis[row][col])
                 continue;

            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 ){
                    int neweffort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);

                    if(neweffort<dis[nrow][ncol]){
                        dis[nrow][ncol] = neweffort;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};