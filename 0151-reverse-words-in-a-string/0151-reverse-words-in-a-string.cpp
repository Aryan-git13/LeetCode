class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        vector<string>st;
        int j=0;

        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(i>j)st.push_back(s.substr(j,i-j));
                int k=i;
                while( k<n && s[k]==' ')k++;
                j=k;
                i=k-1;
            }
        }
        if (j < n)
            st.push_back(s.substr(j));

    string p="";
    
    for(int i=st.size()-1;i>=0;i--){
        if(i==0)p.append(st[i]);
        else{
        p.append(st[i]);
        p.push_back(' ');
        }
    }
    return p;

    }
};