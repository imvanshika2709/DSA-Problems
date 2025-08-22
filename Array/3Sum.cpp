#include <bits/stdc++.h>
using namespace std;

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



int main() {
    vector<int> temp={ -1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans=ThreeSum_optimal(temp);

    for(auto it: ans){
        for(auto ele: it){
            cout<<ele;
        }
        cout<<endl;
    }
    
    return 0;
}