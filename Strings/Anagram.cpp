#include <bits/stdc++.h>
using namespace std;

bool anagram(string &str1, string &str2){
    unordered_map<int,int> mpp;

    if(str1.length()!= str2.length()) return false;
    for(auto it: str1){
        mpp[it]++;
    }

    for(auto it: str2){
        mpp[it]--;
    }

    for(auto it: mpp){
        if(it.second!=0) return false;
    }
    return true;
}


int main() {
    string str1="listen";
    string str2="listse";

    bool ans=anagram(str1, str2);
    cout<<ans;
    
    return 0;
}