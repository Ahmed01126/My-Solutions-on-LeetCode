bool makeEqual(char** words, int wordsSize) {
        int freq[26]={0};
        for(int i=0;i<wordsSize;i++){
            for(int ii=0;words[i][ii]!='\0';ii++){
                freq[words[i][ii]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]%wordsSize!=0)return 0;
        }
        return 1;
}