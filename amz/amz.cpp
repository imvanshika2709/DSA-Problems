#include <bits/stdc++.h>
using namespace std;

//largest rectangle in histogram
// next greater element
//sliding window maximum

// longest subarray with zero sum

int LongestSubarrayWithZeroSum(vector<int>& arr){
    // 3, 0, -1, -2, 3, 0, -2

    unordered_map<int,int> mpp;
    int n=arr.size();
    int sum=0; int maxlen=0;

    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==0) maxlen=i+1;
        if(mpp.find(sum)!=mpp.end()){
            int len=i-mpp[sum];
            maxlen=max(len, maxlen);
        }
        if(mpp.find(sum)==mpp.end()) mpp[sum]=i;
    }
    return maxlen;
}

int main() {
    vector<int> temp={1, 2, 3, 4, 5, 0, 0, -1, 1};
    int ans=LongestSubarrayWithZeroSum(temp);
    cout<<ans;
    
    return 0;
}