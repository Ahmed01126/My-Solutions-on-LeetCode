class Solution {
public:
    
#define all(v)        v.rbegin(), v.rend()
//#define endl "\n"
#define f first
#define sd second
#define ll long long
const ll N = 1e6 + 50, NN = 105, mod = 1e9 + 7;

vector<int> topStudents(vector<string> &positive_feedback,
                        vector<string> &negative_feedback,
                        vector<string> &report,
                        vector<int> &student_id, int k) {
    map<string, int> mp;
    for (auto i : positive_feedback)mp[i] = 1;
    for (auto i : negative_feedback)mp[i] = 2;
    vector<pair<int, int>> ans(report.size(), {0, 0});
    for (int i = 0; i < report.size(); ++i) {
        string s = "";
        for (int j = 0; j < report[i].size(); ++j) {
            if (report[i][j] != ' ')s += report[i][j];
            else {
                // cout << s <<" ";
                if (mp[s] == 1)ans[i].first += 3, ans[i].second = -student_id[i];
                else if (mp[s] == 2)ans[i].first--, ans[i].second = -student_id[i];
                s = "";
            }
        }
        if (!s.empty()) {
            if (mp[s] == 1)ans[i].first += 3, ans[i].second = -student_id[i];
            else if (mp[s] == 2)ans[i].first--, ans[i].second = -student_id[i];
        }
    }
    sort(all(ans));
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(-ans[i].second);
    }
    return res;

}


};