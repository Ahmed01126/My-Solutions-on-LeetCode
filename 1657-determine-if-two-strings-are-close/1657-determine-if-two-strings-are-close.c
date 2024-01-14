#include <stdlib.h>
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

bool closeStrings(char* s1, char* s2) {
   int n = strlen(s1);
   int nn = strlen(s2);
    if(n!=nn)return 0;
    int freq1[27]={}, freq2[27]={},v1[27]={},v2[27]={};
    for(int i=0;i<n;++i){
        freq1[s1[i]-'a']++;
        freq2[s2[i]-'a']++;
    }
    int idx1=0,idx2=0;
    for(int i=0;i<27;++i){
        if(freq1[i]!=0)v1[idx1++]=freq1[i];
        if(freq2[i]!=0)v2[idx2++]=freq2[i];
        if((freq1[i]!=0 && freq2[i]==0)|| (freq1[i]==0 && freq2[i]!=0))return 0;
    }
    qsort(v1,sizeof(v1)/sizeof(*v1), sizeof(*v1), comp);
    qsort(v2,sizeof(v2)/sizeof(*v2), sizeof(*v2), comp);
    for(int i=0;i<27;++i){
        if(v1[i]!=v2[i])return 0;
    }
    return 1;
}