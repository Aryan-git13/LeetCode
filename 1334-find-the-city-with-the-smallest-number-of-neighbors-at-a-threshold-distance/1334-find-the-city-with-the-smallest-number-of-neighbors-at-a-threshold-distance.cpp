class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];

        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int mini=INT_MAX;
        int ans=-1;

        for(int i=0;i<n;i++){
            vector<long long> dis(n, LLONG_MAX);  

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
            > pq;

        dis[i]=0;
        pq.push({0,i});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long dist=it.first;
            int node=it.second;

            if(dist>dis[node])continue;

            for(auto iter:adj[node]){
                int edge=iter.first;
                int wt=iter.second;

                if(dis[edge]>wt+dist){
                    dis[edge]=wt+dist;
                    pq.push({dis[edge],edge});
                }
            }
        }
        int count=0;
        for(int j=0;j<n;j++){
            if(j!=i && dis[j]<=distanceThreshold)count++;
        }
        if(count<=mini){
            mini=count;
            ans=i;
        }
        }
        return ans;
    }
};