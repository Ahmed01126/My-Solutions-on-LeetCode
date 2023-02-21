class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        for(int i=1;i<v.size();i+=2){
            if(v[i]!=v[i-1]){
                return v[i-1];
            }
        }
        return v.back();
    }
};