bool halvesAreAlike(char* s) {
    int arr[27]={ };
    int n=0;
    for(int i=0;s[i]!='\0';++i)s[i] = tolower(s[i]),++n;
    if(n%2!=0)return 0;
    for(int i=0;i<n/2;++i)arr[s[i]-'a']++;
    int sum = arr['a'-'a']+arr['e'-'a']+arr['i'-'a']+arr['o'-'a']+arr['u'-'a'];
    for(int i=n/2;i<n;++i)arr[s[i]-'a']++;
    int sum1 =(arr['a'-'a']+arr['e'-'a']+arr['i'-'a']+arr['o'-'a']+arr['u'-'a'])-sum;
    if(sum==sum1)return 1;
    return 0;
}