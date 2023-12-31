int maxLengthBetweenEqualCharacters(char* s) {
    int mx=-1;
    for(int i=0;s[i]!='\0';++i){
       for(int ii=i+1;s[ii]!='\0';++ii){
        if(s[i]==s[ii] ){
            if(mx <= ii-i-1)
                mx = ii-i-1;
        }
        } 
    }
    return mx;
}