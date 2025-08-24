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
int findduplicates_brute(vector<int>&arr){
    // {1,3,4,2,2} --> 1,2,2,3,4
    // O(n logn +n)
    int n=arr.size();
    sort(arr.begin(), arr.end());

    for(int i=1; i<n; i++){
        if(arr[i]==arr[i-1]) return arr[i];

    }
    return 0;

}
int findduplicates_optimal(vector<int>& arr){
    int n=arr.size();
    int freq[n-1]={0};

    for(int i=0; i<n; i++){
        if(freq[arr[i]]==0) freq[arr[i]]+=1;
        else return arr[i];
    }
    return 0;
}
// Best Time to Buy and Sell Stock

int BuyAndSellStock_brute(vector<int>& arr){
    // [7,1,5,3,6,4]
    int n=arr.size();
    int maxpro=0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int pro=arr[j]-arr[i];
            maxpro=max(pro, maxpro);
        }
    }
    return maxpro;

}
int BuyAndSellStock_optimal(vector<int>& arr){
    int maxpro=0;
    int n=arr.size();
    for(int i=0; i<n; i++){
        int buy=min(buy, arr[i]);
        int pro=arr[i]-buy;
        maxpro=max(maxpro, pro);

    }
    return maxpro;
}
 // Search in Rotated Sorted Array

 int SearchinRotatedArr(vector<int>& arr, int k){
    int n=arr.size();
    int low=0; int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==k) return mid;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && arr[mid]>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=k && arr[high]>=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
 }
 vector<vector<int>> SetMatrixZeros_better(vector<vector<int>> &arr, int n, int m){
    int row[n]={0};
    int col[m]={0};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(row[i]==1 || col[j]==1) arr[i][j]=0;
        }
    }
    return arr;
 }
 vector<vector<int>> SetMatrixZeros_optimal(vector<vector<int>>& arr, int n, int m){
    int col0=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j!=0){
                    arr[0][j]=0;
                }
                else col0=0;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j]!=0){
                if(arr[i][0]==0 || arr[0][j]==0) arr[i][j]=0;
            }
        }
    }

    if(arr[0][0]==0){
        for(int j=0; j<m; j++){
            arr[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0; i<n; i++){
            arr[i][0]=0;
        }
    }
    return arr;
}
int LongestConsecSeq(vector<int>& arr){
    set<int> st;
    int n=arr.size(); int maxlen=1;

    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1)==st.end()){
            int x=it;
            int count=1;

            while(st.find(x+1)!=st.end()){
                count++;
                x=x+1;
            }
            maxlen=max(count, maxlen);
        }
    }
    return maxlen;
}
int main() {
    vector<int> temp={100,1,103,101,3,102,9,6};
    int ans=LongestConsecSeq(temp);
    cout<<ans;
    
    return 0;
}