class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans = 0,mn=1e9;
        for(int i=0;i<v.size();++i){
            mn=min(mn,v[i]);
            ans = max(ans,v[i]-mn);
        }
        return ans;
    }
};