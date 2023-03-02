class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>v;
        v.push_back(chars[0]);
        int x = 1;
        for(int i=1;i<chars.size();++i){
            if(chars[i]==v.back())++x;
            else {
                if(x==1){
                    v.push_back(chars[i]);
                    continue;
                }
                stack<char>st;
                while(x){
                    int y = x%10;
                    st.push(char(y+'0'));
                    x/=10;
                }
                while(!st.empty())v.push_back(st.top()),st.pop();
                x=1;
                v.push_back(chars[i]);
            }
        }
        if(x!=1){
            stack<char>st;
                while(x){
                    int y = x%10;
                    st.push(char(y+'0'));
                    x/=10;
                }
                while(!st.empty())v.push_back(st.top()),st.pop();
                x=1;
        }
        chars.clear();
        for(auto i : v)chars.push_back(i);
        return chars.size();
    
    }
};