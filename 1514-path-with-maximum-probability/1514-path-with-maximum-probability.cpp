class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>d(n,0.0);
        vector<vector<pair<int,double>>>adj(n);
        priority_queue<pair<double,int>>pq;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        pq.push({1.0,start_node});
        d[start_node]=1.0;
        while(!pq.empty()){
            double dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(node==end_node)return dis;

            for(auto it:adj[node]){
                int node1=it.first;
                double prob=it.second;

                if(dis*prob>d[node1]){
                    d[node1]=dis*prob;
                    pq.push({dis*prob,node1});
                }
            }
        }
        return 0.0;
    }
};