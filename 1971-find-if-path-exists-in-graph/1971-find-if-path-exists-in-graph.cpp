class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(source==destination)return true;

        queue<int>q;
        vector<int>vis(n,0);
        vis[source]=1;
        q.push(source);
        while(!q.empty()){
            int n=q.front();
            q.pop();

            for(auto it:adj[n]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);

                    if(it==destination)return true;
                }
            }
        }
        return false;
    }
};