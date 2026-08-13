class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> f;

        int len = 0;
        int maxlen = 0;

        int i = 0;
        int j = 0;

        while(j < n) {

            while(f[nums[j]] >= k) {
                f[nums[i]]--;
                i++;
                len--;
            }

            f[nums[j]]++;
            j++;
            len++;

            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};