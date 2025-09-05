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
bool checkpalin(int low, int high, string &str){
    while(low<high){
        if(str[low]!=str[high]) return false;
        low++;
        high--;
    }
    return true;
}
string longestpalinsubstr_brute(string& str){
    int n=str.length(); int maxlen=1;
    int start=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(checkpalin(i,j,str)==true){
                if(j-i+1>maxlen){
                    start=i;
                    maxlen=j-i+1;
                }
            }
        }
    }
    return str.substr(start, maxlen);
}
int expandaroundcentre(string &str, int left, int right){
    int n=str.length();

    while(left>=0 && right<n && str[left]==str[right]){
        left--;
        right++;
    }
    return right-left-1;
}
string longestpalinsubstr_better(string& str){
    int n=str.length();
    int len1=0; int len2=0; int len=0; 
    int start=0; int end=0;
    for(int i=0; i<n; i++){
        len1=expandaroundcentre(str, i, i);
        len2=expandaroundcentre(str, i, i+1);
        len=max(len1, len2);

        if(len>(end-start+1)){
            start=i-(len-1)/2;
            end= i+len/2;
        }
    }
    return str.substr(start,end-start+1); 
}
int LongestRepeatingCharacterReplacement(string &str, int k){
    int n=str.length();
    int maxf=1;
    int changes=0; int maxlen=1;


    for(int i=0; i<n; i++){
        int hash[26]={0};
        for(int j=i; j<n; j++){
            hash[str[j]-'A']++;
        
            maxf=max(maxf, hash[str[i]-'A']);
            changes=(j-i+1)- maxf;

            if(changes<=k) maxlen=max(maxlen, j-i+1);
            else break;
        }
    }
    return maxlen;
}
int SubstringWithAllThreeCharac(string& str){
    int pos[3]={-1,-1,-1};
    int ans=0;
    int lastseen=-1;


    for(int i=0; i<str.length(); i++){
        pos[str[i]-'a']=i;

        if (pos[0] != -1 && pos[1] != -1 && pos[2] != -1) {
            lastseen=min(pos[0], pos[1]);
            lastseen=min(lastseen, pos[2]);
            ans+=lastseen+1;
        }
    }
    return ans;
}
string ReverseWordsInString(string& str){
    // The pen is here --> here is pen The
    int n=str.length();
    reverse(str.begin(), str.end());
    
    string ans="";
    for(int i=0; i<n; i++){
        string word="";
        while(i<n && str[i]!=' '){
            word+=str[i];
            i++;
        }
        reverse(word.begin(), word.end());

        if (!word.empty()) {  
            if (ans.empty()) {
                ans += word;
            } else {
                ans += " " + word;
            }
        }
    }
    return ans;
}

// Balanced parantheses

bool isBalancedParentheses(string str) {
	stack<char>st;
	
	for(auto it: str){
		if(it=='(' || it=='{' || it=='[')	{
			st.push(it);
		}
		else{
			if(st.empty()) return false;
			char ch=st.top();
			st.pop();
			
			if((ch=='{' && it=='}') || (ch=='(' && it==')') || (ch=='[' && it==']')) continue;
			
			else{
				return false;
			}
		}
	}
	return st.empty();

}
// print all subsequences
void printsub( int i,string &str, string& ans ){
    if(i==str.length()){
        cout<<ans<<endl;
        return;
    }
    //pick
    ans+=str[i];
    printsub(i+1,str,ans);
    ans.pop_back();

    printsub(i+1, str, ans);
}
int main() {
    string str1="abc";
    string ans1="";
    cout<<endl;
    printsub(0,str1, ans1);
    cout<<ans1;
    
    return 0;
}