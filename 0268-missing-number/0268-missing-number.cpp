class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =  *max_element(nums.begin(),nums.end());
        vector<bool>v(n+1);
        for(auto i : nums){
            v[i]=1;
        }
        for(int i = 0;i<v.size();++i){
            if(v[i]==0)return i;
        }
        return n+1;
        
    }
};