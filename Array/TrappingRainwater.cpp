#include <bits/stdc++.h>
using namespace std;

int findtotal(vector<int>& arr){
    int lmax=0, rmax=0, l=0, r=0;
    int total=0;
    while(l<r){
        if(arr[l]<arr[r]){
            if(lmax>arr[l]){
                total+=lmax-arr[l];
            }
            else lmax=arr[l];
        }
        else{
            if(rmax>arr[r]){
                total+=rmax-arr[r];
            }
            else rmax=arr[r];
        }
    }
}
int main() {
    
    return 0;
}