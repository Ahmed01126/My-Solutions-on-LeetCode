class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>freq(26,0);
        for(int i=0;i<words.size();i++){
            for(int ii=0;ii<words[i].size();ii++){
                freq[words[i][ii]-'a']++;
            }
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]%words.size()!=0)return 0;
        }
        return 1;
    }
};