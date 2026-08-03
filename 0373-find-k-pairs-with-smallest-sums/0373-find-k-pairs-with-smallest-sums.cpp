class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>>ans;
        if(n==0 || m==0 || k==0 )return ans;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[0],i,0});
        }

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int sum=it[0];
            int one=it[1];
            int two=it[2];
            if(k==0)return ans;
            ans.push_back({nums1[one],nums2[two]});
            if (two+ 1 < m) {
            pq.push({nums1[one] + nums2[two + 1], one, two+ 1});
            }
            k--;
        }
        return ans;
    }
};