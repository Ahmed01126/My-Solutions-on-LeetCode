class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // map<int,bool>mp;
        // for(auto i: nums){
        //     if(mp[i]==1)return 1;
        //     mp[i]=1;
        // }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1])return 1;
        }
        return 0;
    }
};