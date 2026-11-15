class Solution {
public:
    void f(int n,int i,int target,int sum,vector<int>& ds,vector<vector<int>>&ans,vector<int>& candidates){
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        if(i==n)return;

        ds.push_back(candidates[i]);
        if(sum+candidates[i]<=target)f(n,i,target,sum+candidates[i],ds,ans,candidates);
        ds.pop_back();
        f(n,i+1,target,sum,ds,ans,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>ds;
        vector<vector<int>>ans;
        f(n,0,target,0,ds,ans,candidates);
        return ans;
    }
};