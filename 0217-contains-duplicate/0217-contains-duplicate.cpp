class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second>1) return 1;
        }
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;++i){
        //     if(nums[i]==nums[i+1])return 1;
        // }
        return 0;
    }
};