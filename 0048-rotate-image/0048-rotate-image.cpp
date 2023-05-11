class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        for(int i=0;i<n;++i) {
            for (int ii = i; ii < n; ++ii) {
                swap(v[i][ii],v[ii][i]);
            }
        }
        for(int i=0;i<n;++i)
        reverse(v[i].begin(),v[i].end());

    }
};