class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string s="";
    for (int i = 0; ; ++i) {
            if(strs.size()==1)return strs[0];
        for (int j = 1; j < strs.size(); ++j) {
            if(i<strs[j].size()){
                if(strs[j][i]!=strs[j-1][i])return s;
            }
            else return s;
        }
        s+=strs[0][i];
    }
    return s;
}
};