class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    const int N = 1e5+5;
    int freqLose[N]={},freqWin[N]={};
    vector<vector<int>>ans(2);
    for(int i=0;i<matches.size();++i){
        freqWin[matches[i][0]]++;
        freqLose[matches[i][1]]++;
    }
    int idx0=0,idx1=0;
    for(int i=0;i<N;++i){
       if(freqLose[i]==0 && freqWin[i]>0)ans[0].push_back(i);
        if(freqLose[i]==1)ans[1].push_back(i);
    }
    
    return ans;
    }
};