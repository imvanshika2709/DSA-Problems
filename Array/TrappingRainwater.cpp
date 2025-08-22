#include <bits/stdc++.h>
using namespace std;

int findtotal(vector<int>& arr){
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
    vector<int> temp={4,2,0,3,2,5};
    int ans=findtotal(temp);

    cout<<ans;
    
    return 0;
}