class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int p=times.size();
        int m=times[0].size();

        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

            priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            > pq;
        pq.push({0,k});
        vector<int>dis(n+1,1e9);
        dis[k]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int node=it.second;

            if(dist>dis[node])continue;

            for(auto iter : adj[node]){
                int wt=iter.second;
                int edge=iter.first;

                if(dis[edge]>wt+dist){
                    dis[edge]=wt+dist;
                    pq.push({dis[edge],edge});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9)return -1;
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};