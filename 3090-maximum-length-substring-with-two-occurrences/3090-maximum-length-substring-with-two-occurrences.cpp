class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        unordered_map<int, int> f;

        int len = 0;
        int maxlen = 0;

        int i = 0;
        int j = 0;

        while(j < n) {

            while(f[s[j]-'a'] >= 2) {
                f[s[i]-'a']--;
                i++;
                len--;
            }

            f[s[j]-'a']++;
            j++;
            len++;

            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};