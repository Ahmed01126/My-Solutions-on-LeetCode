int minSteps(char* s, char* t) {
    int freq[27]={};
    for(int i=0;s[i]!='\0';++i){
        freq[s[i]-'a']++;
    }
    for(int i=0;t[i]!='\0';++i){
        freq[t[i]-'a']--;
    }
    int sum=0;
    for(int i=0;i<27;++i){
        if(freq[i]>0)sum+=freq[i];
    }
    return sum;
}