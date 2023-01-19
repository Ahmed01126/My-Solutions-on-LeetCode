class Solution {
public:
 int subarraysDivByK(vector<int> &nums, int k) {
    int sum = 0, n = nums.size();
   // vector<int>mp(k,0);
     unordered_map<int,int>mp;
    int cnt = 0;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        int x = (sum % k + k)%k;
        if (mp[x] > 0)cnt += mp[x];
        mp[x]++;
    }
    return cnt;
}
};