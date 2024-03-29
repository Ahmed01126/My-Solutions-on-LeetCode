class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int product = 1;
    int cntZeros = 0;
    for (auto i: nums) {
        if (i != 0)product *= i;
        else ++cntZeros;
    }
    
    for (int i = 0; i < nums.size(); ++i) {
        if(cntZeros >= 2 )nums[i]=0;
        else if(cntZeros==1){
            if(nums[i]==0)nums[i]=product;
            else nums[i]=0;
        }
        else nums[i] = product / nums[i];
    }
    return nums;
}
};