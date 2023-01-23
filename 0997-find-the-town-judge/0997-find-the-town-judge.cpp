class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    if(trust.empty() && n==1)return 1;
    vector<int>v(n+1,n-1);
    int ans=1;
    for (int i = 0; i < trust.size(); ++i) {
        v[trust[i][1]]--;
        v[trust[i][0]]=-1;
        if(v[trust[i][1]]==0)ans= trust[i][1];

    }
    if(v[ans]==0)return ans;
    return -1;
}
};