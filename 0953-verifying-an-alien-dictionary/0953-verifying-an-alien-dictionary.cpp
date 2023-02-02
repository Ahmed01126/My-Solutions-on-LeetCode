class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
    map<char, int> mp;
    int x = 0;
    for (auto i : order)mp[i] = x++;
    for (int i = 1; i < words.size(); ++i) {
        if(words[i-1].find(words[i])!=-1 && words[i]!=words[i-1])return 0;
        x=0;
         while (x<words[i].size() &&words[i][x]==words[i-1][x])++x;
         if(x<words[i].size() && mp[words[i][x]] < mp[words[i-1][x]])return 0;
         
    }
    return 1;
}
};