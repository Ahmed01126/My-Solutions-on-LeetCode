class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n+1,1e5);
        for(int i=0;i<n;++i){
            int idx = lower_bound(LIS.begin(),LIS.end(),nums[i]) - LIS.begin();
            LIS[idx] = nums[i];
        }
        int cnt=0;
        for(int i=0;i<=n;++i){
            if(LIS[i]!=1e5)++cnt;
            else break;
        }
        return cnt;
    }
};