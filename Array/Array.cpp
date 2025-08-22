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

vector<vector<int>> ThreeSum_brute(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp={arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                }
            }

        }
    }
    return ans;
}
vector<vector<int>> ThreeSum_better(vector<int>& arr){
    int n=arr.size();
    set<vector<int>> hashset;
    for(int i=0; i<n; i++){
        set<int> st;
        for(int j=i+1; j<n; j++){
            int rem=-arr[i]-arr[j];
            if(st.find(rem)!=st.end()){
                vector<int>temp={arr[i],arr[j], rem};
                sort(temp.begin(), temp.end());
                hashset.insert(temp);

            }
            st.insert(arr[j]);
        }
            
    }
    vector<vector<int>> ans(hashset.begin(), hashset.end());
    return ans;
}
vector<vector<int>> ThreeSum_optimal(vector<int>& arr){
    int n=arr.size();
    sort(arr.begin(), arr.end());
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        int j=i+1; int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];

            if(sum==0){
                vector<int> temp={arr[i], arr[j], arr[k]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
                j++; k--;
            }
            
            else if(sum>0) k--;
            else j++;
        }
            
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int TrappingRainWater(vector<int>& arr){
    int n=arr.size();
    int lmax=0, rmax=0, l=0, r=n-1;;
    int total=0;
    while(l<r){
        if(arr[l]<arr[r]){
            if(lmax>arr[l]){
                total+=lmax-arr[l];
            }
            else lmax=arr[l];
            l=l+1;
        }
        else{
            if(rmax>arr[r]){
                total+=rmax-arr[r];
            }
            else rmax=arr[r];
            r--;
        }
    }
    return total;
}

int main() {
    vector<int> temp={2,6,5,8,11};
    int target=14;
    bool ans=TwoSum_optimal(temp,target);

    cout<<ans;
    
    return 0;
}