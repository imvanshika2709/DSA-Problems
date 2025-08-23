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
int LongestSubstringwithoutRepeating_brute(string &str){
    // “c a d b z a b c d”
    int n=str.length();
    int maxlen=1;
    for(int i=0; i<n; i++){
        int hashset[256]={0};

        for(int j=i; j<n; j++){
            if(hashset[str[j]]==1){
                break;
            }
            hashset[str[j]]=1;
            int len=j-i+1;
            maxlen=max(len, maxlen);
        }
    }
    return maxlen;

}
int LongestSubstringwithoutRepeating_optimal(string &str){
    int i=0; int n=str.length(); int maxlen=1;
    set<char>st;
    for(int j=0; j<n; j++){
        if(st.find(str[j])!=st.end()){
            while( i<j && st.find(str[j])!=st.end()){
                st.erase(str[i]);
                i++;
            }
        }
        st.insert(str[j]);
        maxlen=max(j-i+1, maxlen);
    }
    return maxlen;
}

int main() {
    string str1="cadbzabcd";
    int ans=LongestSubstringwithoutRepeating_optimal(str1);
    cout<<ans;
    
    return 0;
}