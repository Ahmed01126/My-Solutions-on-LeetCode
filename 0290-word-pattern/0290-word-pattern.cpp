class Solution {
public:
   bool wordPattern(string pattern, string s) {
    map<char, string> mp;
    map<string, char> mpp;
    string ss = "";
    int j = 0;
    vector<string> v;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ')ss += s[i];
        else mp[pattern[j++]] = "", v.push_back(ss), mpp[ss] = ' ', ss = "";
    }
    if (!ss.empty())mp[pattern[j++]] = "", v.push_back(ss), mpp[ss] = ' ', ss = "";
       if(v.size()!=pattern.size())return 0;
    for (int i = 0; i < pattern.size(); ++i) {
        if (mp[pattern[i]] != "" && mp[pattern[i]] != v[i])return 0;
        else mp[pattern[i]] = v[i];
        if (mpp[v[i]] != ' ' && mpp[v[i]] != pattern[i])return 0;
        else mpp[v[i]] = pattern[i];
    }
    return true;
}
};