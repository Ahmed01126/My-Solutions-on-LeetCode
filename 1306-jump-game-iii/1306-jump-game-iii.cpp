class Solution {
public:
    #define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
  
#define all(v)        v.begin(), v.end()
int dp[55000];
bool goDp(vector<int>& arr, int i){
    if(i<0||i>arr.size()-1)return 0;
    if(arr[i]==0)return 1;
    if(dp[i]!=-1)return dp[i];
    dp[i]=0;
    return dp[i] = goDp(arr,i+arr[i])|| goDp(arr,i-arr[i]);
}
bool canReach(vector<int>& arr, int start) {
    memset(dp,-1,sizeof(dp));
    return goDp(arr,start);
}
};