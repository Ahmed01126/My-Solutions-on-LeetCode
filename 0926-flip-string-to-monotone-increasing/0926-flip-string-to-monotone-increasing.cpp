class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt0=count(s.begin(),s.end(),'0'),mn=1e9,cnt=0;
        for(int i = 0; i < s.size();++i ){
            mn=min(mn,cnt0+cnt);
            if(s[i]=='1')++cnt;
            else --cnt0;
            mn=min(mn,cnt0+cnt);
            
        }
        return mn;
    }
};