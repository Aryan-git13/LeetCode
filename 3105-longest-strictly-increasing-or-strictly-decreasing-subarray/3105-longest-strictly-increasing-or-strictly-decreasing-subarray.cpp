class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1=1;
        int cnt2=1;
        int ans1=1;
        int ans2=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){cnt1++;
            ans1=max(ans1,cnt1);}
            else cnt1=1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){cnt2++;
            ans2=max(ans2,cnt2);
            }
            else cnt2=1;
        }
        return max(ans1,ans2);
    }
};