class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0;
        vector<string>ans;

        while(i<nums.size()){
            int j=i;
            while(j+1<nums.size() && nums[j+1]==nums[j]+1)j++;

           if (i == j) {
                ans.push_back(to_string(nums[i]));
            }

            else {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i=j+1;
        }
        return ans;
    }
};