class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        set<int>cols,rows;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[0].size();++j){
                if(v[i][j]==0){
                    cols.insert(j);
                    rows.insert(i);
                }
                
            }
                
        }
        for(auto i : cols){
            for(int j=0;j<v.size();++j)
                v[j][i]=0;
        }
        for(auto i : rows){
            for(int j=0;j<v[0].size();++j)
                v[i][j]=0;
        }
       
        
    }
};