class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() && n==1)return 1;
    vector<int>v(n+1,n-1);
    for (int i = 0; i < trust.size(); ++i) {
        v[trust[i][1]]--;
        v[trust[i][0]]=-1;
    }
    for (int i = 0; i < trust.size(); ++i) {
        if(v[trust[i][1]]==0)return trust[i][1];
    }
    return -1;
}
};