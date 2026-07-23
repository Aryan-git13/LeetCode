class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        stack<char>st;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(s[i]);
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else cnt++;
            }
        }
        int cnt2=0;

        if(!st.empty()){
            while(!st.empty()){
                cnt2++;
                st.pop();
            }
        }
        return cnt+cnt2;
    }
};