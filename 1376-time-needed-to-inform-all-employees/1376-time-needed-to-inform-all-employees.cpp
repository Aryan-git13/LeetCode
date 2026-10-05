class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>>q;
        q.push({headID,0});
        int time=0;

        while(!q.empty()){
            int x=q.front().first;
            int t=q.front().second;
            q.pop();

            time=max(t,time);

            for(auto it:adj[x]){
                q.push({it,t+informTime[x]});
            }
        }

        return time;
    }
};