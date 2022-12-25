class Solution {
public:

#define all(v)        v.begin(), v.end()
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    nums.push_back(1e9);
    vector<int>ans;
    sort(all(nums));
    for (int i = 1; i < nums.size(); ++i) {
        nums[i]+=nums[i-1];
    }
    for (int i = 0; i < queries.size(); ++i) {
        int x = upper_bound(all(nums),queries[i])-nums.begin()-1;
        ans.push_back(x+1);
    }
    return ans;
}
};