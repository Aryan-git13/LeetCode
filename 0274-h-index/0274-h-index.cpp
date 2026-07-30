class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        int cnt=0;
        int ans=0;

        for(int i=1;i<=n;i++){
            int x=i;
            for(int j=0;j<n;j++){
                if(citations[j]>=i)cnt++;
            }
            if(cnt>=i)ans=x;
            cnt=0;
        }
        return ans;
    }
};