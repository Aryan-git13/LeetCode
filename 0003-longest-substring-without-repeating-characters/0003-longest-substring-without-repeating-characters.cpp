class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mpp;
        int i=0;
        int j=0;
        int maxlen=0;

        while(j<n){
            mpp[s[j]]++;

            while(mpp[s[j]]>1){
                mpp[s[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};