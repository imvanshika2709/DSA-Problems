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
// substring with all unique characters
int SubstringWithAllUniqueCharac(string& str, int k){
    vector<int> pos(26, -1);  

    int ans = 0;

    for (int i = 0; i < str.length(); i++) {
        pos[str[i] - 'a'] = i;  // update last seen index of this char

        // check if we have seen all k required chars
        int lastseen = INT_MAX;
        int count = 0;

        for (int j = 0; j < 26; j++) {
            if (pos[j] != -1) {
                count++;
                if (count <= k)   // only care about k chars
                    lastseen = min(lastseen, pos[j]);
            }
        }

        if (count >= k) {
            ans += (lastseen + 1);
        }
    }
    return ans;
}

int main() {
    string str1="mississippi";
    int k=4;
    int ans=SubstringWithAllUniqueCharac(str1, k);
    cout<<ans;
    
    return 0;
}