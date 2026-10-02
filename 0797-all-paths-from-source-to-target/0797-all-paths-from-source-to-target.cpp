class Solution {
public:

    void dfs(int node,vector<vector<int>>&ans,vector<int>&arr,vector<vector<int>>& graph){
        arr.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(arr);
            arr.pop_back();
            return;
        }
        for(auto it:graph[node]){
            dfs(it,ans,arr,graph);
        }
        arr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>arr;

        dfs(0,ans,arr,graph);

        return ans;
    }
};