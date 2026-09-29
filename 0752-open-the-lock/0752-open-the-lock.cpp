class Solution {
public:
    char right(char c){
        return (c=='9' ? '0':c+1);
    }
    char left(char c){
        return (c=='0' ? '9':c-1);
    }

    vector<string>nextOption(string s){
        vector<string>ans;

        for(int i=0;i<4;i++){
            string copy=s;

            copy[i]=right(s[i]);
            ans.push_back(copy);

            copy[i]=left(s[i]);
            ans.push_back(copy);
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool>vis;
        queue<string>q;
        q.push("0000");
        unordered_set<string>d(deadends.begin(),deadends.end());
        vis["0000"]=true;

        int cnt=0;

        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string s=q.front();
                q.pop();

                if(s==target)return cnt;

                if(d.find(s)!=d.end())continue;

                for(auto it:nextOption(s)){
                    if(!vis[it]){
                        vis[it]=true;
                        q.push(it);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};