class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
   int curSum = 0;
   unordered_map<int, int> mp;
   mp[0]++;
   int res = 0,n=nums.size();
   for (int i = 0; i < n; ++i) {
       curSum += nums[i];
       if (mp.find(curSum - k) != mp.end()) {
           res += mp[curSum - k];
       }
       mp[curSum]++;
   }
   return res;
    }
};