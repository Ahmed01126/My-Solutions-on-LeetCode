class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        long long ans = 0;
        long long n = nums.size(); // 2 4 6 8 10
        vector<unordered_map<long long, long long>> dp(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                dp[i][diff]++;
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
            }
        }
        return ans;
    }
};