class Solution {
public:
    string removeStars(string s) {
        string p="";
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]!='*')st.push(s[i]);
            else st.pop();
        }
        while(!st.empty()){
            p.push_back(st.top());
            st.pop();
        }
        reverse(p.begin(),p.end());
        return p;
    }
};