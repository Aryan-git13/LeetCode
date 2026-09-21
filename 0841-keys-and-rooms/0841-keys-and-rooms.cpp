class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int m=rooms[0].size();

        vector<int>vis(n,0);

        queue<int>q;
        vis[0]=1;
        q.push(0);
        
        while(!q.empty()){
            int n=q.front();
            q.pop();

            for(auto it:rooms[n]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)return false;
        }
        return true;
    }
};