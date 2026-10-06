class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int limit=x+a+b+2000;
        unordered_set<int>s(forbidden.begin(),forbidden.end());
        queue<pair<int,int>>q;
        q.push({0,0});
        int cnt=0;
        while(!q.empty()){
           int sz=q.size();
           while(sz--){
            int n=q.front().first;
            int flag=q.front().second;
            q.pop();
            if(n==x)return cnt;
            int back=n-b;
            if(flag==0 && back>=0 && s.find(back)==s.end() ){
                s.insert(back);
                q.push({back,1});
            }
            if(n+a<=6000 && s.find(n+a)==s.end()){
                    q.push({n+a,0});
                    s.insert(n+a);
                }
           }
           cnt++;
        }

        return -1;
    }
};