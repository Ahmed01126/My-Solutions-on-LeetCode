class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
    map<int,int>mp;
    for(auto i : tasks)++mp[i];
    int ans=0;
    for(auto i : mp){
        ans+=ceil(i.second/3.0);
        if(i.second==1)return -1;
    }
    return ans;
}
};