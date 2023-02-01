class Solution {
public:
    bool check(string x, string s){
    int idx=0;
    for (int i = 0; i < s.size(); ++i) {
        if(x[idx++%x.size()]!=s[i])return false;
    }
    return idx%x.size()==0;
}
string gcdOfStrings(string str1, string str2) {
    for (int i = str1.size(); i >0 ; --i) {
        if(str1.size()%i!=0)continue;
        string x = str1.substr(0,i);
        // cout << x<<" "<< str1 <<" "<< check(x,str1) << check(x,str2)<<endl;
        if(check(x,str1)==1){
            if(check(x,str2)==1)return x;
        }
    }
    return "";
}
};