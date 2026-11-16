class Solution {
public:
    string digitSum(string s, int k) {
      while(s.length()>k){
        string p="";
        int j=0;
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(j==k){
                p+=to_string(sum);
                sum=0;
                j=0;
            }
            sum+=s[i]-'0';
            j++;
        }
        if(j>0)p+=to_string(sum);
        s=p;
      }
      return s;
    }
};