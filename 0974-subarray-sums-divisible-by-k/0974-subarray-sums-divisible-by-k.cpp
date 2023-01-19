class Solution {
public:
 int subarraysDivByK(vector<int> &nums, int k) {
    int sum = 0, n = nums.size();
   vector<int>mp(k,0);
    int cnt = 0;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        cnt += mp[(sum % k + k)%k];
        mp[(sum % k + k)%k]++;
    }
    return cnt;
}
};