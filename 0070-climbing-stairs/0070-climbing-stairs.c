int dp[50];
int goDP(int n,int sum){
    if(sum==n)return 1;
    else if(sum>n)return 0;
    if(dp[n-sum]!=0)return dp[n-sum];
    int take1 = goDP(n,sum+1);
    int take2 = goDP(n,sum+2);
    return dp[n-sum] = take1+take2;
}
int climbStairs(int n) {
    return goDP(n,0);
}