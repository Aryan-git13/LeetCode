class Solution {
public:
    int passwordStrength(string s) {
        int cnt=0;
        unordered_set<char>st;

        for(char ch:s){
            if(st.count(ch))continue;
            st.insert(ch);
            if(ch>='a' && ch<='z')cnt++;
            else if(ch>='A' && ch<='Z')cnt=cnt+2;
            else if(ch>='0' && ch<='9')cnt=cnt+3;
            else cnt=cnt+5;
        }
        return cnt;
    }
};