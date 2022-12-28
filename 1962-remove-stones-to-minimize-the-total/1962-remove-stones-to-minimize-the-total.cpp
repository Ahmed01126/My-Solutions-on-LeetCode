class Solution {
public:
    
#define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 5e4 + 50, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int>pq;
    for (int i = 0; i < piles.size(); ++i) {
        pq.push(piles[i]);
    }
    while (k--){
        int x= pq.top();
        pq.pop();
        if(x%2==0)x/=2;
        else x/=2,x++;
        pq.push(x);
    }
    int sum=0;
    while (!pq.empty())sum+=pq.top(),pq.pop();
    return sum;
}
};