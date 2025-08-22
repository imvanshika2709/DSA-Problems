#include <bits/stdc++.h>
using namespace std;

bool TwoSum_brute(vector<int>& arr, int target){
    // {2,6,5,8,11}
    int n=arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target) return true;
        }
    }
    return false;
}
bool TwoSum_better(vector<int>& arr, int target){
    int n=arr.size();
    unordered_map<int,int> mpp;
    for(int i=0; i<n; i++){
        int rem=target-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            return true;
        }
        mpp[arr[i]]=i;
    }
    return false;
}
bool TwoSum_optimal(vector<int>& arr,int target){
    int n=arr.size();
    int i=0; int j=n-1;
    sort(arr.begin(), arr.end());
    while(i<j){
        int sum=arr[i]+arr[j];

        if(sum==target) return true;
        else if(sum>target) j--;
        else i++;
    }
    return false;
}

int main() {
    vector<int> temp={2,6,5,8,11};
    int target=14;
    bool ans=TwoSum_optimal(temp,target);

    cout<<ans;
    
    return 0;
}