class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();

        vector<pair<int,int>>brr;
        vector<int>ans;

        for(int i=0;i<n;i++){
            brr.push_back({abs(x-arr[i]),arr[i]});
        }

        sort(brr.begin(),brr.end());
        for(auto it:brr){
            if(k>0){
                ans.push_back(it.second);
                k--;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};