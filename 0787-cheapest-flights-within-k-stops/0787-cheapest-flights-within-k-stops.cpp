class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int p=flights.size();
        int m=flights[0].size();
        vector<pair<int,int>>adj[n];

        for(auto it:flights){
          adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.second.second;
            int stop=it.first;
            int node=it.second.first;

            if(stop>k)continue;

            for(auto iter: adj[node]){
                int edw=iter.second;
                int adjnode=iter.first;

                if(dist[adjnode]>dis+edw && stop<=k){
                    dist[adjnode]=edw+dis;
                    q.push({stop+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};