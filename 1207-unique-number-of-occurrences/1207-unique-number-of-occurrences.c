bool uniqueOccurrences(int* arr, int arrSize) {
    int freq[2001]={},freqFreq[1001]={};
    for(int i=0;i<arrSize;++i){
        if(arr[i]<0)freq[2000+arr[i]]++;
        else freq[arr[i]]++;
    }
    for(int i=0;i<2001;++i){
        if(freq[i]>0)freqFreq[freq[i]]++;
        if(freqFreq[freq[i]]>1)return 0;
    }
    return 1;
    
}