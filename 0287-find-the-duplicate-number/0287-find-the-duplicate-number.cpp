class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool>freq(nums.size()+1,0);
        for(auto i : nums){
            if(freq[i]==1)return i;
            freq[i]=1;
        }
        return -1;
    }
};