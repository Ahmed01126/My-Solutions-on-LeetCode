class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool>mp;
        for(auto i: nums){
            if(mp[i]==1)return 1;
            mp[i]=1;
        }
        return 0;
    }
};