class Solution {
public:
    bool valid(string s){
    string x="";
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='.'){
            if(x.empty())return 0;
            if(x.size()>1&& x[0]=='0')return 0;
            long long a = stoll(x);
            if(a>255)return 0;
            x="";
        }
        else x+=s[i];
    }
    if(x.empty())return 0;
    if(x.size()>1&& x[0]=='0')return 0;
    long long a = stoll(x);
    if(a>255)return 0;
    return 1;
}
vector<string> restoreIpAddresses(string s) {
    vector<string> v;
    if (s.size() > 12 || s.size() < 4)return v;
    string x = "";
    for (int i = 0; i < s.size(); ++i) {
        x += s[i];
        if (i < 3)x += '.';
    }
    int n = x.size();
    set<string>st;
    for (int i = 0; i < n -1; ++i) {
        string b = x;
        for (int j = 2; j < n - 1; ++j) {
            string a = x;
            // if(i>=j)continue;
            for (int k = 4; k < n - 1; ++k) {
                if(x[k]!='.')continue;
                if(valid(x)==1)st.insert(x);
                // cout << x <<" ";
                swap(x[k],x[k+1]);
            }
            // cout << endl;
            x=a;
            if(x[j]=='.')swap(x[j],x[j+1]);
        }
        // cout <<endl;
        x=b;
        if(x[i]=='.')swap(x[i],x[i+1]);
    }
    // cout <<endl;
    return vector(st.begin(),st.end());
}
};