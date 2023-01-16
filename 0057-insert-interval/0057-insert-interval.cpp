class Solution {
const int N = 1e5+5, NN = 105, mod = 1e9 + 7;

public:

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> v;
    vector<int> freq(N, 0);
    map<int,bool>mp;
    map<int,bool>mp1;
    int mx=0;
    for (auto i : intervals)freq[i[0]] += 1, freq[i[1] + 1] += -1,mp[i[1]]=1,mp1[i[0]]=1,mx=max(mx,i[1]);
    freq[newInterval[0]] += 1, freq[newInterval[1] + 1] += -1,mp[newInterval[1]]=1,mp1[newInterval[0]]=1;
    mx=max(mx,newInterval[1]);
    for (int i = 1; i < N; ++i) {
        freq[i] += freq[i - 1];
    }
    vector<int> x(2, -1);
    for (int i = 0; i < mx+3; ++i) {
        if(mp[i]==1&&mp1[i+1]==1 && (freq[i]==1 || freq[i+1]==1)){
            if(x[0]==-1)x[0]=i;
                x[1] = i;
                v.push_back(x);
                x[0] = i+1;
                continue;
        }
        if (freq[i] == 0) {
            
            if (x[0] != -1) {
                x[1] = i-1;
                v.push_back(x);
                x[0] = -1;
                
            }
        } else {
            if (x[0] == -1)x[0] = i;
        }
    }
    return v;
}

};