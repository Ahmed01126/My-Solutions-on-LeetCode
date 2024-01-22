class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v;
        map<int,int>mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
            if(mp[nums[i]]==2)v.push_back(nums[i]);
        }
        for(int i=1;i<=nums.size();++i){
            if(mp[i]==0)v.push_back(i);
        }
        return v;
    }
};