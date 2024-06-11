class Solution {
public:
   vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> v;
    int freq[1002] = {};
       
    sort(arr1.begin(),arr1.end());
    for (int i = 0; i < arr1.size(); ++i) {
        ++freq[arr1[i]];
    }
    for (int i = 0; i < arr2.size(); ++i) {
        while (freq[arr2[i]] > 0)freq[arr2[i]]--, v.push_back(arr2[i]);
    }
    for (int i = 0; i < arr1.size(); ++i) {
        if(freq[arr1[i]] > 0)v.push_back(arr1[i]);
    }
    return v;
}
};