int dp[46];
int goDP(int n){
    if(0==n)return 1;
    else if(0>n)return 0;
    if(dp[n]!=0)return dp[n];
    return dp[n] = goDP(n-1)+goDP(n-2);
}
int climbStairs(int n) {
    return goDP(n);
}