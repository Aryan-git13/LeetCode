class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n=startGene.length();
        unordered_set<string>vis;
        vis.insert(startGene);
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        string p="ACGT";
        
        while(!q.empty()){
            string s=q.front().first;
            int x=q.front().second;
            q.pop();

            if(s==endGene)return x;
           
            for(int i=0;i<n;i++){
                char ch=s[i];
                for(auto it:p){
                    if(ch==it)continue;

                    s[i]=it;

                    if(st.find(s)!=st.end() && vis.find(s)==vis.end()){
                        vis.insert(s);
                        q.push({s,x+1});
                    }
                }
                s[i]=ch;
            }
        }
        return -1;
    }
};