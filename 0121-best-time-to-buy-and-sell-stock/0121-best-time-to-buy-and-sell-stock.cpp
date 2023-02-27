class Solution {
public:
    int maxProfit(vector<int>& v) {
        priority_queue<int>pq;
        int mx=0;
        pq.push(v.back());
        for(int i=v.size()-2;i>=0;--i){
            pq.push(v[i]);
            mx=max(mx,pq.top()-v[i]);
        }
        return mx;
    }
};