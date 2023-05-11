class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<bool>freq(nums.size()+1,0);
        vector<int>v;
        for(auto i : nums){
            if(freq[i]==1)v.push_back(i);
            freq[i]=1;
        }
        return v;
    }
};