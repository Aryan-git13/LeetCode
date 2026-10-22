class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        long long ans=0;

        int s=0;
        int e=nums.size()-1;

        while(s<=e){
            ans+=nums[e]-nums[s];
            if(s==e)ans+=nums[s];
            e--;
            s++;
        }
        return ans;
    }
};