int dp[46];
int goDP(int n,int sum){
    if(sum==n)return 1;
    else if(sum>n)return 0;
    if(dp[n-sum]!=0)return dp[n-sum];
    return dp[n-sum] = goDP(n,sum+1)+goDP(n,sum+2);
}
int climbStairs(int n) {
    return goDP(n,0);
}